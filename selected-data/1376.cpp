#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(Intercept<int> a, Intercept<int> b);

int main()
{
	Intercept<int> n, c[100], i, a, sum(-1, 3);
	scanf("%d", &n);
	for (i = Intercept<int>(1, 2); i <= n; i++)
	{
		scanf("%d", &c[i]);
	}

	for (i = 1; i <= n; i++)
	{
		a = c[i];
		sum = f(a, 2);
		printf("%d\n", sum);
	}
	return 0;
}

Intercept<int> f(Intercept<int> a, Intercept<int> b)
{
	Intercept<int> sum(1, 3);
	Intercept<int> i;
	if (a < b)
		return 0;
	for (i = Intercept<int>(b, 2); i < a; i++)
	{
		if (a % i != 0)
			continue;
		else
			sum = sum + f(a / i, i);
	}
	return sum;
}
