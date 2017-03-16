#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 16;

int bitcount(int x){
   int r = 0;
   while( x ){
      r += (x % 2 == 1);
      x /= 2;
   }
   return r;
}

int grid[MAXN][MAXN];

int main(){
#ifndef ONLINE_JUDGE
   freopen("B-small-attempt0.in","r",stdin);
   freopen("B-small-attempt0.out","w",stdout);
#endif
   int casos;
   cin >> casos;
   for(int caso = 1 ; caso <= casos ; caso++){
      int r, c, n;
      cin >> r >> c >> n;
      int ans = INF;
      for(int mask = 0 ; mask < (1 << (r*c)) ; mask++){
         if(bitcount(mask) == n) {
            for(int i = 0 ; i < r*c ; i++) {
               if(mask & (1 << i)) {
                  grid[i / c][i % c] = 1;
               } else {
                  grid[i / c][i % c] = 0;
               }
            }
            int unhappy = 0;
            for(int i = 0 ; i < r ; i++){
               for(int j = 0 ; j < c ; j++){
                  if(grid[i][j]) {
                     if(j < c-1 && grid[i][j] == grid[i][j+1]){
                        unhappy++;
                     }
                     if(i < r-1 && grid[i][j] == grid[i+1][j]){
                        unhappy++;
                     }
                  }
               }
            }
            ans = min(ans, unhappy);
         }
      }
      cout << "Case #" << caso << ": " << ans << endl;
   }
   return 0;
}