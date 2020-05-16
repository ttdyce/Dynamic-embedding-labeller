#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// ????2.cpp : ??????????????
//

void out(int, Intercept<int>);

// Intercept<int> t(1, 2);
Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int> (1, 2), Intercept<int> (0, 4), Intercept<int> (0, 4), Intercept<int> (1, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
	// Intercept<int> n = 0;
	// Intercept<int> i = Intercept<int>(0, 2);
	// double sum = 0;
	cin >> state[2];

	for (state[0] = 1; state[0] <= state[2]; state[0]++)
	{
		cin >> state[3];
		out(state[3], 2.0);
		cout << state[1] << endl;
		state[1] = 1;
		state[4] = 1;
	}

	cin >> state[0];

	return 0;
}

void out(int sum, Intercept<int> q)
{

	Intercept<int> num = 0;
	double m = sum;
	num = sqrt(m);
	if (sum % q == 0 && q <= num)
	{
		state[1]++;
		state[4]++;
		out(sum / q, q);
		out(sum, q + 1);
	}
	if (sum % q != 0 && q <= num)
		out(sum, q + 1);
}
