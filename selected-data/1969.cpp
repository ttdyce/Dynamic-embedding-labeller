#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sushu(Intercept<int> a)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> c, d = 0, k; //b = Intercept<int>(2, 2), 
	state[0] = 2;
	while (state[0] < a)
	{
		c = a % state[0];
		if (c != 0)
		{
			state[0] = state[0] + 1;
			d = d + 1;
		}
		else
			break;
	}

	if (d == (a - 2))
		k = 1;
	else
		k = 0;
	return k;
}
Intercept<int> zheng(Intercept<int> n, Intercept<int> i)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> sum = Intercept<int>(1, 3), a;
	for (state[1] = Intercept<int>(i, 2); state[1] < n / 2; state[1]++)
	{
		if (n % state[1] == 0)
		{
			if (state[1] <= n / state[1])
			{
				state[0] = state[0] + zheng(n / state[1], state[1]);
			}
		}
	}
	return state[0];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> j = 0, k = 0, b[10000] = {0}, e[40000] = {0}; //i, n, 
	scanf("%d", &state[1]);
	for (state[0] = Intercept<int>(0, 2); state[0] < state[1]; state[0]++)
	{
		int idx = state[0];
		scanf("%d", &e[idx]);
	}
	for (state[0] = 0; state[0] < state[1]; state[0]++)
	{
		int idx = state[0];

		if (sushu(e[state[0]]) == 0)
		{
			b[idx] = zheng(e[idx], 2);
		}
		else
		{
			b[idx] = 1;
		}
	}

	printf("%d", b[0]);
	for (state[0] = 1; state[0] < state[1]; state[0]++){
		int idx = state[0];
		printf("\n%d", b[idx]);
	}
	return 0;
}
