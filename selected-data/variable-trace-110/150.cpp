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
void calculate(int, Intercept<int>);

int main()
{
	Intercept<int> n(-1, 1);
	cin >> n;
	for (Intercept<int> i(0, 2); i < n; i++)
	{
		int m;
		sum = Intercept<int>(1,3);
		cin >> m;
		calculate(m, Intercept<int>(2));
		cout << sum << endl;
	}
	return 0;
}
void calculate(int m, Intercept<int> begin)
{
	Intercept<int> i;
	Intercept<int> n = sqrt((double)m);
	for (i = Intercept<int>(begin, 2); i <= n; i++)
	{
		if (m % i == 0)
		{
			sum++;
			calculate(m / i, Intercept<int>(i, 1));
		}
	}
}
