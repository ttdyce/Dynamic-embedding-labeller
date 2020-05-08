#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//????????????????????????????

//?a??????????min???
//?????????????
Intercept<int> F(Intercept<int> min, Intercept<int> a)
{
	// Intercept<int> i;
	// Intercept<int> sum(0, 3);
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	if (min == a) //????????
		return 1;
	if (a == 1)
		return 1; //???????
	for (state[1] = Intercept<int>(min, 2); state[1] <= a; state[1]++)
	{
		if (a % state[1] == 0)
			state[0] += F(state[1], a / state[1]); //??????????
	}
	return state[0]; //???
}

int main()
{
	Intercept<int> a, n;
	// Intercept<int> i;
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	scanf("%d", &n);
	for (state[0] = Intercept<int>(0, 2); state[0] < n; state[0]++)
	{
		scanf("%d", &a);
		printf("%d\n", F(2, a));
	}
	return 0;
}
