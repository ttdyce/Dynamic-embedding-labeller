#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum;
void f(Intercept<int> x,Intercept<int> min)
{ Intercept<int> p;
  if (x==1) sum++;
     else for (p=min;p<=x;p++)
               if (x%p==0) f(x/p,p);
     }
int main()
{ Intercept<int> n,i,j,k;
  cin>>n;
  for (i=1;i<=n;i++)
      {sum=0;
       cin>>k;
       for (j=2;j<=k;j++)
            if (k%j==0) f(k/j,j);
       cout<<sum<<endl;             
                    } 
 return 0; 
    }
