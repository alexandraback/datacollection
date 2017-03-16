#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int test_number = 0;
#define SIZE(A) (int((A).size()))
#define pb push_back
#define mp make_pair
#define gout printf("Case #%d: ", ++test_number);cout

const int MAXN = 20000;
const int fx[] = {0, 1, 0, -1}, fy[] = {1, 0, -1, 0};
vector<char> a[MAXN];

void Main() {
  int n, m, N;
  cin >> n >> m >> N;
  for (int i = 0; i < n; ++i) {
    a[i] = vector<char>(m, 0);
  }
  int res = n*m*4;
  for (int msk = 0; msk < (1<<(n*m)); ++msk) {
    if (__builtin_popcount(msk)!=N) {
      continue;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        a[i][j] = (msk>>(i*m+j))&1;
      }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j]) {
          for (int k = 0; k < 4; ++k) {
            int x = i+fx[k], y = j+fy[k];
            if (x>=0 && y>=0 && x<n && y<m && a[x][y]) {
              ++sum;
            }
          }
        }
      }
    }
    assert(sum%2==0);
    res = min(res, sum/2);
  }
  gout << res << endl;
}

int main() {
  int test;
  cin >> test;
  for (; test--;) {
    Main(); 
  }
  return 0;
}
