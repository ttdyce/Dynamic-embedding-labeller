#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(0, 3);
void f(Intercept<int> x, Intercept<int> y)
{
	y = Intercept<int>(y, 2);

	if (x == 1)
		sum++;
	while (y <= x)
	{
		if (x % y == 0)
			f(x / y, y);
		y++;
	}
}
int main()
{
	Intercept<int> n, i, a;
	cin >> n;
	for (i = Intercept<int>(1, 2); i <= n; i++)
	{
		cin >> a;
		Intercept<int> j(2, 2), num(1, 3);
		while (j <= a / 2)
		{
			if (a % j == 0)
			{
				sum = 0;
				f(a / j, j);
				num += sum;
			}
			j++;
		}
		printf("\n%d", num);
	}
	return 0;
}
