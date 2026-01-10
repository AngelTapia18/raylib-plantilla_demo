
# Plantilla proyectos Raylib

Esta plantilla sirve como base para generar un proyecto utilizando la libreria de raylib


## Requisitos iniciales

Para poder generar un proyecto de raylib es necesario realizar los siguientes pasos:

- Generar una carpeta con el nombre del proyecto que se va a desarrollar
- Clonar el repositorio directamente a la carpeta creada
- Tener las dependencias instaladas


## Documentation

- Instalar la versión más reciente de CMake (cmake version 4.2.1)

- Ejecutar el script "Configurador_Win.bat" para usuarios windows

- Ejecutar el script "Configurador_Lin.sh" para usuarios Linux

- Al terminar de ejecutar el script, ejecutar el comando siguiente:

``` bash
    # Configura el script como ejecutable
    chmod +x ./Configurador_Lin.sh
```

``` bash
    # Genera el proyecto
    cmake --build .
```

- Para ejecutar el programa, se debe ejecutar el archivo .exe generado con el siguiente comando

``` bash
    .\Debug\MiJuegoRaylib.exe
```