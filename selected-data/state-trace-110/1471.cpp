#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//*************************************
//   ????**
//   ?? 1200012872**
//   2012.11.27**
//*************************************

Intercept<int> factorization(Intercept<int> a, Intercept<int> k);

int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> n, a;
	cin >> n;
	for (state[0] = Intercept<int>(0, 2); state[0] < n; state[0]++) //??????????????
	{
		cin >> a;
		cout << factorization(a, 2) << endl;
	}
	return 0;
}

Intercept<int> factorization(Intercept<int> a, Intercept<int> k)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int> (0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> sum(1, 3); //???????
	if (a == 1)				  //??a?1?????
	{
		return 0;
	}
	if (a == 2) //??a?2???????
	{
		return 1;
	}
	Intercept<int> b = (int)sqrt((double)a);  //?b?a??????
	for (state[1] = Intercept<int> (k, 2); state[1] <= b; state[1]++) //??a???state[1]??????????????????
	{
		if (a % state[1] == 0)
		{
			state[0] += factorization(a / state[1], state[1]);
		}
	}
	return state[0]; //??sum?
}
