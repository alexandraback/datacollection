#include<bits/stdc++.h>
using namespace std;
map<int,int> H;
#define ll long long
ll a[10000];


int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int b,n; scanf("%d%d",&b,&n);
      H.clear();
      for(int i=0; i<b; i++){
         scanf("%lld",&a[i]);
      }
      ll lo = -1, hi = LONG_LONG_MAX-1;
      ll diff; ll cov;
      while(hi - lo > 1){
         //cout<<hi<<" "<<lo<<endl;
         ll mid = (lo+hi)/2;
         ll covered = 0;
         cov = 0;
         bool ok = true;
         for(int i=0; i<b; i++){
            if (covered >= LONG_LONG_MAX - mid/a[i]){ covered = -1; ok = false; break;}
            covered += mid/a[i];
            covered += (mid%a[i]==0);
            cov += mid/a[i];
         }
         if (!ok || covered >= n-1){ cov = covered; hi = mid; diff = covered-n+1;}
         else lo = mid;
      }
      
      vector<int> v;
      ll handled;
      
      handled = 0;
      for(int i=0; i<b; i++){
         if (hi%a[i] == 0) v.push_back(i+1);
         handled += max(hi,0LL)/a[i];
      }
      printf("Case #%d: %d\n",cs+1,v[(n-cov+v.size()-1)%v.size()]);
   }
}