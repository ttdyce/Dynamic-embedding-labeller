#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

void fenjie(Intercept<int>, Intercept<int>, Intercept<int>);

Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4)};
StateIntercept gState(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

// Intercept<int> g_num, g_count;
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(-1, 2), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n; //, i(-1, 2);
	cin >> state[1];
	for (state[0] = 1; state[0] <= state[1]; state[0]++)
	{
		// g_count = 0;
		cin >> gState[1];
		fenjie(2, gState[1], 1);
		cout << gState[0] << endl;
	}
	return 0;
}
void fenjie(Intercept<int> a, Intercept<int> num, Intercept<int> sum)
{
	int length = 2;
	Intercept<int> intercepts[length] = {Intercept<int>(a, 2), Intercept<int>(sum, 3)};
	StateIntercept state(intercepts, length);

	// a = Intercept<int>(a, 2);
	// sum = Intercept<int>(sum, 3);
	while (state[0] <= gState[1])
	{
		state[1] *= state[0];
		if (state[1] == gState[1])
			gState[0]++;
		if (state[1] < gState[1])
			fenjie(state[0], gState[1], state[1]);
		if (state[1] > gState[1])
			return;
		state[1] /= state[0];
		state[0]++;
	}
}
