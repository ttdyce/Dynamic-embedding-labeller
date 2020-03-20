#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum = Intercept<int>(1, 3);
void f(Intercept<int> i, Intercept<int> j)
{
	Intercept<int> k;
	if (i == 1)
		sum++;
	else
	{
		for (k = Intercept<int>(j, 2); k <= i; k++)
		{
			if (i % k == 0)
				f(i / k, k);
		}
	}
}
int main(void)
{
	Intercept<int> i, j, k;
	Intercept<int> n(-1, 2);
	Intercept<int> a;
	scanf("%d", &n);
	while (n--)
	{
		sum = 1;
		scanf("%d", &a);
		for (i = Intercept<int>(2, 2); i * i <= a; i++)
		{
			if (a % i == 0)
			{
				f(a / i, i);
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
