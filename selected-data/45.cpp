#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

int main()
{
	Intercept<int> ways(Intercept<int> a, Intercept<int> min);
	Intercept<int> b;
	Intercept<int> intercepts[1] = {Intercept<int>(-1, 2)};
	StateIntercept state(intercepts, 1);
	scanf("%d", &state[0]);
	while (state[0]-- > 0)
	{
		scanf("%d", &b);
		printf("%d\n", ways(b, 2));
	}
}
Intercept<int> ways(Intercept<int> a, Intercept<int> min)
{
	if (a < min)
		return 0;
	Intercept<int> intercepts[2] = {Intercept<int>(0, 3), Intercept<int>(-1, 2)};
	StateIntercept state(intercepts, 2);

	for (state[1] = min; state[1] <= sqrt(a * 1.0); state[1]++)
	{
		if (a % state[1] == 0)
			state[0] = state[0] + ways(a / state[1], state[1]);
	}
	return state[0] + 1;
}
