#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(Intercept<int> n, Intercept<int> m)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));
	// Intercept<int> sum(1, 3), i;
	if (n < m)
		state[0] = 0;
	else if (n == m)
		state[0] = 1;
	else
	{
		for (state[1] = Intercept<int>(m, 2); state[1] <= n; state[1]++)
			if (n % state[1] == 0)
				state[0] = state[0] + f(n / state[1], state[1]);
	}
	return (state[0]);
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> x, j, a[100000];
	scanf("%d", &x);
	for (state[0] = Intercept<int>(0, 2); state[0] < x; state[0]++)
		scanf("%d", &a[state[0]]);
	for (state[0] = 0; state[0] < x; state[0]++)
		printf("%d\n", f(a[state[0]], 2));
}
