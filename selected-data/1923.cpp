#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> digui(int m, Intercept<int> n, Intercept<int> sum)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> i;
	sum++;
	if (sqrt(m) < n)
		return sum;
	else
	{
		for (state[0] = Intercept<int>(n, 2); state[0] <= sqrt(m); state[0]++)
		{
			if (m % state[0] == 0)
				sum = digui(m / state[0], state[0], sum);
		}
		return sum;
	}
}

int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> a; //n(-1, 2), 
	scanf("%d", &state[0]);
	while (state[0]--)
	{
		scanf("%d", &state[1]);
		printf("%d\n", digui(state[1], 2, 0));
	}
}
