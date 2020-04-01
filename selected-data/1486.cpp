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
	// Intercept<int> sum(0, 3);
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	if (n == 1)
	{
		return 1;
	}
	for (state[1] = Intercept<int>(tmp, 2); state[1] <= n; state[1]++)
	{
		if (n % state[1] == 0)
		{
			state[0] += suml(n / state[1], state[1]);
		}
	}
	return state[0];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> m;
	cin >> m;
	Intercept<int> n;
	for (state[0] = Intercept<int>(0, 2); state[0] < m; state[0]++)
	{
		cin >> n;
		Intercept<int> zon_shu = 0;
		zon_shu = suml(n, tmp);
		cout << zon_shu << endl;
	}
}
