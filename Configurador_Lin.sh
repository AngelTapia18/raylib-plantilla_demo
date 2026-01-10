#!/bin/bash

# Borrar build antiguo
rm -rf build

# Crear y entrar
mkdir build
cd build

# Ejecutar CMake
cmake ..

echo "Configuración completada."