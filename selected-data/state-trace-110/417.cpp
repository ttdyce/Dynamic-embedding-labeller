#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum = Intercept<int>(0, 3); //???????
Intercept<int> intercepts[3] = {Intercept<int>(0, 2), Intercept<int>(0, 3), Intercept<int>(1, 2)};
StateIntercept state(intercepts, 3);

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
	Intercept<int> N;	  //j,    //??????????????
	Intercept<int> a[100]; //?????
	cin >> N;
	for (state[2]; state[2] <= N; state[2]++)
	{
		cin >> a[state[2]]; //?????
	}
	for (state[2] = 1; state[2] <= N; state[2]++)
	{
		state[1] = 0;
		fj(a[state[2]], 2); //?????
		cout << state[1] + 1 << endl;
	}
	return 0;
}
