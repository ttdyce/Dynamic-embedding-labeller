#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> cut(int m, Intercept<int> l)
{
	int length = 2;
	Intercept<int> intercepts[length] = {Intercept<int>(1, 3), Intercept<int>(l, 2)};
	StateIntercept state(intercepts, length);

	// Intercept<int> sum(1, 3);
	for (state[1]; state[1] <= sqrt((double)m / l); state[1]++)
	{
		if ((m / l) % state[1] == 0)
		{
			state[0] += cut(m / l, state[1]);
		}
	}
	return state[0];
}

int main()
{
	int length = 1;
	Intercept<int> intercepts[length] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, length);

	Intercept<int> n;
	cin >> n;
	for (state[0]; state[0] < n; state[0]++)
	{
		Intercept<int> t = 0;
		cin >> t;
		cout << cut(2 * t, 2);
		if (state[0] < n - 1)
			cout << endl;
	}
}
