#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/*
 * hehe.cpp
 *
 *  Created on: 2012-11-25
 *      Author:??
 * ???????a?????????????????a = a1 * a2 * a3 * ... * an?
 * ??1 < a1 <= a2 <= a3 <= ... <= an?????????????????a = a???????
 */

// Intercept<int> sum(1, 3); //??????Sum
Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

Intercept<int> Fact(int x, Intercept<int> y);

int main()
{
	Intercept<int> n, a;
	cin >> n;
	for (state[1] = Intercept<int>(0, 2); state[1] < n; state[1]++)
	{
		cin >> a;
		state[0] = 1;	//????state[0]
		Fact(a, 2); //????
		cout << state[0] << endl;
	}
	return 0;
}
Intercept<int> Fact(int x, Intercept<int> y)
{
	if (x == 1)
		return 0; //???1???0
	else
	{
		state[2] = y;
		for (; state[2] <= sqrt(x); state[2]++) //????????
			if (x % state[2] == 0)
			{
				state[0] = state[0] + Fact(x / state[2], state[2]); //????????Fact(??y)
			}
		return 1;
	}
}
