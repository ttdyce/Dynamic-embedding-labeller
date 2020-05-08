#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(0, 3);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

Intercept<int> geshu(int a, Intercept<int> x)
{
	Intercept<int> y, z;
	z = a;
	y = (int)sqrt(a);
	state[2] = x;

	while (state[2] <= y)
	{
		if (a % state[2] == 0)
		{
			a = a / state[2];
			geshu(a, state[2]);
		}
		if (a == z / state[2])
			a = z;
		state[2]++;
	}
	state[0]++;
	return state[0];
}
int main()
{
	Intercept<int> a[100], b[100], x; //i, n, 
	scanf("%d", &state[3]);
	for (state[1]; state[1] < state[3]; state[1]++)
	{
		scanf("%d", &a[state[1]]);
		if (a[state[1]] == 2 || a[state[1]] == 3)
			b[state[1]] = 1;
		else
		{
			state[0] = 0;
			x = 2;
			b[state[1]] = geshu(a[state[1]], x);
		}
	}
	for (state[1] = 0; state[1] < state[3]; state[1]++)
	{
		printf("%d\n", b[state[1]]);
	}
}
