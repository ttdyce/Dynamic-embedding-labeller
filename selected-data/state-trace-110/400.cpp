#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/****************************************
 * ????								*
 *										*
 *  Created on: 2010-12-8				*
 *      Author:??						*
 ***************************************/
Intercept<int> factor(int x, Intercept<int> y) //?????????factor
{
	int length = 2;
	Intercept<int> intercepts[length] = {Intercept<int>(2, 2), Intercept<int>(0, 3)};
	StateIntercept state(intercepts, length);

	// Intercept<int> i;
	for (state[0]; state[0] < x; state[0]++) //?????x?????
	{
		if (x % state[0] == 0)
		{
			break;
		}
	}
	if (state[0] == x)
	{
		return 1; //??x??????1
	}
	else //????????????
	{
		// Intercept<int> sum(0, 3);
		if (x == y) //?x?y?????y/x+1??????????????????????1???
		{
			for (state[0] = y / x + 1; state[0] <= sqrt(x); state[0]++) //?????????????????
			{
				if (x % state[0] == 0)
				{
					state[1] = state[1] + factor(x / state[0], x);
				}
				else
					continue;
			}
			return state[1] + 1; //????state[1]+1?????????a=a???
		}
		else
		{ //?x?y??????y/x?????????
			for (state[0] = y / x; state[0] <= sqrt(x); state[0]++)
			{
				if (x % state[0] == 0)
				{
					state[1] = state[1] + factor(x / state[0], x);
				}
				else
					continue;
			}
			return state[1] + 1; //????sum+1?????????a=a???
		}
	}
}
int main() //?????
{

	Intercept<int> n;
	cin >> n;

	int length = 2;
	Intercept<int> intercepts[length] = {Intercept<int>(n, 1), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, length);

	// const Intercept<int> m(n, 1);
	// int mInt = m;
	int idx = state[0];
	Intercept<int> a[idx]; //, j;
	for (state[1]; state[1] < n; state[1]++)
	{
		int idx2 = state[1];
		cin >> a[idx2]; //???????
	}
	for (state[1] = 0; state[1] < n; state[1]++)
	{
		int idx2 = state[1];
		cout << factor(a[idx2], a[idx2]) << endl; //??????
	}
	return 0;
}
