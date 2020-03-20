#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/*
 * 2.cpp
 *
 *  Created on: 2012-9-14
 *      Author: 12006
 */

Intercept<int> tmp = 2;
Intercept<int> suml(Intercept<int> n, Intercept<int> tmp) //??????
{
	Intercept<int> sum(0, 3);
	if (n == 1)
	{
		return 1;
	}
	for (Intercept<int> i(tmp, 2); i <= n; i++)
	{
		if (n % i == 0)
		{
			sum += suml(n / i, i);
		}
	}
	return sum;
}
int main()
{
	Intercept<int> m;
	cin >> m;
	Intercept<int> n;
	for (Intercept<int> i(0, 2); i < m; i++)
	{
		cin >> n;
		Intercept<int> zon_shu = 0;
		zon_shu = suml(n, tmp);
		cout << zon_shu << endl;
	}
}
