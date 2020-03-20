#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//**********************
//* ???   ????  *
//* 1200012878 ???  *
//* 12?1?            *
//**********************
Intercept<int> fengjie(int a, Intercept<int> b)
{
	if (a == 2 || a == 3)
		return 1;
	Intercept<int> sum(1, 3);
	Intercept<int> c = sqrt(a);
	for (Intercept<int> i(b, 2); i <= c; i++)
	{
		if (a % i == 0)
		{
			sum = sum + fengjie(a / i, i);
		}
	}
	return sum;
}
int main()
{
	Intercept<int> n, a;
	cin >> n;
	for (Intercept<int> i(1, 2); i <= n; i++)
	{
		cin >> a;
		cout << fengjie(a, 2) << endl;
	}
	return 0;
}
