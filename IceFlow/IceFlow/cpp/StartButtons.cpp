#include "../include/StartButtons.h"
#include "../include/Textures.h"
#include "raylib.h"
#include <stdlib.h>
bool Checker1 = 0, Checker2 = 0, Checker3 = 0;
bool CheckerStartTest = 0;
bool CheckerContacts = 0;

void Buttons()
{
	if (!CheckerStartTest && !Checker2 && !Checker1 && !CheckerContacts)
	{

		DrawTexture(CheckFor123Buttons, 55, 367, BLANK); // check for result button
		DrawTexture(CheckFor123Buttons, 55, 487, BLANK); // check for about button
		DrawTexture(CheckFor123Buttons, 55, 617, BLANK); // check for exit button
		DrawTexture(CheckForContactButton, 38, 36, BLANK); // check contacts button
		DrawTexture(CheckForStartNewTest, 860, 200, BLANK); // check start new test button

	     bool Hover123[3] = 
		 {
			CheckCollisionPointRec(GetMousePosition(), { 55, 367, (float)CheckFor123Buttons.width, (float)CheckFor123Buttons.height }),
			CheckCollisionPointRec(GetMousePosition(), { 55, 487, (float)CheckFor123Buttons.width, (float)CheckFor123Buttons.height }),
			CheckCollisionPointRec(GetMousePosition(), {55, 617, (float)CheckFor123Buttons.width, (float)CheckFor123Buttons.height})
		 };
		 bool HoverContacts = CheckCollisionPointRec(GetMousePosition(), { 38, 36, (float)CheckForContactButton.width, (float)CheckForContactButton.height });
		 bool HoverStartTest = CheckCollisionPointRec(GetMousePosition(), { 860, 200, (float)CheckForStartNewTest.width , (float)CheckForStartNewTest.height });

		// check if any of the result,about and exit buttons are hovered and pressed
		if (Hover123[0] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Checker1 = true; // results is pressed
		}
		if (Hover123[1] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Checker2 = true; // about is pressed
		}
		if (Hover123[2] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Checker3 = true; // exit is pressed
		}

		if (Checker3)
		{
			Unload();
			exit(0); // exit button
		}
		//check if any of the buttons results,about or exit is hovered
		if (Hover123[0])
		{
			DrawTexture(RESULTS, 25, 348, RAYWHITE);
		}
		if (Hover123[1])
		{
			DrawTexture(ABOUT, 30, 480, RAYWHITE);
		}
		if (Hover123[2]) // exit button
		{
			DrawTexture(EXIT, 36.5, 604, RAYWHITE);
		}

		if (HoverStartTest)
		{
			DrawTexture(START, 799, 147, RAYWHITE); // start button on hover
		}
		if (HoverContacts)
		{
			DrawTexture(CONTACTS, 26, 29, RAYWHITE); // contacts button hover
		}
		if (HoverStartTest && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			CheckerStartTest = true; // start new test is pressed
		}
		if (HoverContacts && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			CheckerContacts = true; // contacts button is pressed
		}

	}
	


}