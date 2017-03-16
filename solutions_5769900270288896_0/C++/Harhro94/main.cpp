//Author: Harhro94 [Harutyunyan Hrayr]
//#pragma comment(linker, "/STACK:667777216")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); ++i)
typedef long long LL;
typedef long double LD;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
int rd();

const int K = 10007;

int brute(int n, int m, int k) {
   int ans = 4 * n * m;
   FOR(mask, (1 << (n * m))) {
      int cnt = 0;
      FOR(b, n * m)
         if ((mask >> b) & 1) ++cnt;
      if (cnt != k) continue;
      int cur = 0;
      FOR(i, n) FOR(j, m - 1) {
         int id1 = i * m + j;
         int id2 = i * m + j + 1;
         if (((mask >> id1) & 1) && ((mask >> id2) & 1)) ++cur;
      }
      FOR(i, n - 1) FOR(j, m) {
         int id1 = i * m + j;
         int id2 = i * m + j + m;
         if (((mask >> id1) & 1) && ((mask >> id2) & 1)) ++cur;
      }
      ans = min(ans, cur);
   }
   return ans;
}

void solve() {
   int T;
   scanf("%d", &T);
   for (int test = 1; test <= T; ++test) {
      int n, m, k;
      scanf("%d%d%d", &n, &m, &k);
      printf("Case #%d: %d\n", test, brute(n, m, k));
   }
}

int rd() {
   return (((LL)rand() << 16) ^ rand()) % 1000000000;
}

void testGen() {
   FILE *f = fopen("input.txt", "w");
   fclose(f);
}

int main() {
#ifdef harhro94
   //testGen();
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#else
#define task "ghosts"
   //freopen(task".in", "r", stdin);
   //freopen(task".out", "w", stdout);
#endif

   cerr << fixed;
   cerr.precision(9);

   solve();

#ifdef harhro94
   cerr << fixed << setprecision(3) << "\nExecution time = " << clock() / 1000.0 << "s\n";
#endif
   return 0;
}