#include "../include/Textures.h"

Texture2D StartMenu;
Texture2D CheckFor123Buttons;
Texture2D CheckForContactButton;
Texture2D CheckForStartNewTest;
Texture2D EXIT;
Texture2D START;
Texture2D AboutScreen;
Texture2D CheckForBackButton;
Texture2D ABOUT; 
Texture2D RESULTS;
Texture2D CONTACTS;
Texture2D TestScreen;
Texture2D ContactsScreen;
Texture2D CheckForBackButton2;
Texture2D MenuScreen;
Texture2D CheckForSubjectButton;
Texture2D SUBJECTSTART;
Texture2D BACKONTEST;
Texture2D NEXTONTEST;
Texture2D A; 
Texture2D B;
Texture2D C; 
Texture2D D; 
Texture2D BACKONRESULT;
Texture2D ResultsScreen;
Texture2D DOTS;
void Load()
{
	StartMenu = LoadTexture("images/StartMenu2.png");
	CheckFor123Buttons = LoadTexture("images/button123.png");
	CheckForContactButton = LoadTexture("images/button_contacts.png");
	CheckForStartNewTest = LoadTexture("images/button_start_new_test.png");
	EXIT = LoadTexture("images/EXIT.png");
	START = LoadTexture("images/START.png");
	AboutScreen = LoadTexture("images/AboutScreen.png");
	CheckForBackButton = LoadTexture("images/back_button.png");
	ABOUT = LoadTexture("Images/ABOUT.png");
	RESULTS = LoadTexture("Images/RESULTS.png");
	ContactsScreen = LoadTexture("Images/ContactsScreen.png");
	CheckForBackButton2 = LoadTexture("Images/back_button2.png");
	CONTACTS = LoadTexture("Images/CONTACTS.png");
	MenuScreen = LoadTexture("Images/MenuScreen.png");
	CheckForSubjectButton = LoadTexture("Images/subjects_buttons.png");
	TestScreen = LoadTexture("Images/TestScreen.png");
	SUBJECTSTART = LoadTexture("Images/SUBJECTSTART.png");
	BACKONTEST = LoadTexture("Images/back_on_test.png");
	NEXTONTEST = LoadTexture("Images/next_on_test.png");
	A = LoadTexture("Images/A.png");
	B = LoadTexture("Images/B.png");
	C = LoadTexture("Images/C.png");
	D = LoadTexture("Images/D.png");
	BACKONRESULT = LoadTexture("Images/BACKONRESULT.png");
	ResultsScreen = LoadTexture("Images/RESULTSCREEN.png");
	DOTS = LoadTexture("Images/DOTSIFRESULTSARE0.png");
}
void Unload()
{
	UnloadTexture(StartMenu);
	UnloadTexture(CheckFor123Buttons);
	UnloadTexture(CheckForContactButton);
	UnloadTexture(CheckForStartNewTest);
	UnloadTexture(CheckForBackButton);
	UnloadTexture(CheckForBackButton2);
	UnloadTexture(CheckForSubjectButton);
	UnloadTexture(TestScreen);
	UnloadTexture(AboutScreen);
	UnloadTexture(ContactsScreen);
	UnloadTexture(MenuScreen);
	UnloadTexture(EXIT);
	UnloadTexture(ABOUT);
	UnloadTexture(RESULTS);
	UnloadTexture(START);
	UnloadTexture(CONTACTS);
	UnloadTexture(SUBJECTSTART);
	UnloadTexture(BACKONTEST);
	UnloadTexture(NEXTONTEST);
	UnloadTexture(A);
	UnloadTexture(B);
	UnloadTexture(C);
	UnloadTexture(D);
	UnloadTexture(BACKONRESULT);
	UnloadTexture(ResultsScreen);
	UnloadTexture(DOTS);
}