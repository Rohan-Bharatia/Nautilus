#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
//
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...
//
//                  Copyright (c) Rohan Bharatia 2025

#pragma endregion LICENSE

#ifndef _NT_CORE_IOS_WINDOW_MM_
    #define _NT_CORE_IOS_WINDOW_MM_

#import "../Window.h"

#import "../Logger.h"

@interface iOSView : UIView
@property (nonatomic, weak) Nt::Window* window;
@property (nonatomic, strong) UITextField* keyInputField;
@end

@implementation iOSView
{
    CGPoint lastPosition;
    NSMutableSet<NSString*> keyQueue;
}

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];

    if (self)
    {
        keyQueue = [NSMutableSet set];

        // Setup invisible keyboard input field
        _keyInputField = [[UITextField alloc] initWithFrame:CGRectZero];
        _keyInputField.delegate = self;
        _keyInputField.autocorrectionType = UITextAutocorrectionTypeNo;
        _keyInputField.spellCheckingType = UITextSpellCheckingTypeNo;
        _keyInputField.hidden = YES;
        [self addSubview:_keyInputField];

        // Focus it to bring up keyboard
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 100 * NSEC_PER_MSEC), dispatch_get_main_queue(), ^{
            [self.keyInputField becomeFirstResponder];
        });
    }
    return self;
}

- (BOOL)canBecomeFirstResponder
{
    return YES;
}

#pragma mark - UITextFieldDelegate

- (BOOL)textField:(UITextField*)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString*)string
{
    unichar ch  = [string characterAtIndex:0];
    int keyCode = ch;

    if (![currentlyPressedKeys containsObject:string])
    {
        // New key press
        Nt::KeyPressedEvent event(keyCode, false);
        self.window->m_eventCallback(event);
        [keyQueue addObject:string];
    }
    else
    {
        // Repeat
        Nt::KeyPressedEvent event(keyCode, true);
        self.window->m_eventCallback(event);
    }

    // Typed character event (only for printable)
    if (ch >= 32 && ch <= 126)
    {
        Nt::KeyTypedEvent event(keyCode);
        self.window->m_eventCallback(event);
    }

    return YES;
}

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    for (NSString* key in keyQueue)
    {
        Nt::KeyReleasedEvent event([key characterAtIndex:0]);
        self.window->m_eventCallback(event);
    }
    [keyQueue removeAllObjects];
}

#pragma mark - UITouchDelegate

- (void)touchesBegan:(NSSet<UITouch*>*)touches withEvent:(UIEvent*)event
{
    UITouch* touch = [touches anyObject];
    CGPoint pos    = [touch locationInView:self];

    Nt::MouseButtonPressedEvent event(0);
    self.window->m_eventCallback(event);

    lastPosition = pos;
}

- (void)touchesEnded:(NSSet<UITouch*>*)touches withEvent:(UIEvent*)event
{
    UITouch* touch = [touches anyObject];
    CGPoint pos    = [touch locationInView:self];

    Nt::MouseButtonReleasedEvent event(0);
    self.window->m_eventCallback(event);

    lastPosition = pos;
}

- (void)touchesMoved:(NSSet<UITouch*>*)touches withEvent:(UIEvent*)event
{
    UITouch* touch = [touches anyObject];
    CGPoint pos    = [touch locationInView:self];
   
    Nt::MouseMovedEvent event(pos.x, pos.y);
    self.window->m_eventCallback(event);

    lastPosition = pos;
}   

- (void)touchesHeld:(NSSet<UITouch*>*)touches withEvent:(UIEvent*)event
{
    UITouch* touch = [touches anyObject];
    CGPoint pos    = [touch locationInView:self];

    Nt::MouseScrolledEvent event(std::abs(pos.x - lastPosition.x), std::abs(pos.y - lastPosition.y));
    self.window->m_eventCallback(event);

    lastPosition = pos;
}

@end

@interface iOSWindowDelegate : NSObject<UIWindowSceneDelegate>
@property (nonatomic, assign) Nt::Window* window;
@end

@implementation iOSWindowDelegate

@implementation NTSceneDelegate
- (void)windowScene:(UIWindowScene *)windowScene
    didUpdateCoordinateSpace:(id<UICoordinateSpace>)previousCoordinateSpace
        interfaceOrientation:(UIInterfaceOrientation)previousInterfaceOrientation
                     traitCollection:(UITraitCollection *)previousTraitCollection
{
    UIWindow* window = self.window->m_handle.window;
    CGSize size      = window.bounds.size;

    WindowResizeEvent event((uint32)size.width, (uint32)size.height);
    self.window->m_eventCallback(event);
}

@end

namespace Nt
{
    bool Window::Initialize(void)
    {
	UIWindowScene* scene = NT_REINTERPRET_CAST(UIWindowScene*, [UIApplication sharedApplication].connectedScenes.anyObject);
	CGRect frame	     = CGMakeRect(m_desc.position.x, m_desc.position.y, m_desc.width, m_desc.height);

	m_handle.window = [[UIWindow alloc] initWithFrame:frame];
	
	if (!m_handle.window)
	{
	    [Logger Error:@"Failed to create window"];
	    return false;
	}

	iOSView* cview = [[iOSView alloc] initWithFrame:frame];
	cview.window   = this;
	cview.backgroundColor = [UIColor colorWithRed:m_desc.bgColor.r / 255.0f
						 green:m_desc.bgColor.g / 255.0f
						  blue:m_desc.bgColor.b / 255.0f
						 alpha:m_desc.bgColor.a];

	UIViewController* viewc = [[UIViewController alloc] init];
	viewc.view		= cview;

	window.rootViewController = viewc;
	window.windowScene	  = scene;

	m_handle.delegate = [[iOSWindowDelegate alloc] init];
	
	if (!m_handle.delegate)
	{
	    [Logger Error:@"Failed to create window delegate!"];
	    return false;
	}
	
	m_handle.delegate.window = this;
	scene.delegate           = m_handle.delegate;

	[m_handle.window makeKeyAndVisible];

	return true;
    }

    void Window::OnUpdate(void)
    {
	// UIKit handles events in event callbacks
    }

    void Window::Shutdown(void)
    {
	[m_handle.window release];
	[m_handle.delegate release];

	NT_SAFE_DELETE(m_handle.window);
	NT_SAFE_DELETE(m_handle.delegate);
    }
} // namespace Nt

#endif // _NT_CORE_IOS_WINDOW_MM_
