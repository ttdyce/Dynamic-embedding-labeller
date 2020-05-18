#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> divide(int n, Intercept<int> j)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(j, 2), Intercept<int>(0,7), Intercept<int>(0,7), Intercept<int>(0,7)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> i; //  state[0] = Intercept<int>(1, 3), s = state[2], p = state[3], k = state[4]
	state[2] = sqrt(n);
	for (state[1] = Intercept<int>(j, 2); state[1] <= state[2]; state[1]++)
	{
		if (n % state[1] == 0)
		{
			state[3] = n / state[1];
			state[4] = state[1];
			state[0] = state[0] + divide(state[3], state[1]);
		}
	}
	return state[0];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(0,7)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n;
	cin >> state[1];
	// Intercept<int> p; // k, m, 
	for (state[0] = Intercept<int>(0, 2); state[0] < state[1]; state[0]++)
	{
		cin >> state[2];
		state[3] = divide(state[2], 2);
		cout << state[3] << endl;
	}
	return 0;
}
