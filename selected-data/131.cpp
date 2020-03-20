#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> num(Intercept<int> a, Intercept<int> b, Intercept<int> c) //??????????
{
	// Intercept<int> sum(0,3), j(-1,2); //sum????
	Intercept<int> intercepts[2] = {Intercept<int>(0, 3), Intercept<int>(-1, 2)};
	StateIntercept state(intercepts, 2);
	if (a > c)
		return 0; //???????????????0
	if (b == 1)
		return 1;								  //????????????????
	for (state[1] = a; state[1] <= c; state[1]++) //?????????????
		if (c % state[1] == 0)
			state[0] = state[0] + num(state[1], b - 1, c / state[1]);
	return state[0];
}
int main()
{
	Intercept<int> k, n, m; //e??????
	// Intercept<int> k, n, m, e(-1, 2), i(-1, 2); //e??????
	Intercept<int> intercepts[2] = {Intercept<int>(-1, 2), Intercept<int>(-1, 2)};
	StateIntercept state(intercepts, 2);
	cin >> n;
	while (state[0] < n)
	{
		cin >> m;
		k = 0; //k??m????????????????
		Intercept<int> f = m;
		for (state[1] = 2; state[1] <= f; state[1]++)
			if (f % state[1] == 0)
			{
				k++;
				f = f / state[1];
				state[1] = 1;
			}
		cout << num(1, k, m) << endl; //????????
		state[0]++;
	}
	return 0;
}
