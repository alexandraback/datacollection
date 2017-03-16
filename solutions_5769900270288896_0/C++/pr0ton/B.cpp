#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex> 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb(z)       push_back( z )
#define gcd           __gcd

bool isNum(char c) { return ('0' <= c && c <= '9'); }
template<typename T>
T read(T &res) {
  res = 0; char c, neg = 0;
  do { c=getchar(); } while (!isNum(c) && c != '-');
  if (c == '-') { neg = 1; c = getchar(); }
  while (isNum(c)) { res = res * 10 + c-'0'; c = getchar(); }
  return neg ? -res : res;
}

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define readInt read<int>
#define readLL read<ll>

//37ae83cb1254dc6d8f3f075ebd91cb


int A[20][20];
int main() {
  int T;
  cin>>T;
  for (int cs=1; cs <= T; ++cs) {
    int R, C, N;
    cin>>R>>C>>N;
    int Total = R * C;
    int ans = (int)1e9;
    for (int mask=0; mask < (1<<Total); mask++) {
      int bc = bitcount(mask);
      fill(A, 0);
      if (bc == N) {
        for (int bit=0; bit < Total; bit++) if (mask & 1<<bit) {
          int row = bit / C;
          int col = bit % C;
          A[row][col] = 1;
        }
        int noise = 0;
        for (int x=0; x < R; x++)
        for (int y=0; y < C; y++) if (A[x][y]) {
          for (int dx=-1; dx <= 1; dx++)
          for (int dy=-1; dy <= 1; dy++)
          if (abs(dx) + abs(dy) == 1) {
            int nx = x + dx,
                ny = y + dy;
            
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && A[nx][ny]) {
              noise++;
            }
          }
        }
        ans = min(ans, noise / 2);
      }
    }
    
    cout << "Case #" << cs <<": " << ans << endl;
  }
}
