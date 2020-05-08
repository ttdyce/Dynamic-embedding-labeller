#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> fenjieyinshi(Intercept<int> n, Intercept<int> m) //????????
{
    int length = 2;
    Intercept<int> intercepts[length] = {Intercept<int>(0, 2), Intercept<int>(1, 3)};
    StateIntercept state(intercepts, length);

	// Intercept<int> i(0, 2);
	// Intercept<int> sum(1, 3);
	if (n < m)
		return 0; //??????????????????0
	else
	{
		for (state[0] = m; state[0] < n; state[0]++)
			if (n % state[0] == 0)					   //????????????????
				state[1] += fenjieyinshi(n / state[0], state[0]); //??
		return state[1];
	}
}
int main() //???
{		   //?????
    int length = 1;
    Intercept<int> intercepts[length] = {Intercept<int>(0, 2)};
    StateIntercept state(intercepts, length);

	Intercept<int> n = 0;
	// Intercept<int> i(0, 2);
	Intercept<int> a = 0;
	cin >> n; //???????????????
	for (state[0] = 0; state[0] < n; state[0]++)
	{
		cin >> a; //???????
		if (a == 1)
			cout << 1 << endl;
		else
			cout << fenjieyinshi(a, 2) << endl; //????
	}
	return 0;
} //?????
