#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> p = 0;

Intercept<int> factor(Intercept<int> a, Intercept<int> min)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> sum = Intercept<int>(0, 3);
	if (min >= a)
		return 1;
	for (state[1] = Intercept<int>(min, 2); state[1] <= a / min; state[1]++)
		if (a % state[1] == 0)
			state[0] += factor(a / state[1], state[1]);
	return state[0];
}

int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> a = 0; //n = Intercept<int>(0, 2), 
	cin >> state[0];
	while (state[0] > 0)
	{
		cin >> state[1];
		if (state[1] <= 2)
			cout << 1 << endl;
		else
			cout << factor(state[1], 2) + 1 << endl;
		state[0]--;
	}
	return 0;
}
