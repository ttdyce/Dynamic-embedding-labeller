#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//**********************
//* ???   ????  *
//* 1200012878 ???  *
//* 12?1?            *
//**********************
Intercept<int> fengjie(int a, Intercept<int> b)
{
	if (a == 2 || a == 3)
		return 1;

	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(1, 5), Intercept<int>(0,7)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> sum(1, 3);
	// Intercept<int> c == state[3]
	state[3] = sqrt(a);
	for (state[1] = Intercept<int>(b, 2); state[1] <= state[3]; state[1]++)
	{
		if (a % state[1] == 0)
		{
			state[0] = state[0] + fengjie(a / state[1], state[1]);
			state[2] = state[0];
		}
	}
	return state[0];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n, a;
	cin >> state[1];
	for (state[0] = Intercept<int>(1, 2); state[0] <= state[1]; state[0]++)
	{
		cin >> state[2];
		cout << fengjie(state[2], 2) << endl;
	}
	return 0;
}
