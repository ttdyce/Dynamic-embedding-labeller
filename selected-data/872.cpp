#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> chu(Intercept<int> i, Intercept<int> n);
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(2, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n, j; //i, 
	// int m;
	Intercept<int> sum[100];
	scanf("%d", &state[2]);
	for (state[0] = Intercept<int>(0, 2); state[0] <= (state[2] - 1); state[0]++)
	{
		scanf("%d", &state[3]);
		int replacement = state[3];
		sum[state[0]] = Intercept<int>(0, 3);
		for (state[1] = Intercept<int>(2, 2); state[1] <= sqrt(replacement); state[1]++)
		{
			if (state[3] % state[1] == 0)
			{
				sum[state[0]] += chu(state[1], state[3] / state[1]);
			}
		}
	}
	for (state[0] = 0; state[0] <= (state[2] - 1); state[0]++)
	{
		printf("%d\n", sum[state[0]] + 1);
	}
}
Intercept<int> chu(Intercept<int> i, Intercept<int> n)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(i, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> j; //, t
	int m;
	// t = Intercept<int>(1, 3);
	m = n;
	for (state[1] = Intercept<int>(i, 2); state[1] <= sqrt(m); state[1]++)
	{
		if (m % state[1] == 0)
		{

			state[0] += chu(state[1], (m / state[1]));
		}
	}
	return state[0];
}
