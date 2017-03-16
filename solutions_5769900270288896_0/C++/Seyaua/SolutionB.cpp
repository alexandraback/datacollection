#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

int lensmall(int r) {
  if (r <= 3) {
    return 0;
  }
  return r / 2 - 1;
}

int lenbig(int r) {
  return r / 2;
}

int tryeven(int l, int r, int n) {
  int totalzero = (l * r) / 2;
  int totaltwo = 4;
  int totalthree = 2 * (lensmall(r) + lensmall(l));

  n -= totalzero;
  int ans = 0;
  if (n > 0) {
    ans += min(n, totaltwo) * 2;
    n -= totaltwo;
  }
  if (n > 0) {
    ans += min(n, totalthree) * 3;
    n -= totalthree;
  }
  if (n > 0) {
    ans += n * 4;
  }
  return ans;
}

int tryodd(int l, int r, int n) {
  int totalzero = (l * r + 1) / 2;
  int totaltwo = 0;
  int totalthree = 2 * (lenbig(r) + lenbig(l));

  n -= totalzero;
  int ans = 0;
  if (n > 0) {
    ans += min(n, totaltwo) * 2;
    n -= totaltwo;
  }
  if (n > 0) {
    ans += min(n, totalthree) * 3;
    n -= totalthree;
  }
  if (n > 0) {
    ans += n * 4;
  }
  return ans;
}

int oneodd(int len, int n) {
  if (len == 1) return 0;
  int totalzero = (len + 1) / 2;
  n -= totalzero;
  int ans = 0;
  if (n > 0) {
    ans += n * 2;
  }
  return ans;
}

int oneeven(int len, int n) {
  if (len == 1) return 0;
  int totalzero = len / 2;
  int totalone = 2;
  n -= totalzero;
  int ans = 0;
  if (n > 0) {
    ans += min(totalone, n);
    n -= totalone;
  }
  if (n > 0) {
    ans += n * 2;
  }
  return ans;
}

int solveone(int len, int n) {
  if (len % 2 == 1) {
    return min(oneodd(len, n), oneeven(len, n));
  }
  int totalzero = len / 2;
  int totalone = 1;
  n -= totalzero;
  int ans = 0;
  if (n > 0) {
    ans += min(n, totalone);
    n -= totalone;
  }
  if (n > 0) {
    ans += n * 2;
  }
  return ans;
}

int get_res(int l, int r, int n) {
  
  if (l >= r) {
    swap(l, r);
  }

  if (l == 1) {
    return solveone(r, n);
  }

  if (l % 2 == 1 && r % 2 == 1) {
    return min(tryeven(l, r, n), tryodd(l, r, n));
  }

  int totalzero = (l * r) / 2;
  int totaltwo = 2;
  int totalthree = l + r - 4;

  int ans = 0;
  n -= totalzero;
  if (n > 0) {
    ans += min(n, totaltwo) * 2;
    n -= totaltwo;
  }
  if (n > 0) {
    ans += min(totalthree, n) * 3;
    n -= totalthree;
  }
  if (n > 0) {
    ans += n * 4;
  }
  return ans;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int a[25][25];

bool is_in(int x, int y, int l, int r) {
  return x >= 0 && x < l && y >= 0 && y < r;
}

int check_board(int l, int r) {
  int res = 0;
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < r; ++j) {
      for (int k = 0; k < 4; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (is_in(nx, ny, l, r)) {
          if (a[i][j] && a[nx][ny]) {
            ++res;
          }
        }
      }
    }
  }
  return res / 2;
}

int get_res2(int l, int r, int n) {
  int len = l * r;

  int ans = 1000000;
  for (int i = 0; i < (1 << len); ++i) {
    for (int x = 0; x < l; ++x) for (int y = 0; y < r; ++y) a[x][y] = 0;
    int ct = 0;
    for (int j = 0; j < len; ++j) {
      if (i & (1 << j)) {
        a[j / r][j % r] = 1;
        ++ct;
      }
    }
    if (ct == n) {
      ans = min(ans, check_board(l, r));
    }
  }
  return ans;
}

void solve(int tcase) {
  printf("Case #%d: ", tcase);
  int l, r, n;
  cin >> l >> r >> n;
  cout << get_res(l, r, n) << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  /*for (int l = 1; l <= 16; ++l) {
    for (int r = 1; r * l <= 16; ++r) {
      cerr << l << " " << r << endl;
      for (int n = 0; n <= l * r; ++n) {
        int val1 = get_res(l, r, n);
        int val2 = get_res2(l, r, n);
        if (val1 != val2) {
          cerr << l << " " << r << " " << n << endl;
          cerr << val1 << endl;
          cerr << val2 << endl;
          return 0;
        }
      }
    }
  }*/

  //cout << get_res(4, 4, 16) << endl;
  
  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; ++i) {
    solve(i + 1);
  }
  return 0;
}
