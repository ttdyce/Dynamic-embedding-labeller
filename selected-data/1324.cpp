#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//**********?????????*********************
//**********???????*************************
//**********?????2012?11?27?***************
//**********???1200062701**********************

Intercept<int> ifsushu(Intercept<int> n) //????????????1???
{
	Intercept<int> intercepts[] = {Intercept<int>(n - 1, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	if (n == 1)
	{
		return 1;
	}
	else
	{
		for (state[0] = Intercept<int>(n - 1, 2); state[0] >= 2; state[0]--) //??n?????
		{
			if (n % state[0] == 0)
				break;
			if (state[0] == 2)
			{
				return 1;
			}
		}
	}
	return 0;
}
// Intercept<int> sum(0, 3);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
StateIntercept gState(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

Intercept<int> zhaoyinshu(Intercept<int> x, Intercept<int> max)
{
	if (x == 1)
	{
		gState[0]++;
		return 0;
	}
	for (gState[1] = Intercept<int>(max, 2); gState[1] >= 2; gState[1]--)
	{
		if (x % gState[1] == 0) // ??gState[1]?????
		{
			zhaoyinshu(x / gState[1], gState[1]);
		}
	}

	return 1;
}
int main()
{
	// Intercept<int> time, number, t;
	cin >> gState[4];
	for (gState[2] = Intercept<int>(0, 2); gState[2] < gState[4]; gState[2]++)
	{
		cin >> gState[5];
		if (ifsushu(gState[5]) == 1)
		{
			cout << "1" << endl;
		}
		else
		{
			zhaoyinshu(gState[5], gState[5] / 2);
			cout << gState[0] + 1 << endl; //????????????~
			gState[0] = 0;
		}
	}
	return 0;
}
