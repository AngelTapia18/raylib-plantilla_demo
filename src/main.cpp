#include "raylib.h"

int main(void) {
    // 1. Inicialización
    InitWindow(800, 450, "Mi Proyecto con Raylib");
    SetTargetFPS(60);

    // 2. Bucle principal del juego
    while (!WindowShouldClose()) {
        // Actualizar variables aquí...

        // 3. Dibujado
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("¡Todo listo para empezar!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    // 4. Desinicialización
    // Hola
    CloseWindow();
    return 0;
}