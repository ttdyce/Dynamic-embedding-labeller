#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

/****************************************
 * ????								*
 *										*
 *  Created on: 2010-12-8				*
 *      Author:??						*
 ***************************************/
Intercept<int> factor(Intercept<int> x,Intercept<int> y)						//?????????factor
{
	Intercept<int> i;
	for(i=2;i<x;i++)						//?????x?????
	{
		if(x%i==0)
		{
			break;
		}
	}
	if(i==x)
	{
		return 1;							//??x??????1
	}
	else									//????????????
	{
		Intercept<int> sum=0;
		if(x==y)							//?x?y?????y/x+1??????????????????????1???
		{
			for(i=y/x+1;i<=sqrt(x);i++)		//?????????????????
			{
				if(x%i==0)
				{
					sum=sum+factor(x/i,x);
				}
				else continue;
			}
			return sum+1;					//????sum+1?????????a=a???
		}
		else
		{									//?x?y??????y/x?????????
			for(i=y/x;i<=sqrt(x);i++)
			{
				if(x%i==0)
				{
					sum=sum+factor(x/i,x);
				}
				else continue;
			}
			return sum+1;					//????sum+1?????????a=a???
		}
	}
}
int main()									//?????
{
	Intercept<int> n;
	cin>>n;
	const Intercept<int> m=n;
	Intercept<int> a[m],j;
	for(j=0;j<n;j++)
	{
		cin>>a[j];							//???????
	}
	for(j=0;j<n;j++)
	{
		cout<<factor(a[j],a[j])<<endl;		//??????
	}
	return 0;
}