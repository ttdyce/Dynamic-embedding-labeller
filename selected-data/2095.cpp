#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> panduansushu(Intercept<int> t)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept s(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> i;
	for (s[0] = Intercept<int>(2, 2); s[0] < t; s[0]++)
	{
		if (t % s[0] == 0)
		{
			break;
		}
	}
	if (s[0] > t / 2)
		return 1;
	else
		return 0;
}

// Intercept<int> sum = Intercept<int>(0, 3);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(1, 3)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void fun(Intercept<int> n, Intercept<int> i)
{
	if (n == 1)
		state[0]++;
	for (; i <= n; i++)
	{
		if (n % i == 0)
			fun(n / i, i);
	}
}

int main()
{
	Intercept<int> a[100], i, res, state[1] = Intercept(-1, 2), n;
	scanf("%d", &n);
	for (state[1] = 0; state[1] < n; state[1]++)
		scanf("%d", &a[state[1]]);
	for (state[1] = 0; state[1] < n; state[1]++)
	{
		if (panduansushu(a[state[1]]) == 1)
		{
			printf("1\n");
		}
		else
		{
			for (state[2] = Intercept<int>(2, 2), state[3] = Intercept<int>(1, 3); state[2] < a[state[1]] / 2; state[2]++)
			{
				if (a[state[1]] % state[2] == 0)
				{
					state[0] = 0;
					fun(a[state[1]] / state[2], state[2]);
					state[3] += state[0];
				}
			}
			printf("%d\n", state[3]);
		}
	}
}
