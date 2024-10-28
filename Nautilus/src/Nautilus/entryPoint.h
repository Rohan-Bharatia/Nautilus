#pragma once

#ifdef NT_PLATFORM_WINDOWS
	extern Nt::Application* Nt::createApplication(void);

	int main(int argc, char** argv)
	{
		auto sandbox = Nt::createApplication();
		sandbox->run();
		delete sandbox;

		return 0;
	}
#else // NT_PLATFORM_WINDOWS
	#error Nautilus Engine only supports Windows!
#endif // NT_PLATFORM_WINDOWS