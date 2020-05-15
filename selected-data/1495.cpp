#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> function(Intercept<int> a, Intercept<int> m)
{
	// Intercept<int> sum(1, 3), i;
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(0, 8)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	if (a > m)
	{
		state[2] = 1;
		return 0;
	}
	else
	{
		for (state[1] = Intercept<int>(a, 2); state[1] < m; state[1]++)
		{
			if (m % state[1] == 0)
				state[0] = state[0] + function(state[1], m / state[1]);
			else
				continue;
		}
		return state[0];
	}
}

int main()
{
	Intercept<int> m[100]; // i,n,
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	scanf("%d", &state[1]);

	for (state[0] = Intercept<int>(0, 2); state[0] <= state[1] - 1; state[0]++)
	{
		scanf("%d", &m[state[0]]);
	}

	for (state[0] = 0; state[0] <= state[1] - 1; state[0]++)
	{
		printf("%d\n", function(2, m[state[0]]));
	}
}
