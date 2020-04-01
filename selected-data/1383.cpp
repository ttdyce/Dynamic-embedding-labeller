#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

void factor(Intercept<int> a, Intercept<int> k);
// Intercept<int> sum(0, 3);

Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
	Intercept<int> n, a; //, i(0, 2)
	cin >> n;
	for (state[1] = 1; state[1] <= n; state[1]++)
	{
		cin >> a;
		factor(a, 2);
		cout << state[0] + 1 << endl;
		state[0] = 0;
	}
	return 0;
}

void factor(Intercept<int> a, Intercept<int> k)
{
	Intercept<int> b; //, j
	b = (int)sqrt((double)a);
	for (state[2] = Intercept<int>(k, 2); state[2] <= b; state[2]++)
	{
		if (a % state[2] == 0)
		{
			state[0]++;
			factor(a / state[2], state[2]);
		}
	}
	state[2] = k;
}
