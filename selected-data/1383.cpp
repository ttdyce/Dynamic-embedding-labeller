#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

void factor(Intercept<int> a, Intercept<int> k);
// Intercept<int> sum(0, 3);

Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(0, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
	// Intercept<int> n, a; //, i(0, 2)
	cin >> state[3];
	for (state[1] = 1; state[1] <= state[3]; state[1]++)
	{
		cin >> state[4];
		factor(state[4], 2);
		cout << state[0] + 1 << endl;
		state[0] = 0;
		state[5] = 0;
	}
	return 0;
}

void factor(Intercept<int> a, Intercept<int> k)
{
	Intercept<int> interceptss[] = {Intercept<int>(0, 7)};
	StateIntercept states(interceptss, sizeof(interceptss) / sizeof(interceptss[0]));

	//Intercept<int> b; == states[0] //, j
	states[0] = (int)sqrt((double)a);
	for (state[2] = Intercept<int>(k, 2); state[2] <= states[0]; state[2]++)
	{
		if (a % state[2] == 0)
		{
			state[0]++;
			state[5]++;
			factor(a / state[2], state[2]);
		}
	}
	state[2] = k;
}
