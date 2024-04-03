#pragma once
#include "raylib.h"

extern Texture2D StartMenu;
//checkers for exit,about,result,start new test, contact buttons
extern Texture2D CheckFor123Buttons; // result,exit,about
extern Texture2D CheckForContactButton; // contact button
extern Texture2D CheckForStartNewTest; // start the program button check
extern Texture2D CheckForBackButton; // back button in about page
extern Texture2D CheckForBackButton2; // back button2 in contacts page
extern Texture2D CheckForSubjectButton; // check if any subject is being selected

// screens in different parts
extern Texture2D TestScreen; // screen when doing a test
extern Texture2D AboutScreen; // About page screen, with about button
extern Texture2D ContactsScreen; // Contacts screen
extern Texture2D MenuScreen; // Subject menu screen
extern Texture2D ResultsScreen; // result stats screen

//hover showing on different buttons
extern Texture2D EXIT; // exit button on hover
extern Texture2D ABOUT; // about button on hover
extern Texture2D RESULTS; // results button on hover
extern Texture2D START; // start new test button on hover
extern Texture2D DOTS; // dots decoration in result menu, if there are no results yet

extern Texture2D SUBJECTSTART; // start subject test button on hover
extern Texture2D CONTACTS; // contacts button on hover
extern Texture2D BACKONTEST; // back button in test mode
extern Texture2D NEXTONTEST; // next button in tests
extern Texture2D BACKONRESULT; // back button in percentage show

extern Texture2D A; // a) option in tests
extern Texture2D B; // b) option in tests
extern Texture2D C; // c) option in tests
extern Texture2D D; // d) option in tests
void Load();
void Unload();

