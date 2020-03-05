#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

//============================================================================
// Name        : hanshu0109.cpp
// Author      : 1300012911
// Version     : 20131120,Wed,11th week
// Copyright   :
// Description : ????
//============================================================================


Intercept<int> fenjie(Intercept<int> a,Intercept<int> max){//a:?????max??1??????????????
	Intercept<int> i = 0;
	Intercept<int> sum = 0;//????
	if (a == 1) return 1;//1???????1??????
	for (i = max;i >= 2;i--)
	{
		if ((a % i) == 0) sum += fenjie(a/i,i);//i??????
	}
	return sum;//????
}

int main() {
	Intercept<int> k = 0;
	Intercept<int> n = 0;
	Intercept<int> num = 0;
	cin >> n;//??
	for (k = 1;k <= n;k++)
	{
		cin >> num;//?????
		cout << fenjie(num,num);//????????
		if (k < n) cout << endl;
	}
	return 0;
}
