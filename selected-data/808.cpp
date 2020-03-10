#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(0, 3);
void fenjie(Intercept<int> t, Intercept<int> n)
{
	Intercept<int> i(0, 2);
	if (n == 1)
		sum++;
	for (i = t; i <= n; i++)
	{
		if (n % i == 0)
		{
			fenjie(i, n / i);
		}
	}
}
int main()
{
	Intercept<int> n(0,2), k = 0;
	cin >> n;
	while (n > 0)
	{
		cin >> k;
		sum = 0;
		fenjie(2, k);
		n--;
		cout << sum << endl;
	}
	return 0;
}
