#include "raylib.h"

int main() {
	InitWindow(800, 600, "Budgeting App");

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Hello, world!", GetMouseX(), GetMouseY(), 16, RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
