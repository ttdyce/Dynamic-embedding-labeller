#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(0, 3);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 8), Intercept<int>(0, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void fenjie(Intercept<int> t, Intercept<int> n)
{
	// Intercept<int> i(0, 2);
	if (n == 1){
		state[4] = 1;
		state[0]++;
		state[5]++;
	}for (state[1] = t; state[1] <= n; state[1]++)
	{
		if (n % state[1] == 0)
		{
			fenjie(state[1], n / state[1]);
		}
	}
}
int main()
{
	// Intercept<int> k = 0; //n(0, 2), 
	cin >> state[2];
	while (state[2] > 0)
	{
		cin >> state[3];
		state[0] = 0;
		state[5] = 0;
		fenjie(2, state[3]);
		state[2]--;
		cout << state[0] << endl;
	}
	return 0;
}
