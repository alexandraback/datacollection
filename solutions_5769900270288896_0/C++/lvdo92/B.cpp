/***********************************************
* Author - LUONG VAN DO                        *
* Problem
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100111

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int r, c, n, ans;
int x[20], a[20][20];
bool isInside(int xx, int yy) {
      return (xx >= 1 && xx <= r && yy >= 1 && yy <= c);
}
int sumRound(int xx, int yy) {
      int cnt = 0;
      if ( isInside(xx - 1, yy) && a[xx - 1][yy] == 1) cnt++;
      if ( isInside(xx + 1, yy) && a[xx + 1][yy] == 1) cnt++;
      if ( isInside(xx, yy - 1) && a[xx][yy - 1] == 1) cnt++;
      if ( isInside(xx, yy + 1) && a[xx][yy + 1] == 1) cnt++;
      return cnt;
}
int findBest(int k) {
      int row, col, cnt = 0;
      for (int i = 1;i <= k;i++) {
            if (x[i] % c == 0) row = x[i] / c;
            else row = (x[i] / c) + 1;
            if (x[i] % c == 0) col = c;
            else col = (x[i] % c);
            a[row][col] = 1;
      }
      for (int i = 1;i <= r;i++) for (int j = 1;j <= c;j++) {
            if (a[i][j] == 0) continue;
            cnt += sumRound(i,j);
            a[i][j] = 0;
      }
      return cnt;
}
void attemp(int pos, int m, int k) {
      for (int j = x[pos - 1] + 1;j <= m - k + pos;j++) {
            x[pos] = j;
            if (pos == k) ans = min(ans,findBest(k));
            else attemp(pos + 1, m, k);
      }
}
int solve(int m, int k) {
      x[0] = 0; ans = INF;
      attemp(1, m, k);
      return ans;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
      scanf("%d", &cases);
      while (cases--) {
            scanf("%d %d %d", &r,&c,&n);
            for (int i = 1;i <= r;i++) for (int j = 1;j <= c;j++) a[i][j] = 0;
            if (n == 0 || n == 1) printf("Case #%d: 0\n", ++caseno);
            else printf("Case #%d: %d\n", ++caseno, solve(r * c, n));
      }
	return 0;
}
