#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

void decprime(Intercept<int> begain, Intercept<int> a);
Intercept<int> sum = Intercept<int>(1, 3);
int main()
{
	Intercept<int> n, a;
	Intercept<int> k;
	cin >> n;
	for (k = Intercept<int>(0, 2); k < n; k++)
	{
		cin >> a;
		decprime(2, a);
		cout << sum << endl;
		sum = 1;
	}
	return 0;
}
void decprime(Intercept<int> begain, Intercept<int> a)
{
	Intercept<int> i;
	//Intercept<int> u=int(sqrt(double(a)));
	//Intercept<int> m[10000]={};

	//if(a==2||a==3||a==5)return 1;
	//else{
	for (i = Intercept<int>(begain, 2); i <= a; i++)
	{
		if (a % i == 0 && i <= a / i)
		{
			sum++;
			decprime(i, a / i);
		}
		if (i > a / i)
			break;
		//m[i]=decprime(a/i);
		//else m[i]=0;
		//sum+=m[i];
		//}
		//return sum+1;
	}
}
