#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>

using namespace std;

struct swing{
    long long p,x;
    bool operator<(const swing ext) const{
      return (p<ext.p) || (p==ext.p && x<ext.x);
    }
};

int main(){
    long long b,n,t,z,i,j,k,x,y,tt;
    long long now,cust,temp,prevcu;
    swing bar[1000];
    swing bar2[1000];
    bool ok;
    cin>>tt;
    for (z=1; z<=tt; ++z){
        ok=false;
        cin>>b>>n;
        for (i=0; i<b; ++i){
            cin>>bar[i].p;
            bar[i].x=i+1;
        }
        sort(bar,bar+b);
 
        if (n<=b){
          ok=true;
          bar[0].x=n;
        }
        else{
          n-=b;
          x=1;
          y=n+1;
        }

        if (!ok){
        while (x+1<y){
          t=(x+y) /2;
          cust=t;
          now=t*bar[0].p;
          for (i=1; i<b; ++i){
            temp = now / bar[i].p;
            if ((temp * bar[i].p == now) && (bar[i].x > bar[0].x))
              temp--;
            cust+=temp;
          }

          if (cust==n){
            ok=true;
            break;
          }
          else if (cust<n){
            x = t;
          }
          else{
            y = t;
          }
        }
        cust=x;
        now=x*bar[0].p;
        for (i=1; i<b; ++i){
          temp = now / bar[i].p;
          if ((temp * bar[i].p == now) && (bar[i].x > bar[0].x))
            temp--;
          cust+=temp;
        }      
      }
      if (!ok){
        now=x*bar[0].p;
        for (i=0; i<b; ++i){
          temp = now / bar[i].p;
          if ((temp * bar[i].p == now) && (bar[i].x > bar[0].x))
            temp--;
          bar2[i].p=(temp+1)*bar[i].p;
          bar2[i].x=bar[i].x;
        }
        sort(bar2,bar2+b);

        cout<<"Case #"<<z<<": "<<bar2[n-cust-1].x<<endl;
      }
      else
        cout<<"Case #"<<z<<": "<<bar[0].x<<endl;
    }
    return 0;
}
