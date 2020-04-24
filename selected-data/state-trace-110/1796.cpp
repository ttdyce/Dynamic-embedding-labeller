#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> breakways(Intercept<int> num, Intercept<int> min);
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> n;
	cin >> n;
	Intercept<int> number;
	for (state[0] = Intercept<int>(1, 2); state[0] <= n; state[0]++)
	{
		cin >> number;
		cout << breakways(number, 2) << endl;
	}
}

Intercept<int> breakways(Intercept<int> num, Intercept<int> min)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> sum(0, 3);
	for (state[1] = Intercept<int>(min, 2); state[1] <= num; state[1]++)
	{
		if (num % state[1] == 0)
		{
			if (num != state[1])
				state[0] += breakways(num / state[1], state[1]);
			else
				state[0] += 1;
		}
	}
	return state[0];
}
