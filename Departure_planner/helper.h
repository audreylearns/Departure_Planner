#pragma once
/*================================================================================================================================
Owner: Audrey Duzon
GitHub: https://github.com/audreylearns
Release Verssion: 1 - 09/15/2023

Hi there!
Thank you for viewing my first project in C language.
This was developed after semester 1 of studies.
Further development was made after semester 2&3.


==================================================================================================================================*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#define maxHr 23
#define maxHrDeduct 12
#define maxMin 59
#define minE 60

#define basePrepT 30

struct inputData {
	int arvH, arvM, trvH, trvM, bufH, bufM, prpH, prpM, meaH, meaM;
};


//arg1 = H, arg2 = M
void inputTimeVal(int* hrVal, int* minVal);

//arg read only, DISPLAY OUTPUT of calculated data: prep, meal and departure time
void timeToStart(const struct inputData variables);

//arg pass by address, checks if min val greater than 60; returns new val
void minGreaterThan60(int* hVal, int* mVal);

//deduct timeA to timeB, return by address via arg 3&4
void timeADeductTimeB(int aHr, int aMin, int bHr, int bMin, int* valH, int* valM);

//validate h input, returns 1 if hour input valid
int validateHour(const int hr);

//validate min input, returns 1 if minutes input valid
int validateMin(const int min);

//validate confirmation input, LOOP until input valid, INPUT is not case sensitive
//returns y or n by address
void validateConfirmation(char *);

//clear buffer
void clear(void);

//TESTER version
void validateConfirmation_T(char*);

//accepts only 12h deduction from arival time
int maxTimeValidate(int aHr);

//output Heather
void header(void);

//outputHeather
void footer(void);