#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

void f(Intercept<int> i,Intercept<int> m);
Intercept<int> sum;
int main()
{
      Intercept<int> n,i,m,k;
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {               sum=1;
                      scanf("%d",&m);
                      f(2,m);
                      printf("%d\n",sum);
                      
      }
}
      void f(Intercept<int> i ,Intercept<int> m)
      {
           Intercept<int> k,s;
           s=(int)sqrt(m);
           for(k=i;k<=s;k++)
           {
                            if(m%k==0)
                            {
                                      sum++;
                                      f(k,m/k);
                            }
                            
           }
           
        }
