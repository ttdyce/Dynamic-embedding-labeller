#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> s(Intercept<int> a, Intercept<int> b)
{
	Intercept<int> sum(0, 3), z = 0;
	if (a != 1 && b <= a)
	{
		for (Intercept<int> i(b, 2); i <= a; ++i)
		{
			if (a % i == 0)
			{
				sum += s(a / i, i);
				z = 1;
			}
		}
	}
	else if (a == 1)
		return 1;

	return sum;
}
int main()
{
	Intercept<int> n, a;
	cin >> n;
	for (Intercept<int> i(0, 2); i < n; ++i)
	{
		cin >> a;
		cout << s(a, 2) << endl;
	}
	return 0;
}
