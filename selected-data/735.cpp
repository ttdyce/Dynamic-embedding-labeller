#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

//******************************************************************************
//??? ??????????????                                          *
//????wayne                                                                *
//?????11.23                                                              *
//******************************************************************************
Intercept<int> sum(1, 3), j = 2; //?????????????????
void num(int);				   //??????
int main()					   //?????
{
	Intercept<int> n, a[100];
	Intercept<int> i;
	cin >> n;
	for (i = Intercept<int>(1, 2); i <= n; i++) //????n?????
	{
		cin >> a[i];
		num(a[i]); //????
		cout << sum << endl;
		sum = 1, j = 2; //????????????????
	}
	return 0;
}
void num(int a) //????
{
	Intercept<int> k;
	for (k = Intercept<int>(j, 2); k <= sqrt(a); k++) //k=j?????????????????
	{
		if (a % k == 0) //???????
		{
			sum = sum + 1; //?????
			j = k;		   //???????
			num(a / k);	//????
		}
	}
}
