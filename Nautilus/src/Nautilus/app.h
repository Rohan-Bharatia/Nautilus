#pragma once

#ifndef _NT_APP_h_
	#define _NT_APP_h_

#include "core.h"

namespace Nt
{
	class NT_API Application
	{
	public:
		Application(void);
		virtual ~Application(void);

		void run(void);
	};

	extern Application* createApplication(void);
}

#endif // _NT_APP_h_