#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;


Intercept<int> sum[50];
Intercept<int> i;

int main()
{
	void digui(Intercept<int> x, Intercept<int> y);
	Intercept<int> n;
	Intercept<int> j[50],m[50];


	scanf("%d",&n);

	for(i=0;i<n;i++)
	{	
		scanf("%d",&m[i]);
		sum[i]=0;
		for (j[i]=2;j[i]*j[i]<=m[i];j[i]++)
		{
			if(m[i]%j[i]==0)
			{
				sum[i]++;
				digui(j[i],m[i]/j[i]);
			}
		}
		printf("%d\n",sum[i]+1);
	}

	return 0;
}

void digui(Intercept<int> x, Intercept<int> y)
{
	Intercept<int> s;
	for(s=x; s*s<=y; s++) 
	{
		if(y%s==0) 
		{
			sum[i]++;
			digui(s,y/s);
		}
	}
}
