// Adventofcode_day1-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //input/output
#include <cmath> // for power function

int main()
{
	int runningTotal(0); //final sum
	int lastDig(0); // for checking against
	int digit; // temp variable to hold one number
	int firstDig; // for number wrap
	bool isFirstDig(true); //there should only be one first digit
	int numLength(0); //length
	double digitOne; //input
	std::cin >> digitOne;
	double digitOneMirror(digitOne); // for finding legnth with
	do // find number's length
	{
		digitOneMirror /= 10;
		++numLength;
	} while (digitOneMirror>1);
		while(numLength>0)
		{
			digit = trunc(digitOne / pow(10, numLength-1)); //isolate the current highest digit
			digitOne -= (digit * pow(10,numLength-1)); // delete the highest digit from the base
				if (isFirstDig && digit!=0) //the first digit can't be zero
				{
					firstDig = digit;
					isFirstDig = false; 
				}
				if (lastDig == digit)
				{		
					runningTotal += digit;
				}
			lastDig = digit; 
			--numLength; //for loop
		}
		if (digit == firstDig) // check to see if last digit meets first
		{
			runningTotal += digit;
		}
		std::cout << runningTotal << '\n';
    return 0;
}

