#!/bin/bash

# Borrar build antiguo
rm -rf build

# Crear y entrar
mkdir build
cd build || exit

# Ejecutar CMake
cmake cmake ..

echo "Configuración completada."