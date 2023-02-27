workspace "Snow"
	architecture "x64"
	
	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Snow"
	location "Snow"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "snowpch.h"
	pchsource "Snow/src/snowpch.cpp"


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"SNOW_PLATFORM_WINDOWS",
			"SNOW_BUILD_DLL"			
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SNOW_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SNOW_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SNOW_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Snow/vendor/spdlog/include",
		"Snow/src"
	}

	links
	{
		"Snow"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"SNOW_PLATFORM_WINDOWS"
		}
		
	
	filter "configurations:Debug"
		defines "SNOW_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SNOW_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SNOW_DIST"
		optimize "On"