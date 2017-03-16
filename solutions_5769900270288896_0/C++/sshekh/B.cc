#include <bits/stdc++.h>
using namespace std;

#define INF 2000000000
#define MOD 1000000007

typedef long long LL;
typedef pair<int, int> ii;

const int N = 16; 
int mat[N][N], n, r, c;
int ans;

void test() {
  int unhappy = 0;
  /*for(int i = 0; i < r; ++i) {
    for(int j = 0; j < c; ++j) {
      cerr << mat[i][j] << " ";
    }
    cerr << "\n";
  }*/
  for(int i = 0; i < r; ++i) {
    for(int j = 0; j < c; ++j) if(mat[i][j]) {
      if(j + 1 < c && mat[i][j + 1]) ++unhappy;
      if(i + 1 < r && mat[i + 1][j]) ++unhappy; 
    }
  }
  if(ans > unhappy) ans = unhappy;
}

void gen(int idx, int to_fill) {
  if(to_fill == 0) {
    test();
  } else if(r*c - idx == to_fill) {
    for(int i = idx; to_fill; ++i) {
      mat[i / c][i % c] = 1;
      --to_fill;
    }
    test();
  } else {
    mat[idx / c][idx % c] = 1;
    gen(idx + 1, to_fill - 1);
    mat[idx / c][idx % c] = 0;
    gen(idx + 1, to_fill);
  }
}

int main() { 
  
  int T; cin >> T;
  for(int qq = 1; qq <= T; ++qq) {
    printf("Case #%d: ", qq);
    memset(mat, 0, sizeof mat);
    ans = INF;
    cin >> r >> c >> n;
    gen(0, n);
    cout << ans << "\n";
  }
  
  return 0;
}

