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

#include "helper.h"

//arg1 = H, arg2 = M
void inputTimeVal(int *hrVal, int* minVal) {

	int valid = 0;
	do {
		printf(" = ");
		scanf("%i:%i", hrVal, minVal);
		valid += validateHour(*hrVal);
		valid += validateMin(*minVal);
	} while (valid < 2);

}

//arg read only, displays wake, dress, eat and leave time
void timeToStart(const struct inputData variables) {
	int dressH = 0, dressM = 0, eatH = 0, eatM = 0, leaveH=0, leaveM=0;
	int tempH = 0, tempM = 0;

	if (variables.meaH == 0 && variables.meaM == 0) { //if skipping meal!
		//leavetime
		tempH = variables.trvH + variables.bufH;
		tempM = variables.trvM + variables.bufM; 
		minGreaterThan60(&tempH, &tempM); //check assign time, 0:40 
		timeADeductTimeB(variables.arvH, variables.arvM,tempH, tempM, &leaveH, &leaveM); //leavetime
  

		timeADeductTimeB(leaveH, leaveM, variables.prpH, variables.prpM, &dressH, &dressM);	//preptime

	}
	else { //if eating
		tempH = variables.trvH + variables.bufH;
		tempM = variables.trvM + variables.bufM;
		minGreaterThan60(&tempH, &tempM); //check assign time, 0:40 
		timeADeductTimeB(variables.arvH, variables.arvM, tempH, tempM, &leaveH, &leaveM); //leavetime
		timeADeductTimeB(leaveH, leaveM, variables.meaH, variables.meaM, &eatH, &eatM); //eattime
		timeADeductTimeB(eatH, eatM, variables.prpH, variables.prpM, &dressH, &dressM); //preptime

	}

	printf("\nStart getting ready by %02i:%02i\n", dressH, dressM);
	printf("*** Your prep time is %02i:%02i ***\n", variables.prpH, variables.prpM);
	if (variables.meaH != 0 || variables.meaM != 0) { //if eating before going out :)
		printf("Start your meal by %02i:%02i\n", eatH, eatM);
		printf("*** Your meal time is %02i:%02i ***\n", variables.meaH, variables.meaM);
	}
	printf("Leave by %02i:%02i\n", leaveH, leaveM);
}

//arg pass by address, checks if min val greater than 60; returns new val
void minGreaterThan60(int* hVal, int* mVal) {
	int tempMin;

	if (*mVal > minE) {
		*hVal += 1;
		tempMin = *mVal - minE; //70 - 60 = 10, new time 10 carry over 1 to h
		*mVal = tempMin;
	}

}

//deduct timeA to timeB, return by address via arg 3&4
void timeADeductTimeB(int aHr, int aMin, int bHr, int bMin, int *valH, int *valM) {
	int returnH, returnM, tempM;

	if (aMin < bMin) {
		returnH = aHr - 1; //borrow
		tempM = aMin + minE; //add 60
		returnM = tempM- bMin; //deduct 
		if (bHr != 0) {
			returnH -= bHr;
		}
	}
	else {
		returnM = aMin - bMin;
		returnH = aHr - bHr;
	}
	*valH = returnH;
	*valM = returnM;
}




//time subtraction link:
//https://www.youtube.com/watch?v=0nPuCgkc77E


//validate h input, returns 1 if hour input valid
int validateHour(const int hr) {
	static int countH = 0;
	countH++;

	if (countH == 1) { //only in first instance
		if (hr < 0 || hr > maxHr) {
			printf("Hours can only be between 0 - %d hours\n", maxHr);
			return 0;
		}
	}
	else {
		if (hr < 0 || hr > maxHrDeduct) {
			printf("Hours can only be between 0 - %d hours\n", maxHrDeduct);
			return 0;
		}
	}

	return 1;
}

//validate min input, returns 1 if minutes input valid
int validateMin(const int min) {
	if (min < 0 || min > maxMin) {
		printf("Minutes can only be between 0 - %d minutes\n", maxMin);
		return 0;
	}
	return 1;
}

//validate confirmation input, LOOP until input valid, INPUT is not case sensitive
//returns y or n by address
void validateConfirmation(char * rtn) {
	int valid = 0;
	while (valid == 0) {
		scanf(" %c", rtn);
		if (rtn[0] == 'Y' || rtn[0] == 'y') {
			*rtn = 'y';
			valid = 1;
		}
		else if (rtn[0] == 'N' || rtn[0] == 'n') {
			*rtn = 'n';
			valid = 1;
		}
		else {
			valid = 0;
		}
		clear();
	}

}

void validateConfirmation_T(char* rtn) {
	//while loop removed for assert check
	if (rtn[0] == 'Y' || rtn[0] == 'y') {
		*rtn = 'y';
		
	}
	else if (rtn[0] == 'N' || rtn[0] == 'n') {
		*rtn = 'n';
		
	}
	else {
		//reassign to null terminator (FAIL)
		*rtn = '\0';
	}


}

//clear buffer, exits when \n is returned by getchar
void clear(void) {
	while (getchar() != '\n') {
		;
	}
}


//output Heather
void header(void) {
	printf("=========================================================\n");
	printf("                    DEPARTURE PLANNER                    \n");
	printf("=========================================================\n\n");
}

//outputHeather
void footer(void) {
	printf("\n\n=========================================================\n");
	printf("                 THANK YOU & GOOD BYE!!!                 \n");
	printf("=========================================================\n");
}


/*==NEXT UPDATE: 
	User Input for postal code source and destination
	Instead of manually adding it here
	Get travel time from google maps
	Add option: Send link to user email ==*/