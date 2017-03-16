#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <tuple>
#include <numeric>
#include <cstring>

using namespace std;

int main() {

  freopen("in", "r", stdin);
  freopen("out", "w", stdout);

  int T;
  scanf("%d", &T);

  for (int t=1; t<=T; ++t) {
    printf("Case #%d: ", t);
    int N;
    cin >> N;
    int M[N];
    for (int i=0; i<N; ++i) cin >> M[i];
    int result1=0;
    for (int i=1; i<N; ++i) result1 += max(0, M[i-1]-M[i]);
    int result2=0;
    int maxdiff=0;
    for(int i=1; i<N; ++i) maxdiff = max(maxdiff, max(0, M[i-1]-M[i]));
    for(int i=1; i<N; ++i) result2 += min(M[i-1], maxdiff);
    cout << result1 << ' ' << result2 << endl;
  }
}
