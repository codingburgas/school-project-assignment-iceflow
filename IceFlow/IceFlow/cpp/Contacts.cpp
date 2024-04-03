#include "../include/Contacts.h"
#include "../include/StartButtons.h"
#include "../include/Textures.h"
void Contacts()
{
	bool HoverBack = CheckCollisionPointRec(GetMousePosition(), { 78,62,(float)CheckForBackButton2.width,(float)CheckForBackButton2.height });
	if (CheckerContacts)
	{
		DrawTexture(ContactsScreen, 0, 0, RAYWHITE);
		DrawTexture(CheckForBackButton2, 78, 62, BLANK);
		if (HoverBack && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			CheckerContacts = false;
		}
	}
}