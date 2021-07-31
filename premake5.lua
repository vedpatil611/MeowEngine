workspace "Meow"
	architecture "x64"

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
IncludeDirs["FreeImage"] = "Dependencies/FreeImage/include"

project "MeowEngine"
	location "MeowEngine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	systemversion "latest"
	inlining "Auto"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediate/" .. outputdir .. "/%{prj.name}")

	pchheader "MeowPCH.h"
	pchsource "MeowEngine/src/MeowPCH.cpp"

	defines {
		"MEOW_BUILD_DLL",
	}

	includedirs {
		"%{prj.name}/Includes/",
		"%{IncludeDirs.GLFW}",
		"%{IncludeDirs.GLAD}",
		"%{IncludeDirs.FreeImage}",
	}

	libdirs {
		"Dependencies/FreeImage/libs"
	}

	links {
		"GLFW",
		"GLAD",
		"FreeImage",
	}

	files { 
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/Meow/**.cpp",
		"%{prj.name}/src/Meow/Events/**.cpp",
		"%{prj.name}/src/Meow/Maths/**.cpp",
		"%{prj.name}/src/Meow/Renderable/**.cpp",
		"%{prj.name}/src/Meow/Renderer/**.cpp",
		"%{prj.name}/src/Meow/Renderer/openGL/**.cpp",
		"%{prj.name}/src/Meow/Scene/**.cpp",
		"%{prj.name}/src/Meow/Utils/**.cpp"
	}

	filter "system:windows"		
		defines {
			"MEOW_PLATFORM_WINDOWS",
			"_CRT_SECURE_NO_WARNINGS"
		}
		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/MeowApplication"),
			("{COPY} ../Dependencies/FreeImage/bin/ ../bin/" .. outputdir .. "/MeowApplication")
		}

	filter "system:linux"
		pic "On"
		staticruntime "On"
		links {
			"dl",
			"pthread",
        }
		defines {
			"MEOW_PLATFORM_LINUX"
		}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		optimize "On"
		buildoptions "/MD"
