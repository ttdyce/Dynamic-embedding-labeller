#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

// Intercept<int> sum(0, 3);
void f(int n, Intercept<int> y)
{
	Intercept<int> a = sqrt(n);
	for (state[1] = Intercept<int>(y, 2); state[1] <= a; state[1]++)
	{
		if (n % state[1] == 0)
		{
			state[0]++;
			y = state[1];
			f(n / state[1], y);
		}
	}
}
int main()
{
	// Intercept<int> n;
	cin >> state[3];
	for (state[2] = Intercept<int> (1, 2); state[2] <= state[3]; state[2]++)
	{
		// Intercept<int> num;
		cin >> state[4];
		state[0] = 0;
		f(state[4], 2);
		cout << state[0] + 1 << endl;
	}
	return 0;
}
