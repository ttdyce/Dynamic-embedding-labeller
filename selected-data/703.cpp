#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(Intercept<int> x, int y) //???????????????y?????????x????????
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 3), Intercept<int>(x, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> i;
	Intercept<int> a[100];
	// Intercept<int> sum = 0, num(0, 3);
	for (state[2]; state[2] <= sqrt(y); state[2]++)
	{
		if (y % state[2] == 0)
		{
			state[0]++;
			a[state[0]] = 1 + f(state[2], y / state[2]);
		}
	} //??????
	for (state[2] = 1; state[2] <= state[0]; state[2]++)
	{
		state[1] = state[1] + a[state[2]];
	}
	return state[1];
}

int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> b[100]; //i n, x, 
	cin >> state[1]; //?????????
	for (state[0]; state[0] <= state[1]; state[0]++)
	{
		cin >> state[2];
		b[state[0]] = state[2];
	}
	for (state[0] = 1; state[0] <= state[1]; state[0]++)
	{
		cout << f(2, b[state[0]]) + 1 << endl;
	} //???????

	return 0;
}
