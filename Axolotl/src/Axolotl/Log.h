#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Axolotl {


	class AXOLOTL_API Log
	{
	public:
		Log();
		~Log();

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}


// core log macros
#define AX_CORE_TRACE(...)::Axolotl::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AX_CORE_INFO(...)::Axolotl::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AX_CORE_WARN(...)::Axolotl::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AX_CORE_ERROR(...)::Axolotl::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AX_CORE_CRITICAL(...)::Axolotl::Log::GetCoreLogger()->critical(__VA_ARGS__)

// client log macros
#define AX_TRACE(...)::Axolotl::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AX_INFO(...)::Axolotl::Log::GetClientLogger()->info(__VA_ARGS__)
#define AX_WARN(...)::Axolotl::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AX_ERROR(...)::Axolotl::Log::GetClientLogger()->error(__VA_ARGS__)
#define AX_CRITICAL(...)::Axolotl::Log::GetClientLogger()->critical(__VA_ARGS__)


