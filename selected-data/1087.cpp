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

// Intercept<int> sum(-1, 3);
Intercept<int> a[100];
Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void search(Intercept<int> t, Intercept<int> k)
{
	Intercept<int> i;
	if (k == 1)
		state[0]++;
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
	// Intercept<int> n, i, k;
	cin >> state[2];
	for (state[1] = Intercept<int>(1, 2); state[1] <= state[2]; state[1]++)
	{
		cin >> state[3];
		state[0] = 0;
		a[0] = 2;
		search(1, state[3]);
		cout << state[0] << endl;
	}
	return 0;
}
