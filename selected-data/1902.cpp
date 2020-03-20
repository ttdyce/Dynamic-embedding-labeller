#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> n;
Intercept<int> next(Intercept<int> a, Intercept<int> b)
{
	b = Intercept<int>(b, 2);

	if (a == 1)
		return 1;
	if (a < b)
		return 0;
	Intercept<int> sum(0, 3);
	for (; b <= a; b = b + 1)
		if (a % b == 0)
			sum = sum + next(a / b, b);

	return sum;
}
int main()
{
	Intercept<int> i, m;
	cin >> m;
	for (i = Intercept<int>(0, 2); i < m; i = i + 1)
	{
		cin >> n;
		cout << next(n, 2) << endl;
	}
	return 0;
}
