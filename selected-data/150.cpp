#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/**
* @author ??
* @date 2010-12-1
* @description
* ??????:???? 
*/
// Intercept<int> sum;
void calculate(int, Intercept<int>);
Intercept<int> intercepts[] = {Intercept<int>(-1, 1), Intercept<int>(0, 2), Intercept<int>(1, 3), Intercept<int>(-1, 2), Intercept<int>(-1, 4), Intercept<int>(1, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
	// Intercept<int> n(-1, 1);
	cin >> state[0];
	for (state[1]; state[1] < state[0]; state[1]++)
	{
		// int m;
		state[2] = Intercept<int>(1, 3);
		cin >> state[4];
		calculate(state[4], Intercept<int>(2));
		cout << state[2] << endl;
	}
	return 0;
}
void calculate(int m, Intercept<int> begin)
{
	// Intercept<int> i;
	Intercept<int> intercepts[] = {Intercept<int>(0,7)};
	StateIntercept states(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));
	// Intercept<int> n = sqrt((double)m);
	states[0] = sqrt((double)m);
	for (state[3] = Intercept<int>(begin, 2); state[3] <= n; state[3]++)
	{
		if (m % state[3] == 0)
		{
			state[2]++;
			state[5]++;
			calculate(m / state[3], Intercept<int>(state[3], 1));
		}
	}
}
