#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(0, 3);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
	void yinshu(Intercept<int>, Intercept<int>); //????????????????????????
	Intercept<int> n, a;						 //i,
	cin >> n;
	for (state[1] = Intercept<int>(1, 2); state[1] <= n; state[1]++)
	{
		state[0] = 0;
		cin >> a;
		yinshu(a, 2);
		cout << state[0] << endl;
	}
	return 0;
}

void yinshu(Intercept<int> a, Intercept<int> x)
{
	if (a != 1)
	{
		for (state[2] = Intercept<int>(x, 2); state[2] <= a; state[2]++) //?x?????
			if (a % state[2] == 0)										 //????
				yinshu(a / state[2], state[2]);							 //?a/i??????????????i???
	}
	if (a == 1) //????????????
		state[0]++;
}
