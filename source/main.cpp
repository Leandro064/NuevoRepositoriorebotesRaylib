#ifndef NDEBUG
#if defined(__has_include)
#if __has_include(<vld.h>)
#include <vld.h> // Visual Leak Detector solo si está instalado y en Debug
#endif
#endif
#endif

#include <cstdlib>
#include <ctime>
#include "raylib.h"

int main(void)
{
    // Inicializamos una ventana de 1024x768 pixeles con un titulo personalizado
    InitWindow(1024, 768, "Mi Proyecto! Leandro Sanchez");

    Color fondo = { 51, 143, 131, 255 };//color personalizado
    Color texto = DARKPURPLE;

    //Posición de la pelota en los ejes X e Y
    Vector2 posicion = { 1024 / 2.0f, 768 / 2.0f };
    //Velocidad que se le otorgará a la pelota
    Vector2 velocidad = { 200.0f, 100.0f };

    //Configura el framerate
    SetTargetFPS(60);
    srand(time(NULL));

    Color transparente = { 255, 0, 0, 120 };
    Color colorPelota = Fade(DARKGREEN, 0.5f);

    int MensajeActual = 0;

    int rebotes = 0;

    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose())
    {
        // Iniciamos la etapa de dibujo
        BeginDrawing();

        // Limpiamos la pantalla 
        ClearBackground(fondo);


        //_____________________________________
         //Tiempo base
        float deltaTime = GetFrameTime();
     
        //Para mostrar el contacto con algun borde
        bool contacto = false;

        //Constantemente actualiza el tiempo y la velocidad
        posicion.x += velocidad.x * deltaTime;
        posicion.y += velocidad.y * deltaTime;

        //Colisión izquierda y derecha
        if ((posicion.x + 80) >= 1024) {

            posicion.x = 1024 - 80;

            velocidad.x *= -1;

            rebotes = true;
        }
        else if ((posicion.x - 80) <= 0) {

            posicion.x = 80;

            velocidad.x *= -1;

            rebotes = true;
        }

        //Colisión parte superior y parte inferior
        if ((posicion.y + 80) >= 768) {

            posicion.y = 768 - 80;

            velocidad.y *= -1;

            rebotes = true;
        }
        else if ((posicion.y - 80) <= 0) {

            posicion.y = 80;

            velocidad.y *= -1;

            rebotes = true;
        }

        if (contacto) rebotes++;

        //Para mostrar posición actual de la pelota
        DrawText(TextFormat("Posicion: (%.1f, %.1f)", posicion.x, posicion.y), 10, 35, 20, RAYWHITE);

        //Cantidad de rebotes
        DrawText(TextFormat("Rebotes: %d", rebotes), 10, 60, 20, Fade(RAYWHITE, 0.6f));

        //Dibuja un círculo, indicando posición, radio y color
        DrawCircle(posicion.x, posicion.y, 80, (Color)colorPelota);


        //___________________________


		// Dibujamos un texto centrado, aca damos la posicion, el tamanio y el color
        DrawText("BUENAS! MI NOMBRE ES LEAN!", 265, 75, 30, texto);

        // Dibujamos un rectagulo a modo decorativo
        DrawRectangle(190, 68, 650, 40, Fade(DARKGREEN, 0.5f)); // Fondo semitransparente para resaltar el texto

        if (MensajeActual == 0) {
            DrawText("Estoy programando en Raylib!", 265, 590, 30, texto);
        }
        else {
            DrawText("Espero poder avanzar!", 320, 590, 30, texto);
        }



        // Finalizamos el dibujo
        EndDrawing();
    }

    // Cerramos la ventana y liberamos recursos
    CloseWindow();

    return 0;
}

