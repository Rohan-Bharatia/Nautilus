#pragma once

#ifndef _NT_LOG_h_
	#define _NT_LOG_h_

#include "core.h"

#include <memory>

#include <spdlog/spdlog.h>

namespace Nt
{
	class NT_API Log
	{
	public:
		static void init(void);

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger(void);
		inline static std::shared_ptr<spdlog::logger>& getClientLogger(void);

	private:
		static std::shared_ptr<spdlog::logger> m_coreLogger;
		static std::shared_ptr<spdlog::logger> m_clientLogger;
	};
} // namespace Nt

// Core log macros
#define NT_CORE_ERROR(...) ::Nt::Log::getCoreLogger()->error(__VA_ARGS__)
#define NT_CORE_WARN(...)  ::Nt::Log::getCoreLogger()->warn (__VA_ARGS__)
#define NT_CORE_INFO(...)  ::Nt::Log::getCoreLogger()->info (__VA_ARGS__)
#define NT_CORE_TRACE(...) ::Nt::Log::getCoreLogger()->trace(__VA_ARGS__)
// #define NT_CORE_FATAL(...) ::Nt::Log::getCoreLogger()->fatal(__VA_ARGS__)

// Core log macros
#define NT_CLIENT_ERROR(...) ::Nt::Log::getClientLogger()->error(__VA_ARGS__)
#define NT_CLIENT_WARN(...)  ::Nt::Log::getClientLogger()->warn (__VA_ARGS__)
#define NT_CLIENT_INFO(...)  ::Nt::Log::getClientLogger()->info (__VA_ARGS__)
#define NT_CLIENT_TRACE(...) ::Nt::Log::getClientLogger()->trace(__VA_ARGS__)
// #define NT_CLIENT_FATAL(...) ::Nt::Log::getClientLogger()->fatal(__VA_ARGS__)

#endif // _NT_LOG_h_
