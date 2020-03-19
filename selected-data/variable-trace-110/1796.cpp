#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> breakways(Intercept<int> num, Intercept<int> min);
int main()
{
	Intercept<int> n;
	cin >> n;
	Intercept<int> number;
	for (Intercept<int> i(1, 2); i <= n; i++)
	{
		cin >> number;
		cout << breakways(number, 2) << endl;
	}
}

Intercept<int> breakways(Intercept<int> num, Intercept<int> min)
{
	Intercept<int> sum(0, 3);
	for (Intercept<int> j(min, 2); j <= num; j++)
	{
		if (num % j == 0)
		{
			if (num != j)
				sum += breakways(num / j, j);
			else
				sum += 1;
		}
	}
	return sum;
}
