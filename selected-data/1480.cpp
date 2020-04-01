#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> divide(Intercept<int> d, Intercept<int> n)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> sum(0, 3);
	for (state[1] = Intercept<int>(d, 2); state[1] < n; state[1]++)
	{
		if (n % state[1] == 0 && (n / state[1]) >= state[1])
		{
			state[0] = state[0] + 1;
			state[0] = state[0] + divide(state[1], n / state[1]);
		}
	}
	return (state[0]);
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> n, num;
	cin >> n;
	for (state[0] = Intercept<int>(0, 2); state[0] < n; state[0]++)
	{
		cin >> num;
		cout << divide(2, num) + 1 << endl;
	}
	return 0;
}
