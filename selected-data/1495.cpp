#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> function(Intercept<int> a, Intercept<int> m)
{
	Intercept<int> sum(1, 3), i;
	if (a > m)
		return 0;
	else
	{
		for (i = Intercept<int>(a, 2); i < m; i++)
		{
			if (m % i == 0)
				sum = sum + function(i, m / i);
			else
				continue;
		}
		return sum;
	}
}

int main()
{
	Intercept<int> n, i, m[100];

	scanf("%d", &n);

	for (i = Intercept<int>(0, 2); i <= n - 1; i++)
	{
		scanf("%d", &m[i]);
	}

	for (i = 0; i <= n - 1; i++)
	{
		printf("%d\n", function(2, m[i]));
	}
}
