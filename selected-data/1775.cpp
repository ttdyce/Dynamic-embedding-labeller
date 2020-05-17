#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> s(Intercept<int> a, Intercept<int> b)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 8), Intercept<int>(0, 5)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> z = 0; //sum(0, 3),
	if (a != 1 && b <= a)
	{
		for (state[1] = Intercept<int>(b, 2); state[1] <= a; ++state[1])
		{
			if (a % state[1] == 0)
			{
				state[0] += s(a / state[1], state[1]);
				state[3] += state[0];
				z = 1;
			}
		}
	}
	else if (a == 1)
	{
		state[2] = 1;
		return 1;
	}
	return state[0];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n, a;
	cin >> state[1];
	for (state[0] = Intercept<int>(0, 2); state[0] < state[1]; ++state[0])
	{
		cin >> state[2];
		cout << s(state[2], 2) << endl;
	}
	return 0;
}
