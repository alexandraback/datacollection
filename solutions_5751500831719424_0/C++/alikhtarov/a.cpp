#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

vi count(const string& s) {
  vi out;
  size_t i = 0, j = 0;
  while (i < s.size()) {
    while (j < s.size() && s[j] == s[i]) ++j;
    out.push_back(j - i);
    i = j;
  }
  return out;
}

string canon(const string& s) {
  string out;
  size_t i = 0, j = 0;
  while (i < s.size()) {
    out.push_back(s[i]);
    while (j < s.size() && s[j] == s[i]) ++j;
    i = j;
  }
  return out;  
}

int solve(const vi& v) {
  int best = 1000000;
  for (auto t : v) {
    int sol = 0;
    for (auto x : v) {
      sol += abs(x - t);
    }
    best = min(best, sol);
  }
  return best;
}

int main() {
  int ncases;
  cin >> ncases;
  for (int ncase = 1; ncase <= ncases; ++ncase) {
    int n;
    cin >> n;
    vvi sv;
    unordered_set<string> sc;
    string s;
    for (int i = 0; i < n && cin >> s; ++i) {
      sv.push_back(count(s));
      sc.insert(canon(s));
    }

    cout << "Case #" << ncase << ": ";
    if (sc.size() > 1) {
      cout << "Fegla Won" << endl;
    } else {
      int ans = 0;
      for (size_t i = 0; i < sv[0].size(); ++i) {
	vi v;
	for (size_t j = 0; j < sv.size(); ++j) {
	  assert(i < sv[j].size());
	  v.push_back(sv[j][i]);
	}
	ans += solve(v);
      }

      cout << ans << endl;
    }
  }
}
