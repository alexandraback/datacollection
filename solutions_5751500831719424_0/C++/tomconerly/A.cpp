#include <iostream>
#include <string>
#include <vector>

using namespace std;

string order(const string& s) {
  string res = "";
  for (auto ch : s) {
    if (res.size() == 0 || res[res.size()-1] != ch) {
      res += ch;
    }
  }
  return res;
}

vector<int> lengths(const string& s) {
  vector<int> res;
  char prev = 'A';
  for (auto ch : s) {
    if (ch != prev) {
      res.push_back(1);
    } else {
      res[res.size()-1]++;
    }
    prev = ch;
  }
  return res;
}

int solve(const vector<int> lens) {
  int best = 1000000;
  for (auto l : lens) {
    int score = 0;
    for (auto a : lens) {
      score += abs(a - l);
    }
    best = min(best, score);
  }
  return best;
}

int main() {
  int T;
  cin >> T;
  for (int zz = 1; zz <= T; zz++) {
    cout << "Case #" << zz << ": ";
    int N;
    cin >> N;
    vector<string> S(N);
    vector<string> O(N);
    for (int i = 0; i < N; i++) {
      cin >> S[i];
      O[i] = order(S[i]);
    }
    bool lose = false;
    for (int i = 0; i < N; i++) {
      if (O[0] != O[i]) {
        lose = true;
        break;
      }
    }
    if (lose) {
      cout << "Fegla Won" << endl;
      continue;
    }
    vector<vector<int>> L(N);
    for (int i = 0; i < N; i++) {
      L[i] = lengths(S[i]);
    }
    int ans = 0;
    for (int i = 0; i < L[0].size(); i++) {
      vector<int> len(N);
      for (int j = 0; j < N; j++) {
        len[j] = L[j][i];
      }
      ans += solve(len);
    }
    cout << ans << endl;
  }
}
