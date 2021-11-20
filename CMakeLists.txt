cmake_minimum_required(VERSION 3.5)

project(MeowEngine)

add_subdirectory(Dependencies/GLFW)
add_subdirectory(Dependencies/GLAD)
add_subdirectory(Dependencies/stb_image)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")

set (self_include_dir "${PROJECT_SOURCE_DIR}/MeowEngine/Includes")
set (glfw_include_dir "${PROJECT_SOURCE_DIR}/Dependencies/GLFW/include")
set (glad_include_dir "${PROJECT_SOURCE_DIR}/Dependencies/GLAD/include")
set (stb_include_dir "${PROJECT_SOURCE_DIR}/Dependencies/stb_image")

file(GLOB source_files
  "${PROJECT_SOURCE_DIR}/MeowEngine/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/MeowEngine/src/Meow/*.cpp"
  "${PROJECT_SOURCE_DIR}/MeowEngine/src/Meow/Events/*.cpp"
  "${PROJECT_SOURCE_DIR}/MeowEngine/src/Meow/Maths/*.cpp"
  "${PROJECT_SOURCE_DIR}/MeowEngine/src/Meow/Renderable/*.cpp"
  "${PROJECT_SOURCE_DIR}/MeowEngine/src/Meow/Renderer/*.cpp"
  "${PROJECT_SOURCE_DIR}/MeowEngine/src/Meow/Renderer/openGL/*.cpp"
  "${PROJECT_SOURCE_DIR}/MeowEngine/src/Meow/Utils/*.cpp"
)
file(GLOB include_files 
  "${self_include_dir}"
  "${glfw_include_dir}"
  "${glad_include_dir}"
  "${stb_include_dir}"
)

add_library(MeowEngine SHARED "${source_files}")
target_include_directories(MeowEngine PRIVATE "${include_files}")
target_precompile_headers(MeowEngine PRIVATE "${PROJECT_SOURCE_DIR}/MeowEngine/Includes/MeowPCH.h")

target_link_directories(MeowEngine PRIVATE Dependencies/GLFW/src)
target_link_libraries(MeowEngine PRIVATE glad glfw dl pthread stb_image)

install(TARGETS MeowEngine DESTINATION lib)
