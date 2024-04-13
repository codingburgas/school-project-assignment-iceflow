#include "../include/TimeShow.h"
#include "raylib.h"
#pragma warning(disable : 4996) // allows us to use localtime()

time_t Seconds = time(0); // store seconds since 1 jan 1970 in a time_t variable
tm* Calendar = localtime(&Seconds); // calculate the current year,day,minutes,second etc. and store it in a tm struct

void ShowDate()
{
    char Result[50];
    strftime(Result, sizeof(Result), "%a %b %d %Y", Calendar); // get the full day,year,second,hour,minutes in a char array, convert it from it

    DrawText(Result, 830, 30, 25, RED); // show current day , month, year
}
void ShowHour()
{
	
    time_t Seconds = time(0);
    tm* Calendar2 = localtime(&Seconds);

    char Result[9]; 
    strftime(Result, sizeof(Result), "%H:%M:%S", Calendar2);

    DrawText(Result, 1125, 28, 30, RED); // show hour,minutes and seconds

    while (GetTime() < 1) 
    {
        // wait 1 second,
    }
}
