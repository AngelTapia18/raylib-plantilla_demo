#include <iostream>
#include "raylib.h"
#include <deque>
#include <raymath.h>

using namespace std;

Color green = {173, 204, 96, 255 };
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;

double lastUpdateTime = 0;

bool ElementInDeque(Vector2 element, deque<Vector2> deq) {
    for (unsigned int i = 0; i < deq.size(); i++) {
        if (Vector2Equals(deq[i], element)) {
            return true;
        }
    }
    return false;
}

bool eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;

}

//Vector2 - A structure to hold 2D vector data (x, y).
//deque - A deque is a data structure that allows you to add or remove elements from both ends efficiently.

class Snake {

public:
    deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}}; //deque of Vector2 positions
    Vector2 direction = {1, 0}; //initial direction to the right
    bool addSegment = false;

    void Draw() {
        for (int i = 0; i < body.size(); i++) {
            float  x = body[i].x;
            float  y = body[i].y;
            Rectangle segment = Rectangle{x * cellSize, y * cellSize, (float)cellSize, (float)cellSize};
            DrawRectangleRounded(segment, 0.5, 6, darkGreen);
        }
    }

    void Update() {
        body.push_front(Vector2Add(body[0], direction)); //add new head in the direction of movement
        if(addSegment == true){
            addSegment = false;
        }else{
            body.pop_back(); //remove last segment
        }
    }

    void Reset() {
        body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}}; //reset to initial position
        direction = {1, 0}; //reset direction to the right
    }
};

class Food {

public:
    Vector2 position;
    Texture2D texture;

    Food(deque<Vector2> snakeBody) { //Constructor
        Image image = LoadImage("../Graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position = GenerateRandomPos(snakeBody);
    }

    ~Food() { //Destructor
        UnloadTexture(texture);
    }

    void Draw() {
        // DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, darkGreen); //x,y,width,height,color
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE); //texture, x,y,tint (color)
    }

    Vector2 GenerateRandonCell() {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return Vector2 {x, y};
    }

    Vector2 GenerateRandomPos(deque<Vector2> snakeBody) {
        
        Vector2 position = GenerateRandonCell();
        while(ElementInDeque(position, snakeBody)){
            position = GenerateRandonCell();
        }
        return position;
    }

};

class Game { //a general class to manage game state an objects inside the game - easier to maintain

public:
    Snake snake = Snake ();
    Food food = Food (snake.body);
    bool running = true;

    void Draw() {
        snake.Draw();
        food.Draw();
    }

    void Update() {//update game state
        if(running) {
            snake.Update();
            CheckCollisionWithFood();
            CheckCollisionWithEdges();
            CheckCollisionWithTale();
        }
    }

    void CheckCollisionWithFood() {
        if (Vector2Equals(snake.body[0], food.position)) {
            snake.addSegment = true; //grow snake
            food.position = food.GenerateRandomPos(snake.body); //relocate food
        }
    }

    void CheckCollisionWithEdges() {
        if(snake.body[0].x == cellCount || snake.body[0].x == -1) {
            //handle collision with horizontal edges
            GameOver (); //end game or wrap around
        }
        if(snake.body[0].y == cellCount || snake.body[0].y == -1) {
            //handle collision with vertical edges
            //end game or wrap around
            GameOver ();
        }
    }

    void GameOver() {
        //reset snake and food positions
        snake.Reset();
        food.position = food.GenerateRandomPos(snake.body);
        running = false;
    }

    void CheckCollisionWithTale() {
        deque<Vector2> headlessBody = snake.body;
        headlessBody.pop_front(); //remove head from the body to check collision with the rest
        if(ElementInDeque(snake.body[0], headlessBody)) {
            GameOver();
        }   
    }

};

int main () {

    cout << "Starting the game..." << endl;
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake Game");
    SetTargetFPS(60); //set frame rate to 60 frames per second

    Game game = Game();

    while(WindowShouldClose() == false) { //game loop - runs until window is closed
        BeginDrawing(); //create a black canvas
            //ClearBackground(BLACK);

            if(eventTriggered(0.2)) { //update position every 0.2 seconds
                game.Update();
            }

            if(IsKeyPressed(KEY_UP) && game.snake.direction.y != 1) {
                game.snake.direction = {0, -1};
                game.running = true;
            }
            if(IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1) {
                game.snake.direction = {0, 1};
                game.running = true;
            }
            if(IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1) {
                game.snake.direction = {-1, 0};
                game.running = true;
            }
            if(IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1) {
                game.snake.direction = {1, 0};
                game.running = true;
            }

            // Drawing
            ClearBackground(green);
            game.Draw();
        EndDrawing();

    }


    CloseWindow();
    return 0;   
}

