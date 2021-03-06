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
include "Dependencies/ImGui"

IncludeDirs = {}
IncludeDirs["GLFW"] = "Dependencies/GLFW/include"
IncludeDirs["GLAD"] = "Dependencies/GLAD/include"
IncludeDirs["FreeImage"] = "Dependencies/FreeImage/include"
IncludeDirs["ImGui"] = "Dependencies/ImGui/src"

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
        "IMGUI_IMPL_OPENGL_LOADER_GLAD"
	}

	includedirs {
		"%{prj.name}/src/",
		"%{IncludeDirs.GLFW}",
		"%{IncludeDirs.GLAD}",
		"%{IncludeDirs.FreeImage}",
		"%{IncludeDirs.ImGui}",
	}

	libdirs {
		"Dependencies/FreeImage/libs"
	}

	links {
		"GLFW",
		"GLAD",
		"FreeImage",
		"ImGui",
	}

	files { 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/Meow/**.h", 
		"%{prj.name}/src/Meow/**.cpp",
		"%{prj.name}/src/Meow/Events/**.h",
		"%{prj.name}/src/Meow/Events/**.cpp",
        "%{prj.name}/src/Meow/ImGui/**.h",
		"%{prj.name}/src/Meow/ImGui/**.cpp",
		"%{prj.name}/src/Meow/ImGui/openGL/**.h",
		"%{prj.name}/src/Meow/ImGui/openGL/**.cpp",
		"%{prj.name}/src/Meow/Maths/**.h",
		"%{prj.name}/src/Meow/Maths/**.cpp",
		"%{prj.name}/src/Meow/Renderer/**.h",
		"%{prj.name}/src/Meow/Renderer/**.cpp",
		"%{prj.name}/src/Meow/Renderer/openGL/**.h",
		"%{prj.name}/src/Meow/Renderer/openGL/**.cpp",
		"%{prj.name}/src/Meow/Scene/**.h",
		"%{prj.name}/src/Meow/Scene/**.cpp",
		"%{prj.name}/src/Meow/Utils/**.h",
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


project "MeowApplication"
	location "MeowApplication"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
    systemversion "latest"
	inlining "Auto"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediate/" .. outputdir .. "/%{prj.name}")

	includedirs {
		"MeowEngine/src",
		"%{IncludeDirs.GLFW}",
		"%{IncludeDirs.GLAD}",
		"%{IncludeDirs.FreeImage}",
		"%{IncludeDirs.ImGui}"
	}
	
	libdirs {
		"Dependencies/FreeImage/libs"
	}

	links {
		"MeowEngine"
	}

	files { 
		"%{prj.name}/shaders/**.glsl", 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	filter "system:windows"
		defines {
			"MEOW_PLATFORM_WINDOWS"
		}

	filter "system:linux"
		defines {
			"MEOW_PLATFORM_LINUX"
		}
        links {
            "GLAD",
            "GL"
        }
		postbuildcommands {
			("cp -r ./shaders/ ../bin/" .. outputdir .. "/%{prj.name}"),
			("cp -r ./assets/ ../bin/" .. outputdir .. "/%{prj.name}")
		}
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		optimize "On"
		buildoptions "/MD"
