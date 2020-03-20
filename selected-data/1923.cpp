#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> digui(int m, Intercept<int> n, Intercept<int> sum)
{
	Intercept<int> i;
	sum++;
	if (sqrt(m) < n)
		return sum;
	else
	{
		for (i = Intercept<int>(n, 2); i <= sqrt(m); i++)
		{
			if (m % i == 0)
				sum = digui(m / i, i, sum);
		}
		return sum;
	}
}

int main()
{
	Intercept<int> n(-1, 2), a;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &a);
		printf("%d\n", digui(a, 2, 0));
	}
}
