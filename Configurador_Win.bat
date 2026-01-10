@echo off
:: Borrar la carpeta build si ya existe para empezar de cero
if exist build (
    echo Limpiando carpeta build antigua...
    rd /s /q build
)

:: Crear la carpeta y entrar en ella
mkdir build
cd build

:: Ejecutar CMake
echo Configurando proyecto con CMake...
cmake ..

echo.
echo Proceso terminado. Si no hubo errores, escribe 'cmake --build .' para compilar.
pause