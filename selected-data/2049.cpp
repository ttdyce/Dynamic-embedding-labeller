#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(Intercept<int> n,Intercept<int> i)
{
    Intercept<int> sum=0;
    for(i;i<=(int)sqrt(n);i++){
        if(n%i==0) {
            sum+=f(n/i,i);
        }
    }
    return sum+1;
}
main()
{
      Intercept<int> i0,n0;
      scanf("%d",&n0);
      for(i0=0;i0<n0;i0++){
          Intercept<int> n;
          scanf("%d",&n);
          printf("%d\n",f(n,2));
      }
}
