#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> fenjieyinshi(Intercept<int> n, Intercept<int> m) //????????
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(1, 3), Intercept<int>(0, 6)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> i(0, 2);
	// Intercept<int> sum(1, 3);
	if (n < m)
	{
		state[2] = 1;
		return 0; //??????????????????0
	}
	else
	{
		for (state[0] = m; state[0] < n; state[0]++)
			if (n % state[0] == 0)								  //????????????????
				state[1] += fenjieyinshi(n / state[0], state[0]); //??
		return state[1];
	}
}
int main() //???
{		   //?????
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n = 0;
	// Intercept<int> i(0, 2);
	// Intercept<int> a = 0;
	cin >> state[1]; //???????????????
	for (state[0] = 0; state[0] < state[1]; state[0]++)
	{
		cin >> state[2]; //???????
		if (state[2] == 1)
			cout << 1 << endl;
		else
			cout << fenjieyinshi(state[2], 2) << endl; //????
	}
	return 0;
} //?????
