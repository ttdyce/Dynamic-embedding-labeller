#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(Intercept<int> a, Intercept<int> i)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> ret = Intercept<int>(1, 3);
	for (state[1] = Intercept<int>(state[1], 2); state[1] <= sqrt((float)a); state[1]++)
	{
		if (a % state[1] == 0)
		{
			state[0] += sum(a / state[1], state[1]);
		}
	}
	return state[0];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> t, a;//, j;
	cin >> t;

	for (state[0] = Intercept<int>(0, 2); state[0] < t; state[0]++)
	{
		cin >> a;
		cout << sum(a, 2) << endl;
	}
	return 0;
}
