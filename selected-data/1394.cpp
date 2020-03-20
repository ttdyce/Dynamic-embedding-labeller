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
Intercept<int> sum(-1, 3);
int main()
{
	Intercept<int> n, x, count(0, 2);
	cin >> n; //??????
	while (count < n)
	{
		sum = 0;
		count++;  //?????
		cin >> x; //??????
		if (x > 3)
			breakup(x, 2);		 //????
		cout << sum + 1 << endl; //???????????
	}
	return 0;
}

void breakup(Intercept<int> x, Intercept<int> j)
{
	Intercept<int> i, p, m;
	m = x;				 //???????
	p = sqrt((double)x); //p??????????
	for (i = Intercept<int>(j, 2); i <= p; i++)
		if (m % i == 0) //????????????????
		{
			sum++; //??????
			x = m / i;
			breakup(x, i);
		}
	return;
}
