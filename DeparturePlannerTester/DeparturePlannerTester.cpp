/*================================================================================================================================
Owner: Audrey Duzon
GitHub: https://github.com/audreylearns
Release Verssion: 1 - 09/15/2023

Hi there!
Thank you for viewing my first project in C language.
This was developed after semester 1 of studies.
Further development was made after semester 2&3.


==================================================================================================================================*/

#include "pch.h"
#include "CppUnitTest.h"
#include "helper_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#define MSG(msg) [&]{ std::wstringstream _s; _s << msg; return _s.str(); }().c_str()

namespace DeparturePlannerTester
{
	TEST_CLASS(validateInputBlackBox)
	{
	public:
		//BLACK BOX 
		//Purpose: Tests of validation function

		//FUNCTION 1: int validateHour(const int hr)
		TEST_METHOD(validateHour_max)
		{
			int input = 23;
			bool actualRes = validateHour(input);
			bool expectedRes = true;
			Assert::AreEqual(expectedRes, actualRes);
		
		}
		TEST_METHOD(validateHour_min)
		{
			int input = 0;
			bool actualRes = validateHour(input);
			bool expectedRes = true;
			Assert::AreEqual(expectedRes, actualRes);

		}
		TEST_METHOD(validateHour_outOfBounds_neg)
		{
			int input = 90;
			bool actualRes = validateHour(input);
			bool expectedRes = false;
			Assert::AreEqual(expectedRes, actualRes);
		}
		TEST_METHOD(validateHour_outOfBounds_pos)
		{
			int input = -90;
			bool actualRes = validateHour(input);
			bool expectedRes = false;
			Assert::AreEqual(expectedRes, actualRes);
		}
		TEST_METHOD(validateHour_specialValue)
		{
			int input = NULL;
			bool actualRes = validateHour(input);
			bool expectedRes = true;
			Assert::AreEqual(expectedRes, actualRes);
		}

		//==========================================
		//FUNCTION 2: int validateMin(const int min)
		TEST_METHOD(validateMin_max)
		{
			int input = 59;
			bool actualRes = validateMin(input);
			bool expectedRes = true;
			Assert::AreEqual(expectedRes, actualRes);

		}
		TEST_METHOD(validateMin_min)
		{
			int input = 0;
			bool actualRes = validateMin(input);
			bool expectedRes = true;
			Assert::AreEqual(expectedRes, actualRes);

		}
		TEST_METHOD(validateMin_outOfBounds_neg)
		{
			int input = 90;
			bool actualRes = validateMin(input);
			bool expectedRes = false;
			Assert::AreEqual(expectedRes, actualRes);
		}
		TEST_METHOD(validateMin_outOfBounds_pos)
		{
			int input = -90;
			bool actualRes = validateMin(input);
			bool expectedRes = false;
			Assert::AreEqual(expectedRes, actualRes);
		}
		TEST_METHOD(validateMin_specialValue)
		{
			int input = NULL;
			bool actualRes = validateMin(input);
			bool expectedRes = true;
			Assert::AreEqual(expectedRes, actualRes);
		}

		//==========================================
		//FUNCTION 3: void validateConfirmation(char *);
		TEST_METHOD(validateConfirmation_max)
		{
			char input = 'y';
			validateConfirmation_T(&input);
			char expectedRes = 'y';
			char actualRes = 'y';
			Assert::AreEqual(expectedRes, actualRes);

		}
		TEST_METHOD(validateConfirmation_min)
		{
			char input = 'n';
			validateConfirmation_T(&input);
			char expectedRes = 'n';
			char actualRes = 'n';
			Assert::AreEqual(expectedRes, actualRes);

		}
		TEST_METHOD(validateConfirmation_casesensitive)
		{
			char input = 'N';
			validateConfirmation_T(&input);
			char expectedRes = 'n';
			char actualRes = 'n';
			Assert::AreEqual(expectedRes, actualRes);
		}
		TEST_METHOD(validateConfirmation_specialValue1)
		{
			char input = NULL;
			validateConfirmation_T(&input);
			char expectedRes = '\0';
			char actualRes = '\0';
			Assert::AreEqual(expectedRes, actualRes);
		}
		TEST_METHOD(validateConfirmation_specialValue2)
		{
			char input = 'yes';
			validateConfirmation_T(&input);
			char expectedRes = 'y';
			char actualRes = 'y';
			Assert::AreEqual(expectedRes, actualRes);
		}
	};

