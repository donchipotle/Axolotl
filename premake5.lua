workspace "Axolotl"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Axolotl"
	location "Axolotl"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir .. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

	pchheader "axpch.h"
	pchsource "Axolotl/src/axpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
		
	}

	filter   "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AX_PLATFORM_WINDOWS",
			"AX_BUILD_DLL"
		}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "AX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AX_Dist"
		optimize "On"
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" ..outputdir .. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Axolotl/vendor/spdlog/include",
		"Axolotl/src"
	}
	links 
	{
		"Axolotl"
	}

	filter  "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
		{
			"AX_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "AX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AX_Dist"
		optimize "On"