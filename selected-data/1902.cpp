#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> n;
Intercept<int> next(Intercept<int> a, Intercept<int> b)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 3)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// b = Intercept<int>(b, 2);
	state[0] = Intercept<int>(b, 2);

	if (a == 1)
		return 1;
	if (a < state[0])
		return 0;
	// Intercept<int> sum(0, 3);
	for (; state[0] <= a; state[0] = state[0] + 1)
		if (a % state[0] == 0)
			state[1] = state[1] + next(a / state[0], state[0]);

	return state[1];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> i, m;
	cin >> m;
	for (state[0] = Intercept<int>(0, 2); state[0] < m; state[0] = i + 1)
	{
		cin >> n;
		cout << next(n, 2) << endl;
	}
	return 0;
}
