#ifndef _NT_APP_cpp_
	#define _NT_APP_cpp_

#include "app.h"

#include <stdio.h>

namespace Nt
{
	Application::Application(void)
	{}

	Application::~Application(void)
	{}

	void Application::run(void)
	{
		printf("Running Nautilus Application...");

		while (true);
	}
}

#endif // _NT_APP_cpp_