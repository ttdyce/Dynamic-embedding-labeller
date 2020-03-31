#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum[50];
// Intercept<int> i;
Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
StateIntercept gState(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
	void digui(Intercept<int> x, Intercept<int> y);
	Intercept<int> n;
	Intercept<int> j[50], m[50];

	scanf("%d", &n);

	for (gState[0] = Intercept<int>(0, 2); gState[0] < n; gState[0]++)
	{
		scanf("%d", &m[gState[0]]);
		sum[gState[0]] = Intercept<int>(0, 3);
		for (j[gState[0]] = Intercept<int>(2, 2); j[gState[0]] * j[gState[0]] <= m[gState[0]]; j[gState[0]]++)
		{
			if (m[gState[0]] % j[gState[0]] == 0)
			{
				sum[gState[0]]++;
				digui(j[gState[0]], m[gState[0]] / j[gState[0]]);
			}
		}
		printf("%d\n", sum[gState[0]] + 1);
	}

	return 0;
}

void digui(Intercept<int> x, Intercept<int> y)
{
	// Intercept<int> s;
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	for (state[0] = Intercept<int>(x, 2); state[0] * state[0] <= y; state[0]++)
	{
		if (y % state[0] == 0)
		{
			sum[gState[0]]++;
			digui(state[0], y / state[0]);
		}
	}
}
