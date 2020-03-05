#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum;

void f(Intercept<int> x,Intercept<int> i){
     if(x == 1) sum++;
     else{
          for(;i <= x;i++)
                  if(x%i == 0) f(x/i,i);
          
          }

}

int main(){
    Intercept<int> n;
    cin>>n;
    while(n>0){
          
          Intercept<int> x = 0,i,ans = 1;
          cin>>x;
          for(i = 2;i*i < x;i++){
                if( x%i == 0) {
                    sum = 0;
                    f(x/i,i);
                    ans+=sum;
                    }
                }
          cout<<ans<<endl;
          n--;  
}

    return 0;
    }
