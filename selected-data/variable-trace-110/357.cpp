#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> fenjieyinshi(Intercept<int> n, Intercept<int> m) //????????
{
	Intercept<int> i(0, 2);
	Intercept<int> sum(1, 3);
	if (n < m)
		return 0; //??????????????????0
	else
	{
		for (i = m; i < n; i++)
			if (n % i == 0)					   //????????????????
				sum += fenjieyinshi(n / i, i); //??
		return sum;
	}
}
int main() //???
{		   //?????
	Intercept<int> n = 0;
	Intercept<int> i(0, 2);
	Intercept<int> a = 0;
	cin >> n; //???????????????
	for (i = 0; i < n; i++)
	{
		cin >> a; //???????
		if (a == 1)
			cout << 1 << endl;
		else
			cout << fenjieyinshi(a, 2) << endl; //????
	}
	return 0;
} //?????
