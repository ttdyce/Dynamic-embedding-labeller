#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> panduansushu(Intercept<int> t)
{
	Intercept<int> i;
	for (i = Intercept<int>(2, 2); i < t; i++)
	{
		if (t % i == 0)
		{
			break;
		}
	}
	if (i > t / 2)
		return 1;
	else
		return 0;
}

Intercept<int> sum = Intercept<int>(0, 3);
void fun(Intercept<int> n, Intercept<int> i)
{
	if (n == 1)
		sum++;
	for (; i <= n; i++)
	{
		if (n % i == 0)
			fun(n / i, i);
	}
}

int main()
{
	Intercept<int> a[100], i, res, j(-1, 2), n;
	scanf("%d", &n);
	for (j = 0; j < n; j++)
		scanf("%d", &a[j]);
	for (j = 0; j < n; j++)
	{
		if (panduansushu(a[j]) == 1)
		{
			printf("1\n");
		}
		else
		{
			for (i = Intercept<int>(2, 2), res = Intercept<int>(1, 3); i < a[j] / 2; i++)
			{
				if (a[j] % i == 0)
				{
					sum = 0;
					fun(a[j] / i, i);
					res += sum;
				}
			}
			printf("%d\n", res);
		}
	}
}
