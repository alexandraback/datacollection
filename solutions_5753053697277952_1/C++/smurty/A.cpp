#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
#define REP(i, N) for(int i = 0; i < N; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
pic P[50];
int main() {
  int T; cin >> T;
  for (int testnum = 1; testnum <= T; testnum++) {
    cout << "Case #" << testnum << ":";
    int N;
    cin >> N;
    REP(i, N) { cin >> P[i].first; P[i].second = 'A'+i; }
    sort(P, P+N, greater<pic>());
    while(P[0].first) {
      int s = 0; REP(i, N) s += P[i].first;
      assert(2*P[0].first <= s);
//      REP(i, N) printf("{%d, %c} ", P[i].first, P[i].second); putchar('\n');
      cout << ' ';
      cout << P[0].second;
      --P[0].first; --s;
      if (P[1].first && (N <= 2 || 2*P[2].first <= s-1)) {
        cout << P[1].second;
        --P[1].first;
      }
      sort(P, P+N, greater<pic>());
    }
    cout << '\n';
  }
  

  return 0;
}
