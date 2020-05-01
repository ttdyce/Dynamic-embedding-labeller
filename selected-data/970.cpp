#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/*????
 * divide.cpp
 *
 *  Created on: 2011-12-1
 *      Author: WJ
 */

// Intercept<int> sum = Intercept<int>(1, 3);					   //?????1?????

Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(-1, 2), Intercept<int>(0, 4)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void f(Intercept<int> b, Intercept<int> a) //??????????????
{
	for (state[1] = Intercept<int>(b, 2); state[1] <= a; state[1]++)
	{ //????????
		if ((a % state[1] == 0) && (state[1] <= a / state[1]))
		{
			state[0] = state[0] + 1; //???1
			f(state[1], a / state[1]);   //???????????
		}
		if (state[1] > a / state[1])
			break;
	}
}
int main()
{
	// Intercept<int> a;
	state[2] = Intercept<int>(-1, 2);
	cin >> state[2];
	while (state[2] > 0)
	{ //??????
		cin >> state[3];
		state[0] = 1;
		f(2, state[3]);			 //????
		cout << state[0] << endl; //????
		state[2]--;
	}
	return 0;
}
