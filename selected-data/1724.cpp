#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/*Intercept<int> hf[32768][32768]={0};
Intercept<int> work(Intercept<int> m,Intercept<int> n)
{
	if(hf[m][n]!=0)
	return hf[m][n];
	if(m%n!=0)
	{
		hf[m][n]=0;
		return 0;
	}
	for(Intercept<int> i=n;i<=m/n;i++)
	hf[m][n]+=work(m/n,i);
	return hf[m][n];
}*/
Intercept<int> work(Intercept<int> m, Intercept<int> n)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 8), Intercept<int>(0, 8), Intercept<int>(0, 5)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	if (m == n)
	{
		state[2] = 1;
		return 1;
	}
	if (m % n != 0)
	{
		state[3] = 1;
		return 0;
	}
	// Intercept<int> sum(0, 3);
	for (state[1] = Intercept<int>(n, 2); state[1] <= m / n; state[1]++)
	{
		state[0] += work(m / n, state[1]);
		state[4] += state[0];
	}
	return state[0];
}
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n, m, a;
	cin >> state[3];
	Intercept<int> i, j, k;
	for (state[1] = Intercept<int>(1, 2); state[1] <= state[3]; state[1]++)
	{
		cin >> state[4];
		// Intercept<int> s(0, 3);
		for (state[2] = Intercept<int>(2, 2); state[2] <= state[4]; state[2]++)
			state[0] += work(state[4], state[2]);
		cout << state[0] << endl;
	}
	return 0;
}
