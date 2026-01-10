cmake_minimum_required(VERSION 4.2.1)

set(CMAKE_POLICY_VERSION_MINIMUM 4.2.1)
project(MiJuegoRaylib) # Cambiar el nombre del proyecto

# Establece el estandar de C++
set(CMAKE_CXX_STANDARD 17)

# Comprobacion e instalacion de dependencia raylib
include(FetchContent)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib/
        GIT_TAG c1ab645ca298a2801097931d1079b10ff7eb9df8
)
FetchContent_MakeAvailable(raylib)

# Seleccion de archivo principal del proyecto
add_executable(${PROJECT_NAME} src/main.cpp)

# Enlazar librerias de raylib al sistema
target_link_libraries(${PROJECT_NAME} raylib)

# Deteccion de raylib.h al proyecto
target_include_directories(${PROJECT_NAME} PUBLIC src)