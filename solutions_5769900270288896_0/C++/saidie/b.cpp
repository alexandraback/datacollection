#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

int r, c, n;

int g[16][16];

int nbits(int i)
{
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main(void){
  int t;
  cin >> t;
  for(int k = 0; k < t; ++k){
    cin >> r >> c >> n;

    int ans = INT_MAX;
    for(int m = 0; m < (1<<(r*c)); ++m){
      if(nbits(m) == n){
        // cout << m << " : " << nbits(m) << endl;

        int v = m;
        for(int i = 0; i < r; ++i){
          for(int j = 0; j < c;  ++j){
            g[i][j] = v&1;
            v >>= 1;
          }
        }

        int unhappy = 0;
        for(int i = 0; i < r; ++i){
          for(int j = 0; j < c; ++j){
            unhappy += i+1 < r && g[i][j] && g[i+1][j];
            unhappy += j+1 < c && g[i][j] && g[i][j+1];
          }
        }

        // for(int i = 0; i < r; ++i){
        //   for(int j = 0; j < c; ++j)
        //     cout << g[i][j];
        //   cout << endl;
        // }
        // cout << unhappy << endl;;

        ans = min(ans, unhappy);
      }
    }

    cout << "Case #" << k+1 << ": " << ans << endl;
  }

  return 0;
}
