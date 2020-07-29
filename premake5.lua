workspace "Meow"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MeowEngine"
	location "MeowEngine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediate/" .. outputdir .. "/%{prj.name}")

	defines {
		"MEOW_BUILD_DLL"
	}

	files { 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		defines {
			"MEOW_PLATFORM_WINDOWS"
		}
		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/MeowApplication")
		}

	filter "system:linux"
		defines {
			"MEOW_PLATFORM_LINUX"
		}

	filter "configurations:Debug"
		defines { 
			"DEBUG",
		}
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		optimize "On"


project "MeowApplication"
	location "MeowApplication"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediate/" .. outputdir .. "/%{prj.name}")

	includedirs {
		"MeowEngine/src"
	}

	links {
		"MeowEngine"
	}

	files { 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "On"
		defines {
			"MEOW_PLATFORM_WINDOWS"
		}

	filter "system:linux"
		defines {
			"MEOW_PLATFORM_LINUX"
		}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		optimize "On"