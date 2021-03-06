#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//*********************************
//* file?1.cpp
//* description: ????
//* author: ?? 1200012858
//* date: 2012-12-1
//*********************************
Intercept<int> decompose(int x, Intercept<int> y);
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> n, m;
	cin >> n;
	for (state[0] = Intercept<int>(1, 2); state[0] <= n; state[0]++)
	{
		cin >> m;
		cout << decompose(m, 2) << endl;
	}
	return 0;
}
Intercept<int> decompose(int x, Intercept<int> y)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> b; // sum(1, 3),
	b = (int)sqrt(x);
	if (x == 1)
		return 0;
	for (state[1] = Intercept<int>(y, 2); state[1] <= b; state[1]++)
	{
		if (x % state[1] == 0)
		{
			state[0] = state[0] + decompose(x / state[1], state[1]);
		}
	}
	return state[0];
}
