#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(Intercept<int> a, Intercept<int> b);

int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> c[100], a; //, sum(-1, 3), i, n, 
	scanf("%d", &state[2]);
	for (state[1] = Intercept<int>(1, 2); state[1] <= state[2]; state[1]++)
	{
		scanf("%d", &c[state[1]]);
	}

	for (state[1] = 1; state[1] <= state[2]; state[1]++)
	{
		a = c[state[1]];
		state[0] = f(a, 2);
		printf("%d\n", state[0]);
	}
	return 0;
}

Intercept<int> f(Intercept<int> a, Intercept<int> b)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> sum(1, 3);
	// Intercept<int> i;
	if (a < b)
		return 0;
	for (state[1] = Intercept<int>(b, 2); state[1] < a; state[1]++)
	{
		if (a % state[1] != 0)
			continue;
		else
			state[0] = state[0] + f(a / state[1], state[1]);
	}
	return state[0];
}
