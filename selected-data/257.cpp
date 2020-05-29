#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sort(Intercept<int>, int, Intercept<int>);

int main()
{
	// Intercept<int> t = 0;

	Intercept<int> intercepts[] = {Intercept<int>(1, 2), Intercept<int>(1, 2), Intercept<int>(0, 4), Intercept<int>(1, 4),Intercept<int>(0,7)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	cin >> state[2];
	// Intercept<int> state[0](1, 2);
	for (state[0] = 1; state[0] <= state[2]; state[0]++)
	{
		// Intercept<int> state[4] = 0;
		// Intercept<int> vacancy = 0;
		// Intercept<int> num = 1;
		cin >> state[3];
		// Intercept<int> state[1](1, 2);
		Intercept<int> temp = state[3];
		for (state[1] = 2; state[1] <= temp; state[1]++)
		{
			while (temp % state[1] == 0)
			{
				state[4] = state[4] + 1;
				temp = temp / state[1];
			}
		}
		cout << sort(Intercept<int>(1), state[4], state[3]) << endl;
	}
	return 0;
}

Intercept<int> sort(Intercept<int> start, int vacancy, Intercept<int> num)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 2), Intercept<int>(0, 3), Intercept<int>(0, 8), Intercept<int>(0, 8)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	if (num < start)
	{
		state[2] = 1;
		return 0;
	}
	if (vacancy == 1)
	{
		state[3] = 1;
		return 1;
	}

	// Intercept<int> sum(0, 3);
	// Intercept<int> i(1, 2);
	for (state[0] = start; state[0] <= num; state[0]++)
	{
		if (num % state[0] == 0)
		{
			state[1] = state[1] + sort(state[0], vacancy - 1, num / state[0]);
		}
	}

	return state[1];
}
