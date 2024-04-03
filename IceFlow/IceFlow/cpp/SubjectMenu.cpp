#include "../include/SubjectMenu.h"
#include "../include/StartButtons.h"
#include "raylib.h"
#include "../include/Textures.h"

bool MathON = 0, GeographyON = 0, EnglishON = 0;
void Menu()
{
	
	if (CheckerStartTest && !MathON && !GeographyON && !EnglishON)//&& !GeographyON && !EnglishON)
	{
		
			DrawTexture(MenuScreen, 0, 0, RAYWHITE);
			DrawTexture(CheckForBackButton, 75, 60, BLANK);
			DrawTexture(SUBJECTSTART, 185, 530, RAYWHITE); // maths
			DrawTexture(SUBJECTSTART, 585, 530, RAYWHITE); // geography
			DrawTexture(SUBJECTSTART, 977, 530, RAYWHITE); // english

			bool HoverBack2 = CheckCollisionPointRec(GetMousePosition(), { 75,60,(float)CheckForBackButton.width,(float)CheckForBackButton.height });

			bool HoverSubject[3]
			{
				CheckCollisionPointRec(GetMousePosition(), { 185,530,(float)CheckForSubjectButton.width,(float)CheckForSubjectButton.height }),
				CheckCollisionPointRec(GetMousePosition(), { 585,530,(float)CheckForSubjectButton.width,(float)CheckForSubjectButton.height }),
				CheckCollisionPointRec(GetMousePosition(), { 977,530,(float)CheckForSubjectButton.width,(float)CheckForSubjectButton.height })
			};
			if (HoverBack2 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				CheckerStartTest = false;
			}
			
			// subject buttons on hover
			if (HoverSubject[0])
			{
				DrawTexture(SUBJECTSTART, 185, 530, YELLOW);
			}
			if (HoverSubject[1])
			{
				DrawTexture(SUBJECTSTART, 585, 530, YELLOW);
			}
			if (HoverSubject[2])
			{
				DrawTexture(SUBJECTSTART, 977, 530, YELLOW);
			}

			if (HoverSubject[0] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				MathON = true;
			}
			if (HoverSubject[1] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				GeographyON = true;
			}
			if (HoverSubject[2] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				EnglishON = true;
			}		
			
	}
	
	
}