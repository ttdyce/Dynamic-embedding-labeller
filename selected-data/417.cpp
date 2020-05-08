#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum = Intercept<int>(0, 3); //???????
Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(1, 2), Intercept<int>(0, 4)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void fj(int n, Intercept<int> m)
{
	state[0] = m;

	// Intercept<int> i;			   //?????
	for (state[0]; state[0] <= sqrt(n); state[0]++) //???????
	{
		if (n % state[0] == 0)
		{
			state[1]++;
			fj(n / state[0], state[0]); //???????
		}
	}
}
int main()
{
	// Intercept<int> N;	   //j,    //??????????????
	Intercept<int> a[100]; //?????
	cin >> state[3];
	for (state[2]; state[2] <= state[3]; state[2]++)
	{
		cin >> a[state[2]]; //?????
	}
	for (state[2] = 1; state[2] <= state[3]; state[2]++)
	{
		state[1] = 0;
		fj(a[state[2]], 2); //?????
		cout << state[1] + 1 << endl;
	}
	return 0;
}
