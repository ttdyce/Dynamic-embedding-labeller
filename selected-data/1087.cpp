#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/*
 * main.cpp
 *
 *  Created on: 2012-11-12
 *      Author: ??
 * 1090 ????

 */

Intercept<int> sum(-1, 3);
Intercept<int> a[100];
void search(Intercept<int> t, Intercept<int> k)
{
	Intercept<int> i;
	if (k == 1)
		sum++;
	else
		for (i = a[t - 1]; i <= k; i++)
			if (k % i == 0)
			{
				a[t] = i;
				search(t + 1, k / i);
			}
}

int main()
{
	Intercept<int> n, i, k;
	cin >> n;
	for (i = Intercept<int>(1, 2); i <= n; i++)
	{
		cin >> k;
		sum = 0;
		a[0] = 2;
		search(1, k);
		cout << sum << endl;
	}
	return 0;
}
