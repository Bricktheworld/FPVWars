cmake_minimum_required(VERSION 3.19.4)

set(This FPVWars)

project(${This} VERSION 0.1.0)


enable_testing()

file(
  GLOB_RECURSE Sources
  "vendor/*.cpp"
  "src/sources.cpp"
)


if(UNIX)
  set(CMAKE_CXX_STANDARD 20)
  find_package(GTest CONFIG REQUIRED)
  # include_directories(${ASSIMP_INCLUDE_DIRS})
endif(UNIX)

include_directories(src vendor)

set(TargetIncludeDirs src vendor)

set(Libs GL glfw3 X11 Xxf86vm Xrandr pthread Xi dl freetype)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC ${Libs})
target_include_directories(${This} PUBLIC ${TargetIncludeDirs})

add_subdirectory(tests)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
set(CMAKE_CXX_FLAGS "-Wno-reorder -Wno-volatile -Wno-deprecated-enum-enum-conversion")