	//BLACK BOX TEST
	//Purpose: calculated return correct
	TEST_CLASS(time_CalculationTest) {
	public:
		TEST_METHOD(timeADeductTimeB_hour)
		{
			bool equal{ false };
			int inputH = 10, inputM = 0; //10:00
			int inputSubH = 1, inputSubM = 0; //1 hour deduction

			int expectedRes[2]{ 9,0 }; //9:00
			int actualRes[2]{}; //start w 0 to ensure pass by address 

			timeADeductTimeB(inputH, inputM, inputSubH, inputSubM, &actualRes[0], &actualRes[1]);
			
			expectedRes[0] == actualRes[0] && expectedRes[1] == actualRes[1] ? equal = true : equal = false;

			Assert::AreEqual(true, equal);
		}
		TEST_METHOD(timeADeductTimeB_min)
		{
			int inputH = 10, inputM = 0; //10:00
			int inputSubH = 0, inputSubM = 1; //1 min deduction

			int expectedRes[2]{ 9,59 }; //9:59
			int actualRes[2]{}; //start w 0 to ensure pass by address 

			timeADeductTimeB(inputH, inputM, inputSubH, inputSubM, &actualRes[0], &actualRes[1]);
			bool equal;
			expectedRes[0] == actualRes[0] && expectedRes[1] == actualRes[1] ? equal = true : equal = false;

			Assert::AreEqual(true, equal);
		}
		
		TEST_METHOD(timeADeductTimeB_HM)
		{
			int inputH = 10, inputM = 0; //10:00
			int inputSubH = 1, inputSubM = 30; //1 h 30 min deduction

			int expectedRes[2]{ 8,30 }; //8:30
			int actualRes[2]{}; //start w 0 to ensure pass by address 

			timeADeductTimeB(inputH, inputM, inputSubH, inputSubM, &actualRes[0], &actualRes[1]);
			bool equal;
			expectedRes[0] == actualRes[0] && expectedRes[1] == actualRes[1] ? equal = true : equal = false;

			Assert::AreEqual(true, equal);
		}

		TEST_METHOD(timeADeductTimeB_H5M30)
		{
			int inputH = 10, inputM = 0; //10:00
			int inputSubH = 5, inputSubM = 30; //5 h 30 min deduction

			int expectedRes[2]{ 4,30 }; //4:30
			int actualRes[2]{}; //start w 0 to ensure pass by address 

			timeADeductTimeB(inputH, inputM, inputSubH, inputSubM, &actualRes[0], &actualRes[1]);
			bool equal;
			expectedRes[0] == actualRes[0] && expectedRes[1] == actualRes[1] ? equal = true : equal = false;

			Assert::AreEqual(true, equal);
		}
		TEST_METHOD(timeADeductTimeB_H0M59)
		{
			int inputH = 10, inputM = 0; //10:00
			int inputSubH = 0, inputSubM = 59; //0 h 59 min deduction

			int expectedRes[2]{ 9,1 }; //9:01
			int actualRes[2]{}; //start w 0 to ensure pass by address 

			timeADeductTimeB(inputH, inputM, inputSubH, inputSubM, &actualRes[0], &actualRes[1]);
			bool equal;
			expectedRes[0] == actualRes[0] && expectedRes[1] == actualRes[1] ? equal = true : equal = false;

			Assert::AreEqual(true, equal);
		}

		TEST_METHOD(timeADeductTimeB_equivalent)
		{
			int inputH = 10, inputM = 0; //10:00
			int inputSubH = 10, inputSubM = 0; //10 h 0 min deduction

			int expectedRes[2]{ 0,0 }; //0:00
			int actualRes[2]{}; //start w 0 to ensure pass by address 

			timeADeductTimeB(inputH, inputM, inputSubH, inputSubM, &actualRes[0], &actualRes[1]);
			bool equal;
			expectedRes[0] == actualRes[0] && expectedRes[1] == actualRes[1] ? equal = true : equal = false;

			Assert::AreEqual(true, equal);
		}
		TEST_METHOD(timeADeductTimeB_12hbefore)
		{
			int inputH = 15, inputM = 0; //15:00
			int inputSubH = 12, inputSubM = 0; //10 h 0 min deduction

			int expectedRes[2]{ 3,0 }; //3:00
			int actualRes[2]{}; //start w 0 to ensure pass by address 

			timeADeductTimeB(inputH, inputM, inputSubH, inputSubM, &actualRes[0], &actualRes[1]);
			bool equal;
			expectedRes[0] == actualRes[0] && expectedRes[1] == actualRes[1] ? equal = true : equal = false;

			Assert::AreEqual(true, equal);
		}
		TEST_METHOD(timeADeductTimeB_MAX)
		{
			int inputH = 15, inputM = 0; //15:00
			int inputSubH = 12, inputSubM = 59; //12 h 59 min deduction

			int expectedRes[2]{ 2,1 }; //2:01
			int actualRes[2]{}; //start w 0 to ensure pass by address 

			timeADeductTimeB(inputH, inputM, inputSubH, inputSubM, &actualRes[0], &actualRes[1]);
			bool equal;
			expectedRes[0] == actualRes[0] && expectedRes[1] == actualRes[1] ? equal = true : equal = false;

			Assert::AreEqual(true, equal);
		}

	};


	
}
