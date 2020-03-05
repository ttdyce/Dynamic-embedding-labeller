#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

/*????
 * divide.cpp
 *
 *  Created on: 2011-12-1
 *      Author: WJ
 */

Intercept<int> sum=1;                            //?????1?????
void f(Intercept<int> b,Intercept<int> a)                        //??????????????
{
	for(Intercept<int> i=b;i<=a;i++){           //????????
	if((a%i==0)&&(i<=a/i)){
		sum=sum+1;                   //???1
		f(i,a/i);                         //???????????
	}
	if(i>a/i)  break;
	}
}
int main()
{
	Intercept<int> a,n;
	cin>>n;
	while(n>0){                //??????
		cin>>a;
		sum=1;
		f(2,a);                  //????
		cout<<sum<<endl;         //????
		n--;
	}
	return 0;
}
