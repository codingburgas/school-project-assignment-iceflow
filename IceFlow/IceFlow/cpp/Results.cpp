#include "../include/Results.h"
#include "../include/StartButtons.h"
#include "raylib.h"
#include "../include/TestMode.h"
#include "../include/Textures.h"
#include <string>
#include <stdlib.h>
using namespace std;
void Result()
{
	if (Checker1)
	{
		DrawTexture(ResultsScreen, 0, 0, RAYWHITE); // draw results screen
		DrawTexture(CheckForBackButton, 92, 65, BLANK); // back button check

		bool HoverBack = CheckCollisionPointRec(GetMousePosition(), { 92, 65, (float)CheckForBackButton.width, (float)CheckForBackButton.height });
		if (HoverBack && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Checker1 = false;
		}
		//if the math test hasn't been done yet show some dots decoration, else show the result (same for other)
		if (!LastResultMath)
		{
			DrawTexture(DOTS,440, 285, RAYWHITE);
		}
		else
		{
			DrawText((to_string(LastResultMath) + "%").c_str(), 440, 200, 120, BLACK);
		}

        // Geography Last
		if (!LastResultGeography)
		{
			DrawTexture(DOTS, 610, 409, RAYWHITE);
		}
		else
		{
			DrawText((to_string(LastResultGeography) + "%").c_str(), 610, 319, 120, BLACK);
		}

		// English Last
		if (!LastResultEnglish)
		{
			DrawTexture(DOTS, 480, 539, RAYWHITE);
		}
		else
		{
			DrawText((to_string(LastResultEnglish) + "%").c_str(), 480, 447, 120, BLACK);
		}

		// Lowest
		if (!LastResultMath && !LastResultEnglish && !LastResultGeography)
		{
			DrawTexture(DOTS, 980, 470, RAYWHITE);
		}
		else if (LastResultMath && !LastResultGeography && !LastResultEnglish)
		{
			DrawText((to_string(LastResultMath) + "%").c_str(), 980, 430, 90, BLACK);
		}
		else if (!LastResultMath && LastResultGeography && !LastResultEnglish)
		{
			DrawText((to_string(LastResultGeography) + "%").c_str(), 980, 430, 90, BLACK);
		}
		else if (!LastResultMath && !LastResultGeography && LastResultEnglish)
		{
			DrawText((to_string(LastResultEnglish) + "%").c_str(), 980, 430, 90, BLACK);
		}
		else if (LastResultMath && LastResultGeography && !LastResultEnglish)
		{
			DrawText((to_string(min(LastResultMath,LastResultGeography)) + "%").c_str(), 980, 430, 90, BLACK);
		}
		else if (LastResultMath && !LastResultGeography && LastResultEnglish)
		{
			DrawText((to_string(min(LastResultMath, LastResultEnglish)) + "%").c_str(), 980, 430, 90, BLACK);
		}
		else if (!LastResultMath && LastResultGeography && LastResultEnglish)
		{
			DrawText((to_string(min(LastResultGeography,LastResultEnglish)) + "%").c_str(), 980, 430, 90, BLACK);
		}
		else if (LastResultMath && LastResultGeography && LastResultEnglish)
		{
			DrawText((to_string(min(min(LastResultGeography, LastResultEnglish), LastResultMath)) + "%").c_str(), 980, 430, 90, BLACK);
		}

		// Highest
		if (!LastResultMath && !LastResultEnglish && !LastResultGeography)
		{
			DrawTexture(DOTS, 980, 320,RAYWHITE);
		}
		else if (LastResultMath && !LastResultGeography && !LastResultEnglish)
		{
			DrawText((to_string(LastResultMath) + "%").c_str(), 980, 280, 90, BLACK);
		}
		else if (!LastResultMath && LastResultGeography && !LastResultEnglish)
		{
			DrawText((to_string(LastResultGeography) + "%").c_str(), 980, 280, 90, BLACK);
		}
		else if (!LastResultMath && !LastResultGeography && LastResultEnglish)
		{
			DrawText((to_string(LastResultEnglish) + "%").c_str(), 980, 280, 90, BLACK);
		}
		else if (LastResultMath && LastResultGeography && !LastResultEnglish)
		{
			DrawText((to_string(max(LastResultMath, LastResultGeography)) + "%").c_str(), 980, 280, 90, BLACK);
		}
		else if (LastResultMath && !LastResultGeography && LastResultEnglish)
		{
			DrawText((to_string(max(LastResultMath, LastResultEnglish)) + "%").c_str(), 980, 280, 90, BLACK);
		}
		else if (!LastResultMath && LastResultGeography && LastResultEnglish)
		{
			DrawText((to_string(max(LastResultGeography, LastResultEnglish)) + "%").c_str(), 980, 280, 90, BLACK);
		}
		else if (LastResultMath && LastResultGeography && LastResultEnglish)
		{
			DrawText((to_string(max(max(LastResultGeography, LastResultEnglish), LastResultMath)) + "%").c_str(), 980, 280, 90, BLACK);
		}



		//Average
		if (!LastResultMath && !LastResultEnglish && !LastResultGeography)
		{
			DrawTexture(DOTS, 980, 620, RAYWHITE);
		}
		else if (LastResultMath && !LastResultGeography && !LastResultEnglish)
		{
			DrawText((to_string(LastResultMath) + "%").c_str(), 980, 580, 90, BLACK);
		}
		else if (!LastResultMath && LastResultGeography && !LastResultEnglish)
		{
			DrawText((to_string(LastResultGeography) + "%").c_str(), 980, 580, 90, BLACK);
		}
		else if (!LastResultMath && !LastResultGeography && LastResultEnglish)
		{
			DrawText((to_string(LastResultEnglish) + "%").c_str(), 980, 580, 90, BLACK);
		}
		else if (LastResultMath && LastResultGeography && !LastResultEnglish)
		{
			DrawText((to_string((LastResultMath + LastResultGeography) / 2) + "%").c_str(), 980, 580, 90, BLACK);
		}
		else if (LastResultMath && !LastResultGeography && LastResultEnglish)
		{
			DrawText((to_string((LastResultMath + LastResultEnglish) / 2) + "%").c_str(), 980, 580, 90, BLACK);
		}
		else if (!LastResultMath && LastResultGeography && LastResultEnglish)
		{
			DrawText((to_string((LastResultGeography + LastResultEnglish) / 2) + "%").c_str(), 980, 580, 90, BLACK);
		}
		else if (LastResultMath && LastResultGeography && LastResultEnglish)
		{
			DrawText((to_string((LastResultGeography + LastResultEnglish + LastResultMath) / 3) + "%").c_str(), 980, 580, 90, BLACK);
		}

    } 
}