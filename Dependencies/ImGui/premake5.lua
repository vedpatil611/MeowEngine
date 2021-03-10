project "ImGui"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediate/" .. outputdir .. "/%{prj.name}")

	includedirs {
		"../../%{IncludeDirs.GLFW}",
		"../../%{IncludeDirs.GLAD}"
	}

	files {
		"src/**.h",
		"src/**.cpp"
	}

	filter "system:linux"
		pic "On"
		staticruntime "On"

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "on"

	filter "configurations:Release"
		defines { "RELEASE" }
		optimize "on"
