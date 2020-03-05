#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum=0;
void divide(Intercept<int> n,Intercept<int> a)
{
	for(Intercept<int> i=a;i<=n;i++)
	{
		if((n%i==0))
		{
			if(n/i==1)
				sum++;
			else
				divide(n/i,i);
		}
	}
}
int main()
{
	Intercept<int> N=0,n=0,i=0;
	cin>>N;
	for(i=0;i<N;i++)
	{
		cin>>n;
		divide(n,2);
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
