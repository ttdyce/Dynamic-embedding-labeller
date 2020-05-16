#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/*
 * seperateThenumber.cpp
 *
 *  Created on: 2012-11-13
 *      Author: AK
 */
// Intercept<int> sum(1, 3); //??????sum  ??f???sum?????

Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(-1, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void f(Intercept<int> begin, Intercept<int> m)
{ //??f??
	// Intercept<int> i;
	for (state[1] = Intercept<int>(begin, 2); state[1] <= m; state[1]++)
	{ //?state[1]???????????
		if (m % state[1] == 0 && m / state[1] >= state[1])
		{
			state[0]++;
			state[5]++;
			f(state[1], m / state[1]);
		} //?????????????????   ????????????
		if (state[1] > m / state[1])
			break; //?????????????break
	}
}
int main()
{
	// Intercept<int> n, m;//, j
	cin >> state[3]; //????????state[3]
	for (state[2] = Intercept<int>(1, 2); state[2] <= state[3]; state[2]++)
	{ //???????
		cin >> state[4];
		f(2, state[4]);
		cout << state[0] << endl; //??state[0]?
		state[0] = 1;			 //??sum=1
		state[5] = 1;			 //??sum=1
	}
	return 0;
}
