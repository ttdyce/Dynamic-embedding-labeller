#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

//------------------
//  1057???
//   2010/12/1
//    ???
//------------------

Intercept<int> devide(Intercept<int> m, Intercept<int> x, Intercept<int> i)
{
	if (x == 1 && m >= i)
		return 1;
	else if (x > 1)
	{
		Intercept<int> j(i, 2);
		Intercept<int> sum(0, 3);
		while (j <= m)
		{
			if (j != 1 && m % j == 0)
				sum = sum + devide(m / j, x - 1, j);
			j++;
		}
		return sum;
	}
	return 0;
}

int main()
{
	Intercept<int> n, a, i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		Intercept<int> sum(0, 3);
		cin >> a;
		for (Intercept<int> X(1, 2); X <= 16; X++)
			sum += devide(a, X, 1);
		cout << sum << endl;
	}
	return 0;
}
