#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 1010;

int a[MAXN];
int n;

int solveY() {
   int ans = 0;
   int curr = a[0];
   for(int i = 1 ; i < n ; i++){
      if(curr > a[i]) {
         ans += curr - a[i];
      }
      curr = a[i];
   }
   return ans;
}

int solveZ() {
   int maxi = 0;
   int curr = a[0];
   for(int i = 1 ; i < n ; i++){
      if(curr > a[i]) {
         maxi = max(maxi, curr - a[i]);
      }
      curr = a[i];
   }
   int eaten = 0;
   curr = a[0];
   for(int i = 1 ; i < n ; i++){
      if(curr > maxi) {
         eaten += maxi;
      } else {
         eaten += curr;
      }
      curr = a[i];
   }
   return eaten;
}

int main(){
#ifndef ONLINE_JUDGE
   // freopen("in","r",stdin);
   freopen("A-large.in","r",stdin);
   freopen("A-large.out","w",stdout);
#endif
   int casos;
   cin >> casos;
   for(int caso = 1 ; caso <= casos ; caso++){
      cin >> n;
      for(int i = 0 ; i < n ; i++ ){
         cin >> a[i];
      }
      cout << "Case #" << caso << ": " << solveY() << " " << solveZ() << endl;
   }
   return 0;
}