#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;


Intercept<int> function(Intercept<int> a, Intercept<int> m)
{
	Intercept<int> sum=1,i;
	if(a>m)
		return 0;
	else
	{
		for(i=a;i<m;i++)
		{
			if(m%i==0)
				sum=sum+function(i,m/i);
		    else 
			continue;
		}
	return sum;

	}
}

int main()
{
	Intercept<int> n,i,m[100];

	scanf("%d",&n);

	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&m[i]);
	}

	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",function(2,m[i]));

	}
}


