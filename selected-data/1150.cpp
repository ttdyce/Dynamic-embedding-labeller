#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> way(Intercept<int> x, Intercept<int> m)
{
	Intercept<int> sum(0, 3), p = 0, i;
	for (i = Intercept<int>(m, 2); i < x; i++)
		if (x % i == 0)
		{
			p++;
			sum = sum + way(x / i, i);
		}
	sum = sum + 1;
	if (p == 0)
		sum = 1;
	if (m > x)
		sum = 0;
	return (sum);
}
int main()
{
	Intercept<int> n, a, i;
	scanf("%d", &n);
	for (i = Intercept<int>(1, 2); i <= n; i++)
	{
		scanf("%d", &a);
		printf("%d\n", way(a, 2));
	}
	return 0;
}
