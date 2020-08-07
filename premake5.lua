workspace "Meow"
	architecture "x64"
	startproject "MeowApplication"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Dependencies/GLFW"
include "Dependencies/GLAD"

IncludeDirs = {}
IncludeDirs["GLFW"] = "Dependencies/GLFW/include"
IncludeDirs["GLAD"] = "Dependencies/GLAD/include"

project "MeowEngine"
	location "MeowEngine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediate/" .. outputdir .. "/%{prj.name}")

	defines {
		"MEOW_BUILD_DLL"
	}

	includedirs {
		"%{prj.name}/src/",
		"%{IncludeDirs.GLFW}",
		"%{IncludeDirs.GLAD}"
	}

	links {
		"GLFW",
		"GLAD"
	}

	files { 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/Meow/**.h", 
		"%{prj.name}/src/Meow/**.cpp",
		"%{prj.name}/src/Meow/Maths/**.h",
		"%{prj.name}/src/Meow/Maths/vector/**.h",
		"%{prj.name}/src/Meow/Maths/vector/**.cpp"
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

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediate/" .. outputdir .. "/%{prj.name}")

	includedirs {
		"MeowEngine/src",
		"%{IncludeDirs.GLFW}",
		"%{IncludeDirs.GLAD}"
	}

	links {
		"MeowEngine",
		"GLAD"
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