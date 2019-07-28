#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "valIP.h"

char * testStrings[] =
{
		"fubar",
		"foobarfoo",
		"www.fubar.com.we",
		"www.foo.bar.uk",
		"www.fubar.com",
		"1.1.1.1.1",
		"1.1.1.1",
		"1.10..1",
		"1.1.1.1111",
		"1.a.1.1",
		"1a.1.1.1",
		"255.255.255.255",
		"255.255.256.255",
		"255.255.2556.255",
		"001.100.111.010",
		"192.168.1.1",
		"..."
};

void runtests(void)
{
	int ii = 0;
	int ret = 0;

	for(ii = 0; ii< sizeof(testStrings)/(sizeof(testStrings[0])); ii++)
	{
		VALIPTRACE("\n\nTEST # %03d\t\t\t(%s)\n---------------\n", ii, testStrings[ii]);
		ret = ValidateIp(testStrings[ii]);
		VALIPTRACE("-----------------\nEND OF TEST # %03d = %s\n\n\n\n", ii, (ret == 1)?"\t--\t--\tSUCCESS":"\t-\tFAILURE");
	}
}

