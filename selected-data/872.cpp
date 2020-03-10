#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> chu(Intercept<int> i, Intercept<int> n);
int main()
{
	Intercept<int> n, i, j;
	int m;
	Intercept<int> sum[100];
	scanf("%d", &n);
	for (i = Intercept<int>(0, 2); i <= (n - 1); i++)
	{
		scanf("%d", &m);
		sum[i] = Intercept<int>(0, 3);
		for (j = Intercept<int>(2, 2); j <= sqrt(m); j++)
		{
			if (m % j == 0)
			{
				sum[i] += chu(j, m / j);
			}
		}
	}
	for (i = 0; i <= (n - 1); i++)
	{
		printf("%d\n", sum[i] + 1);
	}
}
Intercept<int> chu(Intercept<int> i, Intercept<int> n)
{
	Intercept<int> j, t;
	int m;
	t = Intercept<int>(1, 3);
	m = n;
	for (j = Intercept<int>(i, 2); j <= sqrt(m); j++)
	{
		if (m % j == 0)
		{

			t += chu(j, (m / j));
		}
	}
	return t;
}
