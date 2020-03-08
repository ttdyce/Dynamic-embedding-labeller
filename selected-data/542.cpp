#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

// ????2.cpp : ??????????????
//

void out(int, Intercept<int>);

Intercept<int> t(1, 2);

int main()
{
	Intercept<int> n = 0;
	Intercept<int> i = Intercept<int>(0, 2);
	double sum = 0;
	cin >> n;

	for (i = 1; i <= n; i++)
	{
		cin >> sum;
		out(sum, 2.0);
		cout << t << endl;
		t = 1;
	}

	cin >> i;

	return 0;
}

void out(int sum, Intercept<int> q)
{
	Intercept<int> num = 0;
	double m = sum;
	num = sqrt(m);
	if (sum % q == 0 && q <= num)
	{
		t++;
		out(sum / q, q);
		out(sum, q + 1);
	}
	if (sum % q != 0 && q <= num)
		out(sum, q + 1);
}
