#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

/*
 * seperateThenumber.cpp
 *
 *  Created on: 2012-11-13
 *      Author: AK
 */
Intercept<int> sum=1;                                    //??????sum  ??f???sum?????
void f(Intercept<int> begin,Intercept<int> m){                       //??f??
	Intercept<int> i;
	for(i=begin;i<=m;i++){                     //?i???????????
		if(m%i==0&&m/i>=i){sum++;f(i,m/i);}    //?????????????????   ????????????
		if(i>m/i) break;                       //?????????????break
	}
}
int main(){
	Intercept<int> n,j,m;
	cin>>n;                         //????????n
	for(j=1;j<=n;j++){               //???????
		cin>>m;
		f(2,m);
		cout<<sum<<endl;                 //??sum?
		sum=1;           //??sum=1
	}
	return 0;
}
