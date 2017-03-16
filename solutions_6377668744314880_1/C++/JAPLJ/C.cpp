#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

int X[3333], Y[3333], I[6666], G[6666];

Int det(Int x1, Int y1, Int x2, Int y2) {
  return x1 * y2 - y1 * x2;
}

Int dot(Int x1, Int y1, Int x2, Int y2) {
  return x1 * x2 + y1 * y2;
}

Int len(Int x, Int y) {
  return x * x + y * y;
}

void solve() {
  int N = in();
  for (int i = 0; i < N; ++i) {
    X[i] = in();
    Y[i] = in();
  }

  for (int i = 0; i < N; ++i) {
    int K = 0;
    for (int j = 0; j < N; ++j) {
      if (j != i) {
        I[K++] = j;
        X[j] -= X[i];
        Y[j] -= Y[i];
      }
    }
    sort(I, I + K, [=] (const int a, const int b) -> bool {
      if (det(X[a], Y[a], X[b], Y[b]) == 0 &&
          dot(X[a], Y[a], X[b], Y[b]) > 0) {
        return len(X[a], Y[a]) < len(X[b], Y[b]);
      }
      if ((Int)Y[a] * Y[b] < 0) {
        return Y[a] > Y[b];
      } if (Y[a] == 0 && Y[b] == 0) {
        return X[a] > X[b];
      } else {
        return det(X[a], Y[a], X[b], Y[b]) > 0;
      }
    });

    for (int j = 0; j < K; ++j) {
      I[K + j] = I[j];
    }
    for (int j = 0; j < 2 * K; ++j) {
      G[j] = j;
    }
    for (int j = 1; j < 2 * K; ++j) {
      if (det(X[I[j - 1]], Y[I[j - 1]], X[I[j]], Y[I[j]]) == 0 &&
          dot(X[I[j - 1]], Y[I[j - 1]], X[I[j]], Y[I[j]]) > 0 &&
          len(X[I[j - 1]], Y[I[j - 1]]) < len(X[I[j]], Y[I[j]])) {
        G[j] = G[j - 1];
      }
    }
    int res = N - 1;
    // if(i==4){pv(X,X+N);pv(Y,Y+N);pv(I,I+K);}
    for (int j = 0, to = 0; j < K; ++j) {
      chmax(to, j + 1);
      while (true) {
        Int d = det(X[I[j]], Y[I[j]], X[I[to]], Y[I[to]]);
        // if(i==0)printf("%d %d %lld\n",I[j],I[to],d);
        if (d < 0) {
          break;
        } else if (d == 0) {
          if (G[j] != G[to]) {
            break;
          }
        }
        ++to;
      }
      // if(i==4)printf("%d %d\n", j, to);
      chmin(res, to - j - 1);
    }
    printf("%d\n", res);
    for (int j = 0; j < N; ++j) {
      if (j != i) {
        X[j] += X[i];
        Y[j] += Y[i];
      }
    }
  }
}

int main() {
  int TC = in();

  for (int CN = 1; CN <= TC; ++CN) {
    printf("Case #%d:\n", CN);
    solve();
  }

  return 0;
}
