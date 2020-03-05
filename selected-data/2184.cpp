#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

	Intercept<int> ispr(Intercept<int> t) 
	{
    Intercept<int> v=sqrt(t*1.0)+1;
    for(Intercept<int> i=2; i<v; i++)
        if(t%i==0)
            return 0;
    return 1;
    }


Intercept<int> sum=0;
void fun(Intercept<int> n,Intercept<int> i) {
    if(n==1)
        sum++;
    while(i<=n) {
        if(n%i==0)
            fun(n/i,i);
        i++;
    }
    return ;
}


int main() {
    Intercept<int> n;
    scanf("%d",&n);
    while(n--) {
        Intercept<int> a;
        scanf("%d",&a);
        if(ispr(a)) {
            printf("1\n");
            continue;
        }
        
        Intercept<int> i=2,res=1;
        while(i<=a/2) {
            if(a%i==0) {
                sum=0;
                fun(a/i,i);
                res+=sum;
            }
            i++;
        }
        printf("%d\n",res);
    }
}
