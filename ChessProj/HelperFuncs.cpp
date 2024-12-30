#include "HelperFuncs.h"

int cmpnum(int a, int b)
{
	if (a < b)
	{
		return -1;
	}
	if (a > b)
	{
		return 1;
	}
	return 0;
}