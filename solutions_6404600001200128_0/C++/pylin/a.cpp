#define PRETEST
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <sstream>
using namespace std;

#define INF 0x4f4f4f4f
#define FILL(a,b) memset(a,b,sizeof(a))
#define SQR(a) ((a) * (a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef map<int, int> mii;

int main(int argc, char *argv[]) {
#ifdef PRETEST
  freopen("A-small.in", "r", stdin);
  freopen("out.txt", "w+", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int C = 1; C <= T; ++C) {
    int N;
    scanf("%d", &N);
    vector<int> vec;
    for (int i = 0; i < N; ++i) {
      int x;
      scanf("%d", &x);
      vec.push_back(x);
    }
    int ans1 = 0;
    for (int i = 1; i < N; ++i) {
      if (vec[i] < vec[i - 1]) {
        ans1 += vec[i - 1] - vec[i];
      }
    }
    int rate = 0;
    ll ans2 = 0;
    for (int i = 1; i < N; ++i) {
      if (vec[i] < vec[i - 1]) {
        rate = max(rate, vec[i - 1] - vec[i]);
      }
    }
    for (int i = 1; i < N; ++i) {
      ans2 += min(vec[i - 1], rate);
    }
    printf("Case #%d: %d %lld\n", C, ans1, ans2);
  }
  
  return 0;
}
