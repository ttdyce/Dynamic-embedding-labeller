#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

int main()
{
	Intercept<int> ways(Intercept<int> a, Intercept<int> min);
	// Intercept<int> b;
	Intercept<int> intercepts[] = {Intercept<int>(-1, 2), Intercept<int>(-1, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));
	scanf("%d", &state[0]);
	while (state[0]-- > 0)
	{
		scanf("%d", &state[1]);
		printf("%d\n", ways(state[1], 2));
	}
}
Intercept<int> ways(Intercept<int> a, Intercept<int> min)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(-1, 2), Intercept<int>(0, 8)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));
	if (a < min)
	{
		state[2] = 1;
		return 0;
	}
	for (state[1] = min; state[1] <= sqrt(a * 1.0); state[1]++)
	{
		if (a % state[1] == 0)
			state[0] = state[0] + ways(a / state[1], state[1]);
	}
	return state[0] + 1;
}
