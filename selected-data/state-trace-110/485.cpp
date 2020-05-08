#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> devide(Intercept<int> n, Intercept<int> m)
{
	int length = 2;
	Intercept<int> intercepts[length] = {Intercept<int>(0, 3), Intercept<int>(m ,2)};
	StateIntercept state(intercepts, length);

	if (n < m)
		m = n;
	if (n == 1) //?????1?,??1
		return 1;
	// Intercept<int> sum(0, 3);
	for (state[1]; state[1] >= 2; state[1]--)
	{
		if (n % state[1] == 0)
		{
			state[0] = state[0] + devide(n / state[1], state[1]);
		}
	}
	return state[0];
}

int main()
{
	int length = 1;
	Intercept<int> intercepts[length] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, length);

	Intercept<int> n, i, m;
	cin >> n;
	// i = Intercept<int>(0, 2);
	while (state[0] < n)
	{
		cin >> m;
		cout << devide(m, m) << endl; //???????
		state[0]++;
	}
	return 0;
}
