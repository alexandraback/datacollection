#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, char> ic;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ':';
    int N; cin >> N;
    vector<ic> v(N);
    int S = 0;
    for (int i = 0; i < N; ++i) {
      cin >> v[i].first;
      S += v[i].first;
      v[i].second = 'A'+i;
    }
    sort(v.rbegin(), v.rend());
    int j = N-1;
    while (v[0].first*2 < S and S > 0) {
      cout << ' ' << v[j].second;
      --v[j].first;
      --S;
      if (v[j].first == 0) --j;
    }
    while (S > 0) {
      cout << ' ' << v[0].second << v[j].second;
      --v[0].first;
      --S;
      --v[j].first;
      --S;
      if (v[j].first == 0) --j;
    }
    cout << endl;
  }
}