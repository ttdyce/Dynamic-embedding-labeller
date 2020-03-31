#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> way(Intercept<int> x, Intercept<int> m)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int>  p = 0; //sum(0, 3),, i
	for (state[1] = Intercept<int>(m, 2); state[1] < x; state[1]++)
		if (x % state[1] == 0)
		{
			p++;
			state[0] = state[0] + way(x / state[1], state[1]);
		}
	state[0] = state[0] + 1;
	if (p == 0)
		state[0] = 1;
	if (m > x)
		state[0] = 0;
	return (state[0]);
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> n, a;// , i
	scanf("%d", &n);
	for (state[0] = Intercept<int>(1, 2); state[0] <= n; state[0]++)
	{
		scanf("%d", &a);
		printf("%d\n", way(a, 2));
	}
	return 0;
}
