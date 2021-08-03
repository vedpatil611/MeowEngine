workspace "MeowTest"
	architecture "x64"
	startproject "TestApp"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "testapp"
	location "testapp"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
    systemversion "latest"
	inlining "Auto"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediate/" .. outputdir .. "/%{prj.name}")

	includedirs {
		"../MeowEngine/Includes/"
	}
	
	libdirs {
		"../bin/" .. outputdir .. "/MeowEngine"
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
            "GL"
        }
		postbuildcommands {
			("cp ../../bin/" .. outputdir .. "/MeowEngine/libMeowEngine.so ../bin/" .. outputdir .. "/%{prj.name}/"),
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
