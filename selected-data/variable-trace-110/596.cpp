#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> cut(int m, Intercept<int> l)
{
	Intercept<int> sum(1, 3);
	for (Intercept<int> i = Intercept<int>(l, 2); i <= sqrt((double)m / l); i++)
	{
		if ((m / l) % i == 0)
		{
			sum += cut(m / l, i);
		}
	}
	return sum;
}

int main()
{
	Intercept<int> n;
	cin >> n;
	for (Intercept<int> i = 0; i < n; i++)
	{
		Intercept<int> t = 0;
		cin >> t;
		cout << cut(2 * t, 2);
		if (i < n - 1)
			cout << endl;
	}
}
