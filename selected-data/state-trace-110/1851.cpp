#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 3)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

// Intercept<int> sum(0, 3);
void f(Intercept<int> x, Intercept<int> y)
{
	state[1] = Intercept<int>(y, 2);

	if (x == 1)
		state[0]++;
	while (state[1] <= x)
	{
		if (x % state[1] == 0)
			f(x / state[1], state[1]);
		state[1]++;
	}
}
int main()
{
	Intercept<int> n, i, a;
	cin >> n;
	for (state[2] = Intercept<int>(1, 2); state[2] <= n; state[2]++)
	{
		cin >> a;
		// Intercept<int> j(2, 2), num(1, 3);
		while (state[3] <= a / 2)
		{
			if (a % state[3] == 0)
			{
				state[0] = 0;
				f(a / state[3], state[3]);
				state[4] += state[0];
			}
			state[3]++;
		}
		printf("\n%d", state[4]);
	}
	return 0;
}
