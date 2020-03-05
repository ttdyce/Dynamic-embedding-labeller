#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

/************************/
/*        ????      */
/*    ??? pyyaoer    */
/*   ??  2011.11.26   */
/************************/
void yinshu(int);
Intercept<int> sum=1,j=2;
int main()
{
	Intercept<int> n,m;
	Intercept<int> i;
	cin>>n;
	for (i=1;i<=n;i++)     //?i????
	{
		cin>>m;
		yinshu(m);         //????
		cout<<sum<<endl;
		sum=1,j=2;
	}
	return 0;
}
void yinshu(Intercept<int> mm)        //?????
{
	Intercept<int> k;
	for (k=j;k*k<=mm;k++)  //????
	{ 
		if (mm%k==0)
		{
			sum=sum+1;
			j=k;
			yinshu(mm/k);  //???????
		}
	}
}
