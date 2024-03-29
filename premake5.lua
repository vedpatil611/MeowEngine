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
IncludeDirs["STB_IMAGE"] = "Dependencies/stb_image"

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
		"%{IncludeDirs.STB_IMAGE}"
	}

	links {
		"GLFW",
		"GLAD",
	}

	files { 
		"%{prj.name}/Includes/**.h",
		"%{prj.name}/Includes/Meow/**.h",
		"%{prj.name}/Includes/Meow/Events/**.h",
		"%{prj.name}/Includes/Meow/Maths/**.h",
		"%{prj.name}/Includes/Meow/Renderable/**.h",
		"%{prj.name}/Includes/Meow/Renderer/**.h",
		"%{prj.name}/Includes/Meow/Renderer/openGL/**.h",
		"%{prj.name}/Includes/Meow/Scene/**.h",
		"%{prj.name}/Includes/Meow/Utils/**.h",

		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/Meow/**.cpp",
		"%{prj.name}/src/Meow/Events/**.cpp",
		"%{prj.name}/src/Meow/Maths/**.cpp",
		"%{prj.name}/src/Meow/Renderable/**.cpp",
		"%{prj.name}/src/Meow/Renderer/**.cpp",
		"%{prj.name}/src/Meow/Renderer/openGL/**.cpp",
		"%{prj.name}/src/Meow/Scene/**.cpp",
		"%{prj.name}/src/Meow/Utils/**.cpp",
		"Dependencies/stb_image/stb_image.cpp"
	}

	filter "system:windows"		
		defines {
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "system:linux"
		pic "On"
		staticruntime "On"
		links {
			"dl",
			"pthread",
        }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		optimize "On"
		buildoptions "/MD"
