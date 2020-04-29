#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> devide(Intercept<int> n, Intercept<int> m)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(m ,2)};
    StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	if (n < m)
		m = n;
	if (n == 1) //?????1?,??1
		return 1;
	// Intercept<int> sum(0, 3);
	for (state[1]; state[1] >= 2; state[1]--)
	{
		if (n % state[1] == 0)
		{
			state[0] = state[0] + devide(n / state[1], state[1]);
		}
	}
	return state[0];
}

int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
    StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n, i, m;
	cin >> state[1];
	// i = Intercept<int>(0, 2);
	while (state[0] < state[1])
	{
		cin >> state[2];
		cout << devide(state[2], state[2]) << endl; //???????
		state[0]++;
	}
	return 0;
}
