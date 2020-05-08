#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> meide(int x, Intercept<int> y)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> count = 0; //sum(1, 3), , i
	for (state[1] = Intercept<int>(y, 2); state[1] <= sqrt(x); state[1]++)
	{
		if (x % state[1] == 0)
		{
			state[0] = state[0] + meide(x / state[1], state[1]);
		}
	}
	return state[0];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> k, n, m;
	scanf("%d", &state[1]);
	for (state[0] = Intercept<int>(0, 2); state[0] < state[1]; state[0]++)
	{
		scanf("%d", &state[2]);
		if (state[2] >= 3)
		{
			printf("%d\n", meide(state[2], 2));
		}
		else
		{
			printf("1\n");
		}
	}
	return 0;
}
