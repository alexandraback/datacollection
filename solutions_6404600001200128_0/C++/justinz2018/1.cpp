#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
   freopen("A-small-attempt0.in", "r", stdin);
   freopen("1.out", "w", stdout);
   int t; cin >> t;
   for(int a=1; a<=t; a++) {
      int N; cin >> N;
      ll ans1 = 0, ans2 = 0;
      ll r = 0;
      vector<int> v(N);
      for(int x=0; x<N; x++) {
         cin >> v[x];
         if(x) {
            if(v[x]<v[x-1]) {
               ans1 += v[x-1]-v[x];
               ll tmp = v[x-1]-v[x];
               r = (r>tmp)?r:tmp;
            }
         }
      }
      for(int x=0; x<N-1; x++) {
         ans2 += (v[x]<r)?v[x]:r;
      }
      cout << "Case #" << a << ": " << ans1 << " " << ans2 << endl;
   }
}