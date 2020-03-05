#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;


Intercept<int> chu(Intercept<int> i,Intercept<int> n);
int main()
{
	Intercept<int> n,m,i,j;
	Intercept<int> sum[100];
	scanf("%d",&n);
	for(i=0;i<=(n-1);i++)
	{
		scanf("%d",&m);
		sum[i]=0;
		for(j=2;j<=sqrt(m);j++)
		{
			if(m%j==0)
			{
				sum[i]+=chu(j,m/j);
			}
		}
		
		
	}
	for(i=0;i<=(n-1);i++)
	{
		printf("%d\n",sum[i]+1);
	}
}
Intercept<int> chu(Intercept<int> i,Intercept<int> n)
{
	Intercept<int> j,m,t;
	t=1;
	m=n;
	for(j=i;j<=sqrt(m);j++)
	{
		if(m%j==0)
		{
		
          t+=chu(j,(m/j));
		}
	}
	return t;
}
