#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(Intercept<int> a, Intercept<int> min)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(0, 8), Intercept<int>(1, 5)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	if (a < min)
	{
		state[2] = 1;
		return 0;
	} // Intercept<int> sum(1, 3);
	for (state[1] = Intercept<int>(min, 2); state[1] < a; state[1]++)
	{
		if (a % state[1] == 0)
			state[0] += f(a / state[1], state[1]);
			state[3] += state[0];
	}
	return state[0];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n;
	Intercept<int> a[100];
	scanf("%d", &state[1]);
	for (state[0] = Intercept<int>(0, 2); state[0] < state[1]; state[0]++)
	{
		scanf("%d", &a[state[0]]);
		a[state[0]] = f(a[state[0]], 2);
	}
	for (state[0] = 0; state[0] < state[1]; state[0]++)
	{
		printf("%d\n", a[state[0]]);
	}
	return 0;
}
