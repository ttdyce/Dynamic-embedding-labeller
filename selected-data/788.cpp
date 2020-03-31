#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> Factorization(Intercept<int>, Intercept<int>);
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> n, x, i, k;
	cin >> n;
	for (state[0] = Intercept<int>(0, 2); state[0] < n; state[0]++)
	{
		cin >> x;
		cout << Factorization(x, 2) + 1 << endl;
	}
	return 0;
}
Intercept<int> Factorization(Intercept<int> x, Intercept<int> y)
{
	Intercept<int> intercepts[] = {Intercept<int>(y, 2), Intercept<int>(0, 3) };
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> i;
	// Intercept<int> sum(0, 3);
	if (x < 4)
		return 0;
	else
	{
		for (state[0] = Intercept<int>(y, 2); state[0] <= sqrt((double)x); state[0]++)
			if (x % state[0] == 0)
				state[1] += 1 + Factorization(x / state[0], state[0]);
		return state[1];
	}
}
