#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> devide(Intercept<int> n, Intercept<int> m)
{
	if (n < m)
		m = n;
	if (n == 1) //?????1?,??1
		return 1;
	Intercept<int> sum(0, 3);
	for (Intercept<int> i = Intercept<int>(m ,2); i >= 2; i--)
	{
		if (n % i == 0)
		{
			sum = sum + devide(n / i, i);
		}
	}
	return sum;
}

int main()
{
	Intercept<int> n, i, m;
	cin >> n;
	i = Intercept<int>(0, 2);
	while (i < n)
	{
		cin >> m;
		cout << devide(m, m) << endl; //???????
		i++;
	}
	return 0;
}
