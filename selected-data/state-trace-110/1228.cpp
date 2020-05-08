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

	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> sum(0, 3); //??
	for (state[1] = Intercept<int> (i, 2); state[1] <= sqrt(a); state[1]++)
	{ //?i???a??
		if (a % state[1] != 0)
			continue; //??????
		state[0]++;		  //??????1
		if (a >= state[1] * state[1])
			state[0] += ans(a / state[1], state[1]); //????????????????????
	}
	return state[0];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> n, a; //???????
	cin >> n;
	for (state[0] = Intercept<int> (0, 2); state[0] < n; state[0]++)
	{
		cin >> a;
		cout << ans(a, 2) + 1 << endl;
	}
	return 0;
}
