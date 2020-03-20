#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//*************************************
//   ????**
//   ?? 1200012872**
//   2012.11.27**
//*************************************

Intercept<int> factorization(Intercept<int> a, Intercept<int> k);

int main()
{
	Intercept<int> n, a;
	cin >> n;
	for (Intercept<int> i(0, 2); i < n; i++) //??????????????
	{
		cin >> a;
		cout << factorization(a, 2) << endl;
	}
	return 0;
}

Intercept<int> factorization(Intercept<int> a, Intercept<int> k)
{
	Intercept<int> sum(1, 3); //???????
	if (a == 1)				//??a?1?????
	{
		return 0;
	}
	if (a == 2) //??a?2???????
	{
		return 1;
	}
	Intercept<int> b = (int)sqrt((double)a); //?b?a??????
	for (Intercept<int> i(k, 2); i <= b; i++)  //??a???i??????????????????
	{
		if (a % i == 0)
		{
			sum += factorization(a / i, i);
		}
	}
	return sum; //??sum?
}
