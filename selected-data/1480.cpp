#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> divide(Intercept<int> d, Intercept<int> n)
{
	Intercept<int> sum(0, 3);
	for (Intercept<int> i(d, 2); i < n; i++)
	{
		if (n % i == 0 && (n / i) >= i)
		{
			sum = sum + 1;
			sum = sum + divide(i, n / i);
		}
	}
	return (sum);
}
int main()
{
	Intercept<int> n, num;
	cin >> n;
	for (Intercept<int> i(0, 2); i < n; i++)
	{
		cin >> num;
		cout << divide(2, num) + 1 << endl;
	}
	return 0;
}
