#include "../include/About.h"
#include "../include/Textures.h"
#include "../include/StartButtons.h"
void About()
{
	if (Checker2)
	{
		DrawTexture(AboutScreen, 0, 0, RAYWHITE); // about page	
		DrawTexture(CheckForBackButton,55, 55,BLANK); // back button check
	    bool HoverBack = CheckCollisionPointRec(GetMousePosition(), { 55, 55, (float)CheckForBackButton.width, (float)CheckForBackButton.height });
		if (HoverBack && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Checker2 = false;
		}
	}
}