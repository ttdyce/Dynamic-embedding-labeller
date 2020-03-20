#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/* ????.cpp
 *  Created on: 2012-11-21
 *   Author: ??
 */
Intercept<int> ans(int a, Intercept<int> i)
{							//??????
	Intercept<int> sum(0, 3); //??
	for (Intercept<int> j(i, 2); j <= sqrt(a); j++)
	{ //?i???a??
		if (a % j != 0)
			continue; //??????
		sum++;		  //??????1
		if (a >= j * j)
			sum += ans(a / j, j); //????????????????????
	}
	return sum;
}
int main()
{
	Intercept<int> n, a; //???????
	cin >> n;
	for (Intercept<int> i(0, 2); i < n; i++)
	{
		cin >> a;
		cout << ans(a, 2) + 1 << endl;
	}
	return 0;
}
