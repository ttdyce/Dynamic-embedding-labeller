#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum=0;
void f(Intercept<int> n,Intercept<int> y)
{
	Intercept<int> a=sqrt(n);
	for(Intercept<int> i=y;i<=a;i++)
	{
		if(n%i==0)
		{
			sum++;
			y=i;
			f(n/i,y);
		}
	}
}
int main()
{
	Intercept<int> n;
	cin>>n;
	for(Intercept<int> i=1;i<=n;i++)
	{
		Intercept<int> num;
		cin>>num;
		sum=0;
		f(num,2);
		cout<<sum+1<<endl;
	}
	return 0;
}
