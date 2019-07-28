#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "valIP.h"

int ValidateIp(char * input)
{
	const int minNumOfDigits = 7;
	const int maxNumOfDigits = 15;
	const char dot = '.';
	char * segment[4] = {NULL, NULL, NULL, NULL};
	char inBuffer[maxNumOfDigits];
	int dotCnt = 0;
	int segLen = 0;
	int nSeg = 0;
	int inLen = 0;
	int ii = 0;
	int jj = 0;

	memset(inBuffer, 0, sizeof(inBuffer));

	//input error control
	if(inBuffer == NULL)
	{
		VALIPTRACE("Error: Uninitialized input\n");
		return IP_ERROR;
	}

	inLen = strlen(input);

	//check valid length
	if(inLen < minNumOfDigits || inLen > maxNumOfDigits)
	{
		VALIPTRACE("Not valid IP - wrong length(%d)\n", inLen);
		return IP_NOT_VALID;
	}
	strcpy(inBuffer, input);

	//check numeric input and dot count
	while(inBuffer[ii] != '\0')
	{
		if(inBuffer[ii] == dot)
		{
			dotCnt++;
			ii++;
		}
		else if( inBuffer[ii] >= '0' && inBuffer [ii] <= '9')
		{
			ii++;
		}
		else
		{
			VALIPTRACE("Not valid IP - non numeric character (%c)\n", inBuffer[ii]);
			return IP_NOT_VALID;
		}
	}

	//count correct number of dots
	if(dotCnt != 3)
	{
		VALIPTRACE("Not valid IP - wrong number of dots (%d)\n",dotCnt);
		return IP_NOT_VALID;
	}

	//separate address segments
	segment[jj] = inBuffer;
	for(ii = 0; ii< inLen; ii++)
	{
		if(inBuffer[ii] == dot)
		{
			jj++;
			segment[jj] = &inBuffer[ii+1];
			inBuffer[ii] = 0;	//separate strings with terminators
		}
	}

	//validate segments
	for(ii = 0; ii < (sizeof(segment)/(sizeof(segment[0]))); ii++)
	{
		//segment length
		segLen = strlen(segment[ii]);
		if(segLen < 1 || segLen >3)
		{
			VALIPTRACE("Not valid IP - wrong segment length (%d : %s)\n",segLen, segment[ii]);
			return IP_NOT_VALID;
		}

		//segment content
		nSeg = atoi(segment[ii]);
		if(nSeg <0 || nSeg >255)
		{
			VALIPTRACE("Not valid IP - wrong IP segment (%d)\n", nSeg);
			return IP_NOT_VALID;
		}
	}
	VALIPTRACE("VALID IP (%d.%d.%d.%d)\n",
						atoi(segment[0]),
						atoi(segment[1]),
						atoi(segment[2]),
						atoi(segment[3]));
	return IP_VALID;
}
