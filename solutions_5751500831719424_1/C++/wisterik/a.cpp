#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

template<class T> ostream& operator<<(ostream& os, vector<T> v) {
  for(T x : v) os << x << ", ";
  return os;
}

vector<pair<char, int> > poyo(string s) {
  vector<pair<char, int> > ans;
  int n = s.size();
  rep(i, n) {
    if(ans.empty() || ans.back().first != s[i]) {
      ans.push_back(make_pair(s[i], 1));
    }
    else {
      ans.back().second++;
    }
  }
  return ans;
}

int main() {

  int T;
  cin >> T;

  rep(t, T) {

    cout << "Case #" << (t+1) << ": ";

    int N;
    cin >> N;

    vector<vector<pair<char, int> > > ss(N);
    rep(i, N) {
      string s;
      cin >> s;
      ss[i] = poyo(s);
    }

    bool ok = true;
    int size = ss[0].size();
    for(int i = 1; i < N; i++) {
      if((int)ss[i].size() != size) {
	ok = false;
      }
      rep(j, size) {
	if(ss[i][j].first != ss[0][j].first) {
	  ok = false;
	}
      }
    }
    
    if(!ok) {
      cout << "Fegla Won" << endl;
      continue;
    }

    int ans = 0;

    rep(j, size) {
      int maxV = 0;
      rep(i, N) {
	maxV = max(maxV, ss[i][j].second);
      }

      int bestCost = 1 << 16;

      for(int k = 1; k <= maxV; k++) {
	int cost = 0;
	rep(i, N) {
	  cost += abs(k - ss[i][j].second);
	}
	bestCost = min(bestCost, cost);
      }
      ans += bestCost;
    }

    cout << ans << endl;
  }

  return 0;
}
