#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> Factorization(Intercept<int>, Intercept<int>);
int main()
{
	Intercept<int> n, x, i, k;
	cin >> n;
	for (i = Intercept<int>(0, 2); i < n; i++)
	{
		cin >> x;
		cout << Factorization(x, 2) + 1 << endl;
	}
	return 0;
}
Intercept<int> Factorization(Intercept<int> x, Intercept<int> y)
{
	Intercept<int> i;
	Intercept<int> sum(0, 3);
	if (x < 4)
		return 0;
	else
	{
		for (i = Intercept<int>(y, 2); i <= sqrt((double)x); i++)
			if (x % i == 0)
				sum += 1 + Factorization(x / i, i);
		return sum;
	}
}
