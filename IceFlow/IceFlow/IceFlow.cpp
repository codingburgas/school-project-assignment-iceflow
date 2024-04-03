#include "include/IceFlow.h"
int main()
{
	InitWindow(1280, 720, "IceFlow"); // create exe name, width and height
    SetTargetFPS(60); 
    
	Load(); // define textures
	
	while (!WindowShouldClose())
	{
		BeginDrawing();
		DrawTexture(StartMenu, 0, 0, RAYWHITE); // draw backgound

		ShowDate(); // show year,month,day
		ShowHour(); // show hour,minutes and seconds
		
		Buttons(); // start menu buttons

		EndDrawing();
	}
	Unload();
	
}


