#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> num = 0;
Intercept<int> sum(Intercept<int> a, Intercept<int> i)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// i = Intercept<int>(i, 2);
	state[0] = Intercept<int>(i, 2);

	if (a == 1)
	{
		num++;
	}
	else
	{
		while (i <= a)
		{
			if (a % i == 0)
			{
				sum(a / i, i);
			}
			i++;
		}
	}
	return num;
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> a, t, j, count; //i, 
	cin >> t;
	for (state[0] = Intercept<int>(0, 2); state[0] < t; state[0]++)
	{
		count = 1;
		cin >> a;
		state[1] = Intercept<int>(2, 2);
		while (state[1] <= (a / 2))
		{
			if (a % state[1] == 0)
			{
				num = 0;
				sum(a / state[1], state[1]);
				count = count + num;
			}
			state[1]++;
		}
		cout << count << endl;
	}

	return 0;
}
