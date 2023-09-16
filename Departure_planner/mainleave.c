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

int main() {
	//int arvH, arvM, trvH, trvM, bufH, bufM, prpH, prpM, meaH, meaM;
	struct inputData time = { 0,0,0,0,0,0,0,0,0,0 };
	char selection;
	header();
	printf("*** Enter time in hh:mm format only ***\n");
	printf("---------------------------------------------------------\n");
	printf("Arrival time");
	inputTimeVal(&time.arvH, &time.arvM);
	printf("---------------------------------------------------------\n\n");
	printf("Travel time");
	inputTimeVal(&time.trvH, &time.trvM);

	printf("Enter buffer time");
	inputTimeVal(&time.bufH, &time.bufM);

	printf("_________________________________________________________\n");
	printf("Do you need prep time longer than %i mins? (y || n) = ", basePrepT);
	validateConfirmation(&selection);
	if (selection == 'y') {
		printf("Prep time");
		inputTimeVal(&time.prpH, &time.prpM);
	}
	else {
		time.prpH = 0;
		time.prpM = basePrepT;
	}
	printf("_________________________________________________________\n");
	printf("\nDo you need meal time before leaving? (y || n) = ");
	validateConfirmation(&selection);
	if (selection == 'y') {
		printf("Meal time = ");
		inputTimeVal(&time.meaH, &time.meaM);
	}
	else {
		time.meaH = 0;
		time.meaM = 0;
	}
	printf("\n=========================================================\n");
	timeToStart(time);
	footer();
	return 0;
}



