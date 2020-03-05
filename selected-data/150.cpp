#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;


/**
* @author ??
* @date 2010-12-1
* @description
* ??????:???? 
*/
Intercept<int> sum;
void calculate(int, int);


int main()
{
	Intercept<int> n;
	cin >> n;
	for (Intercept<int> i = 0; i < n;i++)
	{
		Intercept<int> m;
		sum  = 1;
		cin >> m;
		calculate(m, 2);
		cout << sum << endl;
	}
	return 0;
}
void calculate(Intercept<int> m,Intercept<int> begin)
{
	Intercept<int> i;
	Intercept<int> n = sqrt((double)m);
	for ( i = begin; i <= n; i++ )
	{
		if ( m % i == 0)
		{
			sum++;
			calculate(m / i,i);
		}
	}
}
