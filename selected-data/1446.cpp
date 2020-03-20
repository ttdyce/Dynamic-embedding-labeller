#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(0, 3);
int main()
{
	void yinshu(Intercept<int>, Intercept<int>); //????????????????????????
	Intercept<int> i, n, a;
	cin >> n;
	for (i = Intercept<int>(1, 2); i <= n; i++)
	{
		sum = 0;
		cin >> a;
		yinshu(a, 2);
		cout << sum << endl;
	}
	return 0;
}

void yinshu(Intercept<int> a, Intercept<int> x)
{
	if (a != 1)
	{
		for (Intercept<int> i(x, 2); i <= a; i++) //?x?????
			if (a % i == 0)						//????
				yinshu(a / i, i);				//?a/i??????????????i???
	}
	if (a == 1) //????????????
		sum++;
}
