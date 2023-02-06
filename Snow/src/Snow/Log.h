#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Snow {
	class SNOW_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private: 
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};


}


// Core log macros
#define SNOW_CORE_TRACE(...) ::Snow::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SNOW_CORE_INFO(...)  ::Snow::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SNOW_CORE_WARN(...)  ::Snow::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SNOW_CORE_ERROR(...) ::Snow::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SNOW_CORE_FATAL(...) ::Snow::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define SNOW_INFO(...)  ::Snow::Log::GetClientLogger()->info(__VA_ARGS__)
#define SNOW_TRACE(...) ::Snow::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SNOW_WARN(...)  ::Snow::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SNOW_ERROR(...) ::Snow::Log::GetClientLogger()->error(__VA_ARGS__)
#define SNOW_FATAL(...) ::Snow::Log::GetClientLogger()->fatal(__VA_ARGS__)