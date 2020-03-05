#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> divide(Intercept<int> n,Intercept<int> j)
{
	Intercept<int> sum=1,i,s,p,k;
	s=sqrt(n);
	for(i=j;i<=s;i++)
	{
		if (n%i==0)
		{
			p=n/i;
            k=i;
			sum=sum+divide(p,i);
		}
	}
	return sum;
}
int main()
{
	Intercept<int> n;
	cin>>n;
	Intercept<int> k,m,p;
	for(k=0;k<n;k++)
	{
		cin>>m;
		p=divide(m,2);
		cout<<p<<endl;
	}
	return 0;
}




		
