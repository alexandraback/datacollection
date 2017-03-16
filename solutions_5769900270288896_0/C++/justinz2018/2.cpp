#include <bits/stdc++.h>
#include <unordered_map>
#define pb push_back
using namespace std;

typedef long long ll;


int main() {
   ios_base::sync_with_stdio(0);
  freopen("B-small-attempt2.in", "r", stdin);
   freopen("2.out", "w", stdout);
   
   int t23; cin >> t23;
   for(int a23=1; a23<=t23; a23++) {
      int r,c,n; cin >> r >> c >> n;
      cout << "Case #" << a23 << ": ";
      ll tmp =ceil(r*c/2.0); 
      if(n-tmp<=0) {
         cout << 0 << endl;
         continue;
      }
      if(n<=0) {
         cout << 0 << endl;
         continue;
      }
      if(r>c) swap(r,c);
      if(r==1) {
         if(c%2) {
            cout << 2*(n-tmp) << endl;
         } 
         else {
            cout << 2*(n-tmp-1)+1 << endl;
         }
      } 
      else if(r==2) {
         n-=tmp;
         if(n==1) {
            cout << 2 << endl;
         } 
         else {
            cout << 3*(n-2)+4 << endl;
         }
      } 
      else {
         if((r%2) && (c%2)) {
            ll n1 = n-tmp;
            ll n2 = n-r*c/2;
            ll num3_1 = (r/2)*2+(c/2)*2, num3_2 = ceil(r/2.0)*2+ceil(c/2.0)*2-8;
            ll num4_1 = ((r-2)*(c-2))/2, num4_2 = ceil((r-2)*(c-2)/2.0);
            ll r1 = 3*(min(num3_1,n1));
            r1 += 4*max(n1-num3_1,0*1LL);
            ll r2 = 2*min(4LL,n2);
            n2-=4;
            r2 += 3*max(min(num3_2,n2), 0*1LL);
            r2 += 4*max(n2-num3_2, 0*1LL);
            cout << min(r1,r2) << endl;
         } 
         else {
            n-=tmp;
            if(n==1) {
               cout << 2 << endl;
               continue;
            } 
            else {
               if((r%2) || (c%2)) {
                  ll num3 = 2*(r/2)+2*(c/2)-3;
                  ll num4 = (r-2)*(c-2)/2;
                  n-=2;
                  if(n<=0) {
                     cout << 4 << endl; 
                     continue;
                  }
                  ll r1 = 4+3*(min(num3,n*1LL));
                  r1 += 4*max(n-num3,0*1LL);
              //    cout << num4 << " " << " " << num3 << endl;
                  cout << r1 << endl;
               }
               else { 
                  ll num3 = 2*(r/2)+2*(c/2)-4;
                  ll num4 = (r-2)*(c-2)/2;
                  n-=2;
                  if(n<=0) {
                     cout << 4 << endl; 
                     continue;
                  }
                  ll r1 = 4+3*(min(num3,n*1LL));
                  r1 += 4*max(n-num3,0*1LL);
               //   cout << num4 << " " << " " << num3 << endl;
                  cout << r1 << endl;
               }
            }
         }
      }
   }
}
