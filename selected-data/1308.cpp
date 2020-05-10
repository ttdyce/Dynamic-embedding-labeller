#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> calculate(Intercept<int> a, Intercept<int> num)
{ // a is the max num
	// Intercept<int> sum(0, 3);
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 8)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	if (num == 1)
	{
		state[1] = 1;
		return 1;
	}
	for (state[1] = Intercept<int>(num, 2); state[1] >= 2; state[1]--)
	{
		if (num % state[1] == 0 && state[1] <= a)
		{
			state[0] += calculate(state[1], num / state[1]);
		}
	}
	return state[0];
}

int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n;
	cin >> state[1];
	// Intercept<int> num = 0;
	for (state[0] = Intercept<int>(0, 2); state[0] < state[1]; state[0]++)
	{ // input part
		cin >> state[2];
		cout << calculate(state[2], state[2]) << endl;
	}
	return 0;
}
