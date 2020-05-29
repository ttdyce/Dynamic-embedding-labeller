#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> num = 0; gState[0]
Intercept<int> interceptss[] = {Intercept<int>(0, 7)};
StateIntercept gState(interceptss, sizeof(interceptss) / sizeof(interceptss[0]));

Intercept<int> sum(Intercept<int> a, Intercept<int> i)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// i = Intercept<int>(i, 2);
	state[0] = Intercept<int>(i, 2);

	if (a == 1)
	{
		gState[0]++;
	}
	else
	{
		while (i <= a)
		{
			if (a % i == 0)
			{
				sum(a / i, i);
			}
			i++;
		}
	}
	return gState[0];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(0, 5)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> j, count; //i, a, t, 
	cin >> state[2];
	for (state[0] = Intercept<int>(0, 2); state[0] < state[2]; state[0]++)
	{
		state[4] = 1;
		cin >> state[3];
		state[1] = Intercept<int>(2, 2);
		while (state[1] <= (state[3] / 2))
		{
			if (state[3] % state[1] == 0)
			{
				gState[0] = 0;
				sum(state[3] / state[1], state[1]);
				state[4] = state[4] + gState[0];
			}
			state[1]++;
		}
		cout << state[4] << endl;
	}

	return 0;
}
