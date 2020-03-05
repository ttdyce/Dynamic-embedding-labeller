#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

void f(int,int);
Intercept<int> sum=0,res=1;
int main()
{
	Intercept<int> n,a,i,j;
	cin>>n;
	for(i=0;i<n;i++)		//n???
	{
		res=1;				//??????a=a
		cin>>a;
		for(j=2;j<=(int)sqrt((float)a);j++)			//??????
		{
			if(a%j==0)
			{
				sum=0;
				f(a/j,j);			//????????
				res+=sum;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
void f(Intercept<int> x,Intercept<int> y)
{
	if(x==1)
		sum++;
	while(y<=x)			//?????????????
	{
		if(x%y==0)
			f(x/y,y);
		y++;
	}
	return;
}
