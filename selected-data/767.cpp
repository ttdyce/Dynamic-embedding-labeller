#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> divide(int n, Intercept<int> j)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(j, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> i, s, p, k; //  state[0] = Intercept<int>(1, 3), 
	s = sqrt(n);
	for (state[1] = Intercept<int>(j, 2); state[1] <= s; state[1]++)
	{
		if (n % state[1] == 0)
		{
			p = n / state[1];
			k = state[1];
			state[0] = state[0] + divide(p, state[1]);
		}
	}
	return state[0];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> n;
	cin >> n;
	Intercept<int> m, p; // k, 
	for (state[0] = Intercept<int>(0, 2); state[0] < n; state[0]++)
	{
		cin >> m;
		p = divide(m, 2);
		cout << p << endl;
	}
	return 0;
}
