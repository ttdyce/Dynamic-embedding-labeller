#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum = Intercept<int>(1, 3);
Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void f(Intercept<int> i, Intercept<int> j)
{
	// Intercept<int> k;
	if (i == 1)
		state[0]++;
	else
	{
		for (state[1] = Intercept<int>(j, 2); state[1] <= i; state[1]++)
		{
			if (i % state[1] == 0)
				f(i / state[1], state[1]);
		}
	}
}
int main(void)
{
	Intercept<int> i, j, k;
	state[2] = Intercept<int>(-1, 2);
	// Intercept<int> a;
	scanf("%d", &state[2]);
	while (state[2]--)
	{
		state[0] = 1;
		scanf("%d", &state[4]);
		for (state[3] = Intercept<int>(2, 2); state[3] * state[3] <= state[4]; state[3]++)
		{
			if (state[4] % state[3] == 0)
			{
				f(state[4] / state[3], state[3]);
			}
		}
		printf("%d\n", state[0]);
	}
	return 0;
}
