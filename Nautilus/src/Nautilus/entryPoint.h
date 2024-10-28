#pragma once

#ifdef NT_PLATFORM_WINDOWS
	extern Nt::Application* Nt::createApplication(void);

	int main(int argc, char** argv)
	{
		Nt::Log::init();
		NT_CORE_WARN("Initialized log");
		NT_CLIENT_INFO("Hello! a={0}", 5);

		auto app = Nt::createApplication();
		app->run();
		delete app;

		return 0;
	}
#else // NT_PLATFORM_WINDOWS
	#error Nautilus Engine only supports Windows!
#endif // NT_PLATFORM_WINDOWS