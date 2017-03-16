#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init() {
}

// 変数を書く

int N;
int m[10010];

void input() {
  cin >> N;
  for (auto i=0; i<N; i++) {
    cin >> m[i];
  }
}

void output() {
  int ans1 = 0;
  for (auto i=0; i<N-1; i++) {
    ans1 += max(m[i] - m[i+1], 0);
  }
  int ans2 = 0;
  int rate = 0;
  for (auto i=0; i<N-1; i++) {
    rate = max(m[i] - m[i+1], rate);
  }
  for (auto i=0; i<N-1; i++) {
    if (m[i] - rate >= 0) {
      ans2 += rate;
    } else {
      ans2 += m[i];
    }
  }
  cout << ans1 << " " << ans2 << endl;
}

int main() {
  init();
  int T;
  cin >> T;
  for (auto t=1; t<=T; t++) {
    cout << "Case #" << t << ": "; 
    input();
    output();
  }
}
