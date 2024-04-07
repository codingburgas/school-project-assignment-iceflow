#include "../include/TestMode.h"
#include "raylib.h"
#include "../include/Textures.h"
#include <stdlib.h>
using namespace std;
#include <time.h>
#include "../include/Questions.h"
#pragma warning(disable : 6385) // warning invalid data is read in Answers arrays, because we are using a random index to access data but that's safe

int ResultMath = 0, ResultGeography = 0, ResultEnglish = 0;
int LastResultMath = 0, LastResultGeography = 0, LastResultEnglish = 0; // store last results for the result panel in the start menu

static int i = rand() % 50 + 1; // random question chooser
static int CurrentQuestion[3] = {}; // counter for how many question you have answered
void Math()
{
	srand(time(0));

	if (MathON)
	{
		
		DrawTexture(TestScreen, 0, 0, RAYWHITE); // test screen draw
		DrawTexture(BACKONTEST, 68, 630, RAYWHITE); // draw back button
		DrawTexture(NEXTONTEST, 1070, 620, RAYWHITE); // draw next button
		bool HoverBack = CheckCollisionPointRec(GetMousePosition(), { 68,630,(float)BACKONTEST.width,(float)BACKONTEST.height }); // back button 
		bool HoverNext = CheckCollisionPointRec(GetMousePosition(), { 1070,620,(float)NEXTONTEST.width,(float)NEXTONTEST.height }); // next button

		if (HoverBack && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			MathON = false; // if clicked the test screenis closed
			CurrentQuestion[0] = 0; // reset the test if back is clicked		
		}

		if (HoverNext)
		{
			DrawTexture(NEXTONTEST, 1070, 620, YELLOW); // draw next button on hover
		}
		if (HoverNext && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			i = rand() % 50 + 1; // change the question, by giving another value to i
			// CurrentQuestion++; // incrementing the counter for the total questions completed
		}

		if (CurrentQuestion[0] <= 20) // while doing the exam
		{
			DrawText(QuestionsMath[i], 276, 90, 35, BLACK); // show the question the user needs to answer

			DrawText(AnswersMath[i - 1][0].c_str(), 450, 204, 50, BLACK);// answer a
			DrawText(AnswersMath[i - 1][1].c_str(), 450, 325, 50, BLACK); // answer b
			DrawText(AnswersMath[i - 1][2].c_str(), 450, 432, 50, BLACK); // answer c
			DrawText(AnswersMath[i - 1][3].c_str(), 450, 550, 50, BLACK); // answer d

			DrawTexture(A, 294, 174, RAYWHITE); // a option button
			DrawTexture(B, 290, 290, RAYWHITE); // b option button
			DrawTexture(C, 290, 400, RAYWHITE); // c option button
			DrawTexture(D, 294, 514, RAYWHITE); // d option button

			bool HoverABCD[4] = {
				CheckCollisionPointRec(GetMousePosition(), { 294,174,(float)A.width,(float)A.height }),
				CheckCollisionPointRec(GetMousePosition(), { 290,290,(float)B.width,(float)B.height }),
				CheckCollisionPointRec(GetMousePosition(), { 290,400,(float)C.width,(float)C.height }),
				CheckCollisionPointRec(GetMousePosition(), { 294,514,(float)D.width,(float)D.height }),
			};
			if (HoverABCD[0])
			{
				DrawTexture(A, 294, 174, YELLOW); // a option button on hover
			}
			if (HoverABCD[1])
			{
				DrawTexture(B, 290, 290, YELLOW); // b option button on hover
			}
			if (HoverABCD[2])
			{
				DrawTexture(C, 290, 400, YELLOW); // c option button on hover
			}
			if (HoverABCD[3])
			{
				DrawTexture(D, 294, 514, YELLOW); // D option button on hover
			}

			if (HoverABCD[0] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // a option pressed (chosen), same for other
			{
				if (i == 24 or i == 32 or i == 35 or i == 37 or i == 46)
					ResultMath++;

				i = rand() % 50 + 1;
				CurrentQuestion[0]++;
				
			}
			if (HoverABCD[1] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				if( i == 1 or i == 2 or i == 3 or i ==4 or i == 6 or i == 7 or i == 9 or i == 11 or i == 12 or i == 14 or i == 18 or i == 20 or i == 27 or i == 31 or i == 38 or i == 43 or i == 45 or i == 47 or i == 48  )
					ResultMath++;

				i = rand() % 50 + 1;
				CurrentQuestion[0]++;
			}
			if (HoverABCD[2] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				if( i == 5 or i == 8 or i == 10 or i == 13 or i == 16 or i == 21 or i == 22 or i == 25 or i == 28 or i == 30 or i == 33 or i == 34 or i == 36 or i == 40 or i == 41 or i == 49 or i == 50)
					ResultMath++;

				i = rand() % 50 + 1;
				CurrentQuestion[0]++;
			}
			if (HoverABCD[3] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				///////check if ite answer is correct///////////////// for D
				if (i == 15 or i == 17 or i == 19 or i == 23 or i == 26 or i == 29 or i == 39 or i == 42 or i == 44)
					ResultMath++;

				i = rand() % 50 + 1;
				CurrentQuestion[0]++;
			}

		}
		else if (CurrentQuestion[0] == 21)
		{
			DrawText("         Your result is: ", 284, 90, 50, BLACK);  //  show the final result
			string percentage = "         " + to_string(int((double)ResultMath / 20 * 100)) + "%";
			DrawText(percentage.c_str(), -110, 190, 170, BLACK); // percentage score

			DrawTexture(BACKONRESULT, 580, 390, RAYWHITE); // back button to return to the test
			bool HoverBackOnResult = CheckCollisionPointRec(GetMousePosition(), { 580,390,(float)BACKONRESULT.width,(float)BACKONRESULT.height });

			if (HoverBackOnResult && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				MathON = false;
				CurrentQuestion[0] = 0; // return to the subject menu if you're done and reset the test
				
			}
			if (HoverBackOnResult)
			{
				DrawTexture(BACKONRESULT, 580, 390, YELLOW); // back button to return to the test on hover
			}

			LastResultMath = int((double)ResultMath / 20 * 100); // last result
			
		}
		else
		{
			MathON = false; // return to the subject menu if the user has finished and he is spamming the next button
			CurrentQuestion[0] = 0; // reset the test if it is finished and let the user start it again from the subject menu
			LastResultMath = int((double)ResultMath / 20 * 100); // last result store
			
		}
		

	}
	else
	{
		ResultMath = 0;
	}
		
}

void Geography()
{
 	srand(time(0));
	int QuestionNumber = rand() % 50 + 1;
	if (GeographyON)
	{
			DrawTexture(TestScreen, 0, 0, RAYWHITE); // test screen draw
			DrawTexture(BACKONTEST, 68, 630, RAYWHITE); // draw back button
			DrawTexture(NEXTONTEST, 1070, 620, RAYWHITE); // draw next button
			bool HoverBack = CheckCollisionPointRec(GetMousePosition(), { 68,630,(float)BACKONTEST.width,(float)BACKONTEST.height }); // back button 
			bool HoverNext = CheckCollisionPointRec(GetMousePosition(), { 1070,620,(float)NEXTONTEST.width,(float)NEXTONTEST.height }); // next button

			if (HoverBack && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				GeographyON = false; // if clicked the test screenis closed
				CurrentQuestion[1] = 0; // reset the test if back is clicked		
			}

			if (HoverNext)
			{
				DrawTexture(NEXTONTEST, 1070, 620, YELLOW); // draw next button on hover
			}
			if (HoverNext && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				i = rand() % 50 + 1; // change the question, by giving another value to i
				// CurrentQuestion++; // incrementing the counter for the total questions completed
			}

			if (CurrentQuestion[1] <= 20) // while doing the exam
			{
				DrawText(QuestionsGeography[i], 276, 90, 35, BLACK); // show the question the user needs to answer

				DrawText(AnswersGeography[i - 1][0].c_str(), 450, 204, 50, BLACK);// answer a
				DrawText(AnswersGeography[i - 1][1].c_str(), 450, 325, 50, BLACK); // answer b
				DrawText(AnswersGeography[i - 1][2].c_str(), 450, 432, 50, BLACK); // answer c
				DrawText(AnswersGeography[i - 1][3].c_str(), 450, 550, 50, BLACK); // answer d

				DrawTexture(A, 294, 174, RAYWHITE); // a option button
				DrawTexture(B, 290, 290, RAYWHITE); // b option button
				DrawTexture(C, 290, 400, RAYWHITE); // c option button
				DrawTexture(D, 294, 514, RAYWHITE); // d option button

				bool HoverABCD[4] = {
					CheckCollisionPointRec(GetMousePosition(), { 294,174,(float)A.width,(float)A.height }),
					CheckCollisionPointRec(GetMousePosition(), { 290,290,(float)B.width,(float)B.height }),
					CheckCollisionPointRec(GetMousePosition(), { 290,400,(float)C.width,(float)C.height }),
					CheckCollisionPointRec(GetMousePosition(), { 294,514,(float)D.width,(float)D.height }),
				};
				if (HoverABCD[0])
				{
					DrawTexture(A, 294, 174, YELLOW); // a option button on hover
				}
				if (HoverABCD[1])
				{
					DrawTexture(B, 290, 290, YELLOW); // b option button on hover
				}
				if (HoverABCD[2])
				{
					DrawTexture(C, 290, 400, YELLOW); // c option button on hover
				}
				if (HoverABCD[3])
				{
					DrawTexture(D, 294, 514, YELLOW); // D option button on hover
				}

				if (HoverABCD[0] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // a option pressed (chosen), same for other
				{
					if (i == 3 or i == 9 or i == 10 or i == 12 or i == 14 or i == 15 or i == 16 or i == 19 or i == 20 or i == 22 or i == 24 or i == 25 or i == 26 or i == 27 or i == 28 or i == 31 or i == 32 or i == 34 or i == 35 or i == 36 or i == 38 or i == 39 or i == 40 or i == 41 or i == 43 or i == 45 or i == 46 or i == 47 or i == 48 or i == 50)
						ResultGeography++;

					i = rand() % 50 + 1;
					CurrentQuestion[1]++;

				}
				if (HoverABCD[1] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // b option
				{
					if (i == 2 or i == 4 or i == 5 or i == 7 or i == 11 or i == 13 or i == 17 or i == 18 or i == 21 or i == 29 or i == 33 or i == 37 or i == 44 or i == 49)
						ResultGeography++;

					i = rand() % 50 + 1;
					CurrentQuestion[1]++;
				}
				if (HoverABCD[2] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					if (i == 1 or i == 6 or i == 8 or i == 23 or i == 42)
						ResultGeography++;

					i = rand() % 50 + 1;
					CurrentQuestion[1]++;
				}
				if (HoverABCD[3] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					///////check if ite answer is correct///////////////// for D
					if (i == 30)
						ResultGeography++;

					i = rand() % 50 + 1;
					CurrentQuestion[1]++;
				}

			}
			else if (CurrentQuestion[1] == 21)
			{
				DrawText("         Your result is: ", 284, 90, 50, BLACK);  //  show the final result
				string percentage = "         " + to_string(int((double)ResultGeography / 20 * 100)) + "%";
				DrawText(percentage.c_str(), -110, 190, 170, BLACK); // percentage score

				DrawTexture(BACKONRESULT, 580, 390, RAYWHITE); // back button to return to the test
				bool HoverBackOnResult = CheckCollisionPointRec(GetMousePosition(), { 580,390,(float)BACKONRESULT.width,(float)BACKONRESULT.height });

				if (HoverBackOnResult && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					GeographyON = false;
					CurrentQuestion[1] = 0; // return to the subject menu if you're done and reset the test

				}
				if (HoverBackOnResult)
				{
					DrawTexture(BACKONRESULT, 580, 390, YELLOW); // back button to return to the test on hover
				}
				//back button
				//////////// result stats finish
				LastResultGeography = int((double)ResultGeography / 20 * 100); // last result

			}
			else
			{
				GeographyON = false; // return to the subject menu if the user has finished and he is spamming the next button
				CurrentQuestion[1] = 0; // reset the test if it is finished and let the user start it again from the subject menu
				LastResultGeography = int((double)ResultGeography / 20 * 100); // last result store

			}

	}
	else
	{
	ResultGeography = 0;
	}
}

void English()
{
	srand(time(0));
	int QuestionNumber = rand() % 50 + 1;
	if (EnglishON)
	{
		
		DrawTexture(TestScreen, 0, 0, RAYWHITE); // test screen draw
		DrawTexture(BACKONTEST, 68, 630, RAYWHITE); // draw back button
		DrawTexture(NEXTONTEST, 1070, 620, RAYWHITE); // draw next button
		bool HoverBack = CheckCollisionPointRec(GetMousePosition(), { 68,630,(float)BACKONTEST.width,(float)BACKONTEST.height }); // back button 
		bool HoverNext = CheckCollisionPointRec(GetMousePosition(), { 1070,620,(float)NEXTONTEST.width,(float)NEXTONTEST.height }); // next button

		if (HoverBack && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			EnglishON = false; // if clicked the test screenis closed
			CurrentQuestion[2] = 0; // reset the test if back is clicked		
		}

		if (HoverNext)
		{
			DrawTexture(NEXTONTEST, 1070, 620, YELLOW); // draw next button on hover
		}
		if (HoverNext && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			i = rand() % 50 + 1; // change the question, by giving another value to i
			// CurrentQuestion++; // incrementing the counter for the total questions completed
		}

		if (CurrentQuestion[2] <= 20) // while doing the exam
		{
			DrawText(QuestionsEnglish[i], 276, 90, 35, BLACK); // show the question the user needs to answer

			DrawText(AnswersEnglish[i - 1][0].c_str(), 450, 204, 50, BLACK);// answer a
			DrawText(AnswersEnglish[i - 1][1].c_str(), 450, 325, 50, BLACK); // answer b
			DrawText(AnswersEnglish[i - 1][2].c_str(), 450, 432, 50, BLACK); // answer c
			DrawText(AnswersEnglish[i - 1][3].c_str(), 450, 550, 50, BLACK); // answer d

			DrawTexture(A, 294, 174, RAYWHITE); // a option button
			DrawTexture(B, 290, 290, RAYWHITE); // b option button
			DrawTexture(C, 290, 400, RAYWHITE); // c option button
			DrawTexture(D, 294, 514, RAYWHITE); // d option button

			bool HoverABCD[4] = {
				CheckCollisionPointRec(GetMousePosition(), { 294,174,(float)A.width,(float)A.height }),
				CheckCollisionPointRec(GetMousePosition(), { 290,290,(float)B.width,(float)B.height }),
				CheckCollisionPointRec(GetMousePosition(), { 290,400,(float)C.width,(float)C.height }),
				CheckCollisionPointRec(GetMousePosition(), { 294,514,(float)D.width,(float)D.height }),
			};
			if (HoverABCD[0])
			{
				DrawTexture(A, 294, 174, YELLOW); // a option button on hover
			}
			if (HoverABCD[1])
			{
				DrawTexture(B, 290, 290, YELLOW); // b option button on hover
			}
			if (HoverABCD[2])
			{
				DrawTexture(C, 290, 400, YELLOW); // c option button on hover
			}
			if (HoverABCD[3])
			{
				DrawTexture(D, 294, 514, YELLOW); // D option button on hover
			}

			if (HoverABCD[0] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // a option pressed (chosen), same for other
			{
				if (i == 3 or i == 9 or i == 10 or i == 12 or i == 14 or i == 15 or i == 16 or i == 19 or i == 20 or i == 22 or i == 24 or i == 25 or i == 26 or i == 27 or i == 28 or i == 31 or i == 32 or i == 34 or i == 35 or i == 36 or i == 38 or i == 39 or i == 40 or i == 41 or i == 43 or i == 45 or i == 46 or i == 47 or i == 48 or i == 50)
					ResultEnglish++;

				i = rand() % 50 + 1;
				CurrentQuestion[2]++;

			}
			if (HoverABCD[1] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // b option
			{
				if (i == 2 or i == 4 or i == 5 or i == 7 or i == 11 or i == 13 or i == 17 or i == 18 or i == 21 or i == 29 or i == 33 or i == 37 or i == 44 or i == 49)
					ResultEnglish++;

				i = rand() % 50 + 1;
				CurrentQuestion[2]++;
			}
			if (HoverABCD[2] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				if (i == 1 or i == 6 or i == 8 or i == 23 or i == 42)
					ResultEnglish++;

				i = rand() % 50 + 1;
				CurrentQuestion[2]++;
			}
			if (HoverABCD[3] && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				///////check if ite answer is correct///////////////// for D
				if (i == 30)
					ResultEnglish++;

				i = rand() % 50 + 1;
				CurrentQuestion[2]++;
			}

		}
		else if (CurrentQuestion[2] == 21)
		{
			DrawText("         Your result is: ", 284, 90, 50, BLACK);  //  show the final result
			string percentage = "         " + to_string(int((double)ResultEnglish / 20 * 100)) + "%";
			DrawText(percentage.c_str(), -110, 190, 170, BLACK); // percentage score

			DrawTexture(BACKONRESULT, 580, 390, RAYWHITE); // back button to return to the test
			bool HoverBackOnResult = CheckCollisionPointRec(GetMousePosition(), { 580,390,(float)BACKONRESULT.width,(float)BACKONRESULT.height });

			if (HoverBackOnResult && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				EnglishON = false;
				CurrentQuestion[2] = 0; // return to the subject menu if you're done and reset the test

			}
			if (HoverBackOnResult)
			{
				DrawTexture(BACKONRESULT, 580, 390, YELLOW); // back button to return to the test on hover
			}
			//back button
			//////////// result stats finish
			LastResultEnglish = int((double)ResultEnglish / 20 * 100); // last result

		}
		else
		{
			EnglishON = false; // return to the subject menu if the user has finished and he is spamming the next button
			CurrentQuestion[2] = 0; // reset the test if it is finished and let the user start it again from the subject menu
			LastResultEnglish = int((double)ResultEnglish / 20 * 100); // last result store

		}


	}
	else
	{
		ResultEnglish = 0;
	}
}