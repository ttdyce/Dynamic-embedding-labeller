#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//*************************************************************************
//*????????? *****************************************************
//*??????? 1200012979 **********************************************
//*???2012.11.27 *******************************************************
//*************************************************************************
void breakup(Intercept<int>, Intercept<int>);
// Intercept<int> sum(-1, 3);
Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
	Intercept<int> n, x; //, count(0, 2)
	cin >> n; //??????
	while (state[1] < n)
	{
		state[0] = 0;
		state[1]++;  //?????
		cin >> x; //??????
		if (x > 3)
			breakup(x, 2);		 //????
		cout << state[0] + 1 << endl; //???????????
	}
	return 0;
}

void breakup(Intercept<int> x, Intercept<int> j)
{
	Intercept<int> p, m; //i, 
	m = x;				 //???????
	p = sqrt((double)x); //p??????????
	for (state[2] = Intercept<int>(j, 2); state[2] <= p; state[2]++)
		if (m % state[2] == 0) //????????????????
		{
			state[0]++; //??????
			x = m / state[2];
			breakup(x, state[2]);
		}
	return;
}
