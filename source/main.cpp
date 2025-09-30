#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, util en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"

int main(void)
{
    // Inicializamos una ventana de 800x450 pixeles con un titulo personalizado
    InitWindow(800, 450, "Mi Proyecto! Leandro Sanchez");

    // Configuramos el framerate deseado (opcional, pero recomendado)
    SetTargetFPS(60);

    Color fondo = { 51, 143, 131 };//color personalizado
    Color texto = DARKPURPLE;

    int MensajeActual = 0;

    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose())
    {
        // Iniciamos la etapa de dibujo
        BeginDrawing();

        // Limpiamos la pantalla 
        ClearBackground(fondo);

		// Dibujamos un texto centrado, aca damos la posicion, el tamanio y el color
        DrawText("BUENAS! MI NOMBRE ES LEAN!", 155, 197, 30, texto);

        // Dibujamos un rectagulo a modo decorativo
        DrawRectangle(80, 190, 650, 40, Fade(DARKGREEN, 0.5f)); // Fondo semitransparente para resaltar el texto

        DrawCircle(385, 300, 50, { 0, 117, 44, 255 });

        if (IsKeyPressed(KEY_SPACE)) {

            MensajeActual = 1;
        }

        if (MensajeActual == 0) {
            DrawText("Estoy programando en Raylib!", 155, 370, 30, texto);
        }
        else {
            DrawText("Espero poder avanzar!", 210, 370, 30, texto);
        }
        // Finalizamos el dibujo
        EndDrawing();
    }

    // Cerramos la ventana y liberamos recursos
    CloseWindow();

    return 0;
}

