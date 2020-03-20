#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(Intercept<int> a, Intercept<int> i)
{
	Intercept<int> ret = Intercept<int>(1, 3);
	for (i = Intercept<int>(i, 2); i <= sqrt((float)a); i++)
	{
		if (a % i == 0)
		{
			ret += sum(a / i, i);
		}
	}
	return ret;
}
int main()
{
	Intercept<int> t, a, j;
	cin >> t;

	for (j = Intercept<int>(0, 2); j < t; j++)
	{
		cin >> a;
		cout << sum(a, 2) << endl;
	}
	return 0;
}
