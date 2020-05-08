#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/*
 *?????
 *???2010 - 12 - 07
 *?????????  ????
 */
Intercept<int> num(Intercept<int>, Intercept<int>, Intercept<int>);
Intercept<int> qufen(Intercept<int>);
Intercept<int> power(Intercept<int>, Intercept<int>);
int main()
{
    int length = 3;
    Intercept<int> intercepts[length] = {Intercept<int>(-1, 2), Intercept<int>(-1, 2), Intercept<int>(1, 3)};
    StateIntercept state(intercepts, length);

	// Intercept<int> state[0](-1, 2);
	cin >> state[0];
	while (state[0] >= 1)
	{
		Intercept<int> n, x; //, sum(1, 3), state[1](-1, 2);
		cin >> n;
		x = qufen(n); //qufen????????????????????
		for (state[1] = 2; state[1] <= x; state[1]++)
			state[2] = state[2] + num(n, state[1], 2); //num?????????????i????????
		cout << state[2] << endl;
		state[0]--;
	}
	return 0;
}
Intercept<int> qufen(Intercept<int> n)
{
    int length = 1;
    Intercept<int> intercepts[length] = {Intercept<int>(1, 2)};
    StateIntercept state(intercepts, length);

	// Intercept<int> j;
	for (state[0] = Intercept<int>(1, 2);; state[0]++)
	{
		if (power(2, state[0]) > n)
		{
			return state[0] - 1;
			break;
		}
	}
}
Intercept<int> power(Intercept<int> a, Intercept<int> b)
{
    int length = 2;
    Intercept<int> intercepts[length] = {Intercept<int>(1, 3), Intercept<int>(-1, 2)};
    StateIntercept state(intercepts, length);

	// Intercept<int> sum(1, 3), k(-1, 2);
	for (state[1] = 1; state[1] <= b; state[1]++) //?????????
		state[0] = state[0] * a;
	return state[0];
}
Intercept<int> num(Intercept<int> n, Intercept<int> g, Intercept<int> h)
{
    int length = 2;
    Intercept<int> intercepts[length] = {Intercept<int>(-1, 2), Intercept<int>(0, 3)};
    StateIntercept state(intercepts, length);

	if ((g == 1) && (n >= h)) //???????
		return 1;
	Intercept<int> j = 0, a[20000]; //, i(-1, 2), count(0, 3)
	for (state[0] = h; state[0] < n; state[0]++) //???????????? n ?? i ?? g ??????n / i????? g - 1?
	{						//?n = i * ……?g?? ???? n / i = h * ……(g - 1 ???h??????i???
		if (n % state[0] == 0)
		{
			a[j] = state[0];
			j++;
		}
	}
	if (j == 0) //j == 0?????????????????
		return 0;
	else
	{
		for (state[0] = 0; state[0] < j; state[0]++)
			state[1] = state[1] + num(n / a[state[0]], g - 1, a[state[0]]);
		return state[1];
	}
}
