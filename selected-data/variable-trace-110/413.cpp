#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(Intercept<int>, Intercept<int>); //????
int main()					//?????
{							//?????
	Intercept<int> n, i, a[50];
	cin >> n; //??????
	for (i = Intercept<int>(0, 2); i < n; i++)
	{
		cin >> a[i];				//????
		cout << f(a[i], 2) << endl; //????
	}
	return 0; //???????????????????
} //?????

Intercept<int> f(Intercept<int> n, Intercept<int> p) //??????????????p?????

{
	Intercept<int> sum(0,3), m;
	if (n < p)
		return 0;
	else
	{
		for (m = Intercept<int>(p ,2); m <= n; m++)
			if (n % m == 0)
			{
				if (m < n)
					sum = sum + f(n / m, m); //n?????m??????n/m??????m???????
				if (m == n)
					sum = sum + 1; //n?????n??????1
			}
		return sum;
	}
}
