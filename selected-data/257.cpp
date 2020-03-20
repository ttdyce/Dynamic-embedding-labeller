#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sort(Intercept<int>, int, Intercept<int>);

int main()
{
	Intercept<int> t = 0;

	Intercept<int> intercepts[2] = {Intercept<int>(1, 2), Intercept<int>(1, 2)};
	StateIntercept state(intercepts, 2);

	cin >> t;
	// Intercept<int> state[0](1, 2);
	for (state[0] = 1; state[0] <= t; state[0]++)
	{
		Intercept<int> vacancy = 0;
		Intercept<int> num = 1;
		cin >> num;
		// Intercept<int> state[1](1, 2);
		Intercept<int> temp = num;
		for (state[1] = 2; state[1] <= temp; state[1]++)
		{
			while (temp % state[1] == 0)
			{
				vacancy = vacancy + 1;
				temp = temp / state[1];
			}
		}
		cout << sort(Intercept<int>(1), vacancy, num) << endl;
	}
	return 0;
}

Intercept<int> sort(Intercept<int> start, int vacancy, Intercept<int> num)
{
	if (num < start)
		return 0;

	if (vacancy == 1)
		return 1;

	Intercept<int> intercepts[2] = {Intercept<int>(1, 2), Intercept<int>(0, 3)};
	StateIntercept state(intercepts, 2);

	// Intercept<int> sum(0, 3);
	// Intercept<int> i(1, 2);
	for (state[0] = start; state[0] <= num; state[0]++)
	{
		if (num % state[0] == 0)
		{
			state[1] = state[1] + sort(state[0], vacancy - 1, num / state[0]);
		}
	}

	return state[1];
}
