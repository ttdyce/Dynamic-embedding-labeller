#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> fact(Intercept<int> n, Intercept<int> m); //????fact
int main()												 //?????
{
    int length = 1;
    Intercept<int> intercepts[length] = {Intercept<int>(0, 2)};
    StateIntercept state(intercepts, length);

	Intercept<int> n, a[35000], i, b[35000];
	cin >> n;
	for (state[0] = 0; state[0] < n; state[0]++)
		cin >> a[state[0]]; //???????????
	for (state[0] = 0; state[0] < n; state[0]++)
		b[state[0]] = fact(a[state[0]], 2); //?????????????????fact(a[state[0]],2)
	for (state[0] = 0; state[0] < n; state[0]++)
		cout << b[state[0]] << endl; //????????
	return 0;
} //?????
Intercept<int> fact(Intercept<int> n, Intercept<int> m) //fact??
{
    int length = 2;
    Intercept<int> intercepts[length] = {Intercept<int>(1, 3), Intercept<int>(-1, 2)};
    StateIntercept state(intercepts, length);

	Intercept<int> temp = 0; //sum(1, 3), i(-1, 2), 
	if (n < m)
		return 0; //?n<m,?????0
	else if (n == 2)
		return 1; //?n???2??????1
	else
	{
		for (state[1] = m; state[1] < n; state[1]++) //??????m?n
		{
			if (n % state[1] == 0)
				state[0] = state[0] + fact(n / state[1], state[1]);
		} //?n??i????state[0]??fact(n/i,i)??,????
		return state[0];
	}
} //fact??
