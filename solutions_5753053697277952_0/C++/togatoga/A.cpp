#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <functional>
#include <limits.h>
#include <bitset>

#include <tuple>
#include <unordered_map>

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1 << 29;
const double EPS = 1e-9;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int T;
bool check_two(const vector<pii> &party, int one, int two, int sum) {
  for (int i = 0; i < party.size(); i++) {
    int val = party[i].first;
    int index = party[i].second;
    if (index == one) {
      val--;
    }
    if (index == two) {
      val--;
    }
    if ((long double)val * 1.0 / sum > 0.5) {
      return false;
    }
  }
  return true;
}
bool check_one(const vector<pii> &party, int one, int sum) {
  for (int i = 0; i < party.size(); i++) {
    int val = party[i].first;
    int index = party[i].second;
    if (index == one) {
      val--;
    }
    if ((long double)val * 1.0 / sum > 0.5) {
      return false;
    }
  }
  return true;
}
void solve(const int case_id) {
  int N;
  cin >> N;
  vector<pii> party;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    sum += x;
    party.push_back(mp(x, i));
  }
  vector<string> ans;
  while (sum > 0) {
    sort(party.rbegin(), party.rend());

    // two
    if (sum >= 2) {
      for (int i = 0; i < party.size(); i++) {
        if (party[i].first == 0)
          continue;
        for (int j = 0; j < party.size(); j++) {
          if (party[j].first == 0)
            continue;
          int tmp_sum = sum - 2;
          if (check_two(party, party[i].second, party[j].second, tmp_sum)) {
            string tmp_ans = "";
            tmp_ans += (party[i].second + 'A');
            tmp_ans += (party[j].second + 'A');
            ans.push_back(tmp_ans);
            party[i].first--;
            party[j].first--;
            sum -= 2;
            goto Next;
          }
        }
      }
    }
    for (int i = 0; i < party.size(); i++) {
      if (party[i].first != 0) {
        int tmp_sum = sum - 1;
        if (check_one(party, party[i].second, tmp_sum)) {
          string tmp_ans = "";
          tmp_ans += (party[i].second + 'A');
          ans.push_back(tmp_ans);
          party[i].first--;
          sum -= 1;
          break;
        }
      }
    }
  Next:
    ;
  }
  cout << "Case #" << case_id << ":";
  for (auto &val : ans) {
    cout << " " << val;
  }
  cout << endl;
}
int main() {
  cin >> T;
  for (int i = 0; i < T; i++) {
    solve(i + 1);
  }
  return 0;
}