cmake_minimum_required(VERSION 3.11)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
project(MiJuegoRaylib) #Cambiar el nombre del proyecto

# Comprobacion e instalacion de dependencia raylib
include(FetchContent)
FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)
FetchContent_MakeAvailable(raylib)

# Seleccion de archivo principal del proyecto
add_executable(${PROJECT_NAME} src/main.cpp)

# Enlazar librerias de raylib al sistema
target_link_libraries(${PROJECT_NAME} raylib)

# Deteccion de raylib.h al proyecto
target_include_directories(${PROJECT_NAME} PUBLIC src)