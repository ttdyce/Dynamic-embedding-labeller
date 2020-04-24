#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> Factorization(Intercept<int> n, Intercept<int> k)
{							  //????????
	// Intercept<int> sum(0, 3); //??????sum??????????
	Intercept<int> intercepts[] = {Intercept<int>(0, 3)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	if (n < k)
	{			  //?????????k
		return 0; //??0
	}
	if (n % k == 0)
	{ //????????k???
		if (n == k)
		{			  //?n?k???
			return 1; //??1
		}
		else
		{
			state[0] = state[0] + Factorization(n, k + 1) + Factorization(n / k, k); //??????????
		}
	}
	else
	{
		state[0] = state[0] + Factorization(n, k + 1); //?????????k????????
	}
	return state[0]; //??sum??
}

int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> t, a; //???????t???????i??????a??????? i, 
	cin >> t;				//????????
	for (state[0] = Intercept<int>(1, 2); state[0] <= t; state[0]++)
	{ //?????????
		cin >> a;
		cout << Factorization(a, 2) << endl;
	}
	return 0;
}
