#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

/*
 * fengjie.cpp
 *
 *  Created on: 2013-11-23
 *      Author: sony
 */

Intercept<int> sum;

void f(Intercept<int> x, Intercept<int> i)
{
	if (x == 1)
		sum++;
	for (i = Intercept<int>(i, 2); i <= x; i++)
		if (x % i == 0)
			f(x / i, i);
	return;
}

int main()
{
	Intercept<int> t, a, i = 2;
	cin >> t; //????????
	for (a = Intercept<int>(0, 2); a < t; a++)
	{
		int x;
		cin >> x;
		Intercept<int> ans(1, 3);
		for (i = 2; i < sqrt(x); i++)
		{
			sum = 0;
			if (x % i == 0)
				f(x / i, i);
			ans = ans + sum;
		}
		cout << ans << endl;
	}
	return 0;
}
