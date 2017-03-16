#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm(int i, int j) {
   return 1LL*i*j/__gcd(i,j);
}

int main() {
   freopen("B.in", "r", stdin);
   freopen("2.out", "w", stdout);
   int t; cin >> t;
   for(int a=1; a<=t; a++) {
      int b,n; cin >> b >> n;
      vector<int> v(b);
      ll prev=-1;
      for(int x=0; x<b; x++) {
         cin >> v[x];
         if(x) prev = lcm(v[x],prev);
         else prev=v[x];
      }
      ll m = 0;
      for(int x=0; x<b; x++)
         m +=prev/v[x];
      vector<int> v2(b,0);
      n %= m;
      if(!n) n+=m;
      int i, min1=1e9;
      bool b2=0;
      for(int x=1;; x++) {
         for(int y=0; y<v2.size(); y++) {
            if(v2[y]<=0) {
               n--; 
               if(n<=0) {
                  cout << "Case #" << a << ": " << y+1 << endl;
                  b2=1;
                  break;
               }
               v2[y]=v[y];
            }
            v2[y]--;
         }
         if(b2) break;
      }
   }
}