#ifndef NDEBUG
#include <stdlib.h>
#include <time.h>
#include <vld.h>
#include <stdbool.h>
#endif
#include "raylib.h"
#include <utility>

class Sprite {

    public:

    Texture2D* textura;
    Vector2 posicion;
    Vector2 velocidad;
    float escala;
    Color color;

    Sprite(Texture2D* t = nullptr, Vector2 p = { 0,0 }, float s = 1.0f, Color c = WHITE, Vector2 v = { 200.0f })
        : textura(t), posicion(p), escala(s), velocidad(v), color(c) {
    }

    void Draw() const {
        if (textura && textura->id != 0) DrawTextureEx(*textura, posicion, 0.0f, escala, color);
    }


};




int main(void)
{
    // Inicializamos una ventana de 800x450 píxeles con un título personalizado
    InitWindow(800, 450, "Paper Mario Sprite");

    // Configuramos el framerate deseado (opcional, pero recomendado)
    SetTargetFPS(60);

    //Color fondo = { 110, 100, 215, 255 };//color violeta personalizado
    //Color texto = DARKPURPLE;

    

    //Cargar textura desde archivos
    Texture2D paperMario = LoadTexture("assets/papermario.png");
    SetTextureFilter(paperMario, TEXTURE_FILTER_BILINEAR);
    Texture2D paperMarioFondo = LoadTexture("assets/paperMarioFondo.png");
    SetTextureFilter(paperMarioFondo, TEXTURE_FILTER_BILINEAR);

    Vector2 posicionMario = { 210, 250 };
    Vector2 posicionFondo = { 0, 0 };
    Vector2 posicionMario2 = { 490, 150 };

    Sprite fondo(&paperMarioFondo, { 0,0 }, 2.7f, WHITE);
    Sprite MarioA(&paperMario, { 210,250 }, 1.0f, WHITE);
    Sprite MarioB(&paperMario, { 490, 150 }, 1.0f, BLACK);

    int activo = 0; // 0 -> a, 1 -> b
    const float velocidad = 200.0f;

    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose())
    {

        float deltaTime = GetFrameTime();

        Sprite* SpriteActivo = (activo == 0) ? &MarioA : &MarioB;

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) SpriteActivo->posicion.x += velocidad * deltaTime;
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) SpriteActivo->posicion.x -= velocidad * deltaTime;
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) SpriteActivo->posicion.y -= velocidad * deltaTime;
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) SpriteActivo->posicion.y += velocidad * deltaTime;

        if (IsKeyPressed(KEY_SPACE)) {
            std::swap(MarioA, MarioB);
            std::swap(MarioA.color, MarioB.color);
        }







        // Iniciamos la etapa de dibujo
        BeginDrawing();

        // Limpiamos la pantalla 
        ClearBackground(BLACK);

        //________Main code___________________________________________________

        //El drawing usando clases
        fondo.Draw();
        MarioA.Draw();
        MarioB.Draw();

        //Datos en pantalla
        DrawText(TextFormat("Pos: %.1f , %.1f", SpriteActivo->posicion.x, SpriteActivo->posicion.y), 10, 10, 20, BLACK);
        DrawText(TextFormat("Vel: %.1f , %.1f", SpriteActivo->velocidad.x, SpriteActivo->velocidad.y), 10, 30, 20, BLACK);
        DrawText(TextFormat("Escala: %.2f", SpriteActivo->escala), 10, 55, 20, BLACK);
        DrawText("Mover: Flechas / WASD   Swap: Tecla Espacio", 230, 420, 16, BLACK);

 

        //_________Fin del Main code_______________________________________________

        // Finalizamos el dibujo
        EndDrawing();
    }

    // Cerramos la ventana y liberamos recursos
    UnloadTexture(paperMario);
    UnloadTexture(paperMarioFondo);
    CloseWindow();

    return 0;
}

