#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
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
		Intercept<int> intercepts[2] = {Intercept<int>(i, 2), Intercept<int>(0, 3)};
		StateIntercept state(intercepts, 2);

		// Intercept<int> j(i, 2);
		// Intercept<int> sum(0, 3);
		while (state[0] <= m)
		{
			if (state[0] != 1 && m % state[0] == 0)
				state[1] = state[1] + devide(m / state[0], x - 1, state[0]);
			state[0]++;
		}
		return state[1];
	}
	return 0;
}

int main()
{
	Intercept<int> intercepts[3] = {Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(1, 2)};
	StateIntercept state(intercepts, 3);

	Intercept<int> n, a;
	cin >> n;
	for (state[0] = 0; state[0] < n; state[0]++)
	{
		// Intercept<int> sum(0, 3);
		cin >> a;
		for (state[2]; state[2] <= 16; state[2]++)
			state[1] += devide(a, state[2], 1);
		cout << state[1] << endl;
	}
	return 0;
}
