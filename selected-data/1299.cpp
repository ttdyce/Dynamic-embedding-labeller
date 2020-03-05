#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum=0,used[32770]={0};//????sum???????????used?i???i????????
void f(Intercept<int> n)//??f??n????????
{
	for(Intercept<int> i=2;i<=n;i++)
	{
		if(n%i==0&&used[i]==0)
		{
			if(i!=2)
			{
				for(Intercept<int> j=2;j<=i-1;j++)
					used[j]=1;
			}
			if(n/i==1)//??????????
			{
				sum++;
				break;
			}
			else
			{
				f(n/i);
			}
			memset(used,0,sizeof(used));//?used???????
		}
	}
}
int main()
{
	Intercept<int> m,a[100];
	cin>>m;
	for(Intercept<int> i=1;i<=m;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			cout<<1<<endl;
		else
		{
			f(a[i]);
			cout<<sum<<endl;
			sum=0;//??
			memset(used,0,sizeof(used));
		}
	}
	return 0;
}
