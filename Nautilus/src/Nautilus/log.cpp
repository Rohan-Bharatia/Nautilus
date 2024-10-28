#ifndef _NT_LOG_cpp_
	#define _NT_LOG_cpp_

#include "log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Nt
{
	std::shared_ptr<spdlog::logger> Log::m_coreLogger;
	std::shared_ptr<spdlog::logger> Log::m_clientLogger;

	void Log::init(void)
	{
		spdlog::set_pattern("%^[%T] %n: %v%$", spdlog::pattern_time_type::local);

		m_coreLogger = spdlog::stdout_color_mt("[NAUTILUS]");
		m_coreLogger->set_level(spdlog::level::trace);

		m_clientLogger = spdlog::stdout_color_mt("[APPLICATION]");
		m_clientLogger->set_level(spdlog::level::trace);

	}

	inline std::shared_ptr<spdlog::logger>& Log::getCoreLogger(void)
	{
		return m_coreLogger;
	}
	inline std::shared_ptr<spdlog::logger>& Log::getClientLogger(void)
	{
		return m_clientLogger;
	}
	//
} // namespace Nt

#endif // _NT_LOG_cpp_
