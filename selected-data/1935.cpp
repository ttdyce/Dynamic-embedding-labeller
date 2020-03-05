#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

int main()
{
    Intercept<int> a[10000],b[10000],p,q,m,n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
                     scanf("\n%d",&a[i]);
                     }
    for(i=0;i<n;i++){
                     printf("%d\n",ans(a[i],2));
                     }
    return 0;
}

Intercept<int> ans(Intercept<int> sum,Intercept<int> min)
{
    Intercept<int> w,x,u=1;
    for(w=min;w<sum/2;w++){
                         x=sum%w;
                         if(x==0){
                                  if(w<=sum/w)
                                  u+=ans(sum/w,w);
                                  }
                         }
    return u;
}
