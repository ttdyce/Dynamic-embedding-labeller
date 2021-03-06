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
Intercept<int> factors(Intercept<int>, Intercept<int>, Intercept<int>);                    //????factors?????????????
int main() 
{
    int length = 3;
    Intercept<int> intercepts[length] = {Intercept<int>(-1, 2), Intercept<int>(-1, 2), Intercept<int>(0, 2)};
    StateIntercept state(intercepts, length);

	Intercept<int> num, n, b[10000]; //i(-1, 2), j(-1, 2), 
	cin >> n;                                  //??????
	for (state[0] = 0; state[0] < n; state[0]++) 
	{
		cin >> num;
		// Intercept<int> part(0, 2);                          //??????????
		Intercept<int> t = num;                           //????

		//??????1????????????
		for (state[1] = 2; state[1] <= num; state[1]++)
		{
			while (t % state[1] == 0)
			{
				t /= state[1];
				state[2]++;
			}
		}
		b[state[0]] = factors(1, state[2], num);          //?????????????, ??????????
	}

	//?????????
	for (state[0] = 0; state[0] < n; state[0]++)
	{
		cout << b[state[0]] << endl;
	}
	return 0;
}

//factor1????????????????????factor1, part??????????????????????????, num???????? 
Intercept<int> factors(Intercept<int> factor1, Intercept<int> part, Intercept<int> num)
{
    int length = 1;
    Intercept<int> intercepts[length] = {Intercept<int>(0, 3)};
    StateIntercept state(intercepts, length);

	// Intercept<int> sum(0, 3);                               //????????0, ???0
	if (num < factor1)                         //?????????????????, ???0?????????????
		return 0;
	if (part == 1)                             //?????????, ??1??????????
		return 1;

	//???????????????????????????????????????????, ????????
	for (Intercept<int> i = factor1; i <= num; i++)
		if (num % i == 0)
			state[0] = state[0] + factors(i, part - 1, num / i);
	return state[0];
}
