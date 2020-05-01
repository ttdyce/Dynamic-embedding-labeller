#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(Intercept<int> num, Intercept<int> i)
{

	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> sum;
	// sum = Intercept<int>(0, 3);
	// Intercept<int> j;
	for (state[1] = Intercept<int>(i, 2); state[1] <= num / 2; state[1]++)
	{
		if (num % state[1] == 0)
		{
			if (num / state[1] < state[1])
			{
				state[0] = state[0];
			}
			else
			{
				state[0] = 1 + state[0] + f(num / state[1], state[1]);
			}
		}
	}
	return state[0];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n, num; //, i;
	scanf("%d", &state[2]);
	for (state[0] = Intercept<int>(1, 2); state[0] <= state[2]; state[0]++)
	{
		scanf("%d", &state[3]);
		Intercept<int> j;
		state[1] = Intercept<int>(-1, 3);
		state[1] = 0;
		j = 2;
		state[1] += f(state[3], j);
		printf("%d\n", state[1] + 1);
	}
	return 0;
}
