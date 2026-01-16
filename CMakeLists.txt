cmake_minimum_required(VERSION 4.2.1)

set(CMAKE_POLICY_VERSION_MINIMUM 4.2.1)
project(MiJuegoRaylib) # Cambiar el nombre del proyecto

# Establece el estandar de C++
set(CMAKE_CXX_STANDARD 20)

# Comprobacion e instalacion de dependencia raylib
include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib/
        GIT_TAG c1ab645ca298a2801097931d1079b10ff7eb9df8
        GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raylib)

# file(GLOB_RECURSE PROJECT_SOURCES "src/**.cpp" "src/**.h")
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/") # Define PROJECT_INCLUDE to be the path to the include directory of the project


# Seleccion de archivo principal del proyecto
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)