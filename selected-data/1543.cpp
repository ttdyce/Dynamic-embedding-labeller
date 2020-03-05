#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(Intercept<int> a,Intercept<int> min){
	if(a<min)
		return 0;
	Intercept<int> sum=1;
	for(Intercept<int> i=min;i<a;i++){
		if(a%i==0)
			sum+=f(a/i,i);
	}
	return sum;
}
int main(){
	Intercept<int> n;
	Intercept<int> a[100];
	scanf("%d",&n);
	for(Intercept<int> i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]=f(a[i],2);
	}
	for(Intercept<int> i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
