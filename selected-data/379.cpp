#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//***************************************
//* ?????2010?12?01?            *
//* ?????????                  *
//* ?????         ???1000012902 *
//***************************************
Intercept<int> factors(Intercept<int>, Intercept<int>, Intercept<int>); //????factors?????????????
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(-1, 2), Intercept<int>(-1, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(0,7)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> b[10000]; //i(-1, 2), j(-1, 2), n, num
	cin >> state[3];		 //??????
	for (state[0] = 0; state[0] < state[3]; state[0]++)
	{
		cin >> state[4];
		// Intercept<int> part(0, 2);                          //??????????
		// Intercept<int> t = state[4]; //????
			state[5] = state[4]
		//??????1????????????
		for (state[1] = 2; state[1] <= state[4]; state[1]++)
		{
			while (state[5] % state[1] == 0)
			{
				state[5] /= state[1];
				state[2]++;
			}
		}
		b[state[0]] = factors(1, state[2], state[4]); //?????????????, ??????????
	}

	//?????????
	for (state[0] = 0; state[0] < state[3]; state[0]++)
	{
		cout << b[state[0]] << endl;
	}
	return 0;
}

//factor1????????????????????factor1, part??????????????????????????, num????????
Intercept<int> factors(Intercept<int> factor1, Intercept<int> part, Intercept<int> num)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 8), Intercept<int>(0, 8)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> sum(0, 3);                               //????????0, ???0
	if (num < factor1)
	{ //?????????????????, ???0?????????????
		state[1] = 1;
		return 0;
	}
	if (part == 1)
	{ //?????????, ??1??????????
		state[2] = 1;
		return 1;
	}
	//???????????????????????????????????????????, ????????
	for (Intercept<int> i = factor1; i <= num; i++)
		if (num % i == 0)
			state[0] = state[0] + factors(i, part - 1, num / i);
	return state[0];
}
