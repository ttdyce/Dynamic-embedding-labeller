#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(1, 3);
Intercept<int> kk(Intercept<int> a, Intercept<int> b)
{
	Intercept<int> i;
	for (i = Intercept<int>(b, 2); i >= 2; i--)
		if (a % i == 0)
			return a / i;
	return 0;
}
Intercept<int> seperate(Intercept<int> a, Intercept<int> b)
{
	Intercept<int> i;
	for (i = Intercept<int>(b, 2); i >= 2; i--)
	{
		if (a % i == 0 && (a / i) <= i)
		{
			sum++;
			if ((a / i) == 2)
				continue;
			else
				seperate(a / i, a / i - 1);
		}
		else if ((a % i == 0) && ((kk(a / i, i)) != 0))
		{
			seperate(a / i, i);
		}
	}
	return sum;
}
int main()
{
	Intercept<int> n, i, m;
	cin >> n;

	for (i = Intercept<int>(1, 2); i <= n; i++)
	{
		cin >> m;
		cout << seperate(m, m - 1) << endl;
		sum = 1;
	}
	return 0;
}
