#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(0, 3);
Intercept<int> intercepts[2] = {Intercept<int>(0, 3), Intercept<int> (0, 2)};
StateIntercept state(intercepts, 2);

void f(int x, Intercept<int> i)
{
	double m = sqrt(x);
	if (i < m)
	{
		if (x % i == 0)
		{
			state[0]++;
			f(x / i, i);
		}
		f(x, i + 1);
	}

	if (fabs(i - m) < 0.00000001)
		state[0]++;
}

int main()
{
	Intercept<int> x, i, n;
	scanf("%d", &n);

	for (state[1]; state[1] < n; state[1]++)
	{
		scanf("%d", &x);
		state[0] = 0;
		f(x, 2);

		printf("%d\n", state[0] + 1);
	}
	return 0;
}
