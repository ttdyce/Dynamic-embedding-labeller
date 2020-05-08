#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(1, 3);
Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(1, 2), Intercept<int>(0, 4), Intercept<int>(0, 4) };
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

Intercept<int> kk(Intercept<int> a, Intercept<int> b)
{
	// Intercept<int> i;
	for (state[1] = Intercept<int>(b, 2); state[1] >= 2; state[1]--)
		if (a % state[1] == 0)
			return a / state[1];
	return 0;
}
Intercept<int> seperate(Intercept<int> a, Intercept<int> b)
{
	Intercept<int> i;
	for (state[2] = Intercept<int>(b, 2); state[2] >= 2; state[2]--)
	{
		if (a % state[2] == 0 && (a / state[2]) <= state[2])
		{
			state[0]++;
			if ((a / state[2]) == 2)
				continue;
			else
				seperate(a / state[2], a / state[2] - 1);
		}
		else if ((a % state[2] == 0) && ((kk(a / state[2], state[2])) != 0))
		{
			seperate(a / state[2], state[2]);
		}
	}
	return state[0];
}
int main()
{
	// Intercept<int> n,  m; // i,
	cin >> state[4];

	for (state[3]; state[3] <= state[4]; state[3]++)
	{
		cin >> state[5];
		cout << seperate(state[5], state[5] - 1) << endl;
		state[0] = 1;
	}
	return 0;
}
