#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(Intercept<int> n, Intercept<int> m)
{
	Intercept<int> sum(1, 3), i;
	if (n < m)
		sum = 0;
	else if (n == m)
		sum = 1;
	else
	{
		for (i = Intercept<int>(m, 2); i <= n; i++)
			if (n % i == 0)
				sum = sum + f(n / i, i);
	}
	return (sum);
}
int main()
{
	Intercept<int> x, j, a[100000];
	scanf("%d", &x);
	for (j = Intercept<int>(0, 2); j < x; j++)
		scanf("%d", &a[j]);
	for (j = 0; j < x; j++)
		printf("%d\n", f(a[j], 2));
}
