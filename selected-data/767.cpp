#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> divide(int n, Intercept<int> j)
{
	Intercept<int> sum = Intercept<int>(1, 3), i, s, p, k;
	s = sqrt(n);
	for (i = Intercept<int>(j, 2); i <= s; i++)
	{
		if (n % i == 0)
		{
			p = n / i;
			k = i;
			sum = sum + divide(p, i);
		}
	}
	return sum;
}
int main()
{
	Intercept<int> n;
	cin >> n;
	Intercept<int> k, m, p;
	for (k = Intercept<int>(0, 2); k < n; k++)
	{
		cin >> m;
		p = divide(m, 2);
		cout << p << endl;
	}
	return 0;
}
