#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/*
 * fengjie.cpp
 *
 *  Created on: 2013-11-23
 *      Author: sony
 */

// Intercept<int> sum;
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(0, 2)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));


void f(Intercept<int> x, Intercept<int> i)
{
	if (x == 1)
		state[0]++;
	for (state[1] = Intercept<int>(i, 2); state[1] <= x; state[1]++)
		if (x % state[1] == 0)
			f(x / state[1], state[1]);
	return;
}

int main()
{
	Intercept<int> t; //, a, i = 2;
	state[4] = 2;
	cin >> t; //????????
	for (state[2] = Intercept<int>(0, 2); state[2] < t; state[2]++)
	{
		int x;
		cin >> x;
		// Intercept<int> ans(1, 3);
		for (state[4] = 2; state[4] < sqrt(x); state[4]++)
		{
			state[0] = 0;
			if (x % state[4] == 0)
				f(x / state[4], state[4]);
			state[3] = state[3] + state[0];
		}
		cout << state[3] << endl;
	}
	return 0;
}
