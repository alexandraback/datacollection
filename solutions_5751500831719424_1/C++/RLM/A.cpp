#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

#define f(x, y) for (int x = 0; x < (int)y; ++x)
#define abs(x) max(x, -(x))

string itoa(int x) {
  ostringstream ss;
  ss << x;
  return ss.str();
}

string solve() {
  int N; cin >> N;
  vector <string> game(N);
  f(i, N) cin >> game[i];
  int c = 1;
  vector <char> chars(game[0].size());
  vector< vector<int> > count(game[0].size(), vector<int>(N, 0));
  chars[0] = game[0][0];
  ++count[0][0];
  f(i, game[0].size()-1) {
    if (game[0][i] != game[0][i+1])
      chars[c++] = game[0][i+1];
    ++count[c-1][0];
  }
  f(i, game.size()-1) {
    int p = 0;
    f(j, game[i+1].size()) {
      while (game[i+1][j] != chars[p]) {
        if (count[p++][i+1] == 0) return "Fegla Won";
        if (p >= c) return "Fegla Won";
      }
      count[p][i+1]++;
    }
    if (++p != c) return "Fegla Won";
  }
  int sum = 0;
  f(i, c) {
    sort(count[i].begin(), count[i].end());
    f(j, N) sum += abs(count[i][j] - count[i][N/2]);
  }
  return itoa(sum);
}

int main() {
  int T; cin >> T;
  for (int C = 1; C <= T; ++C) {
    cout << "Case #" << C << ": " << solve() << endl;
  }
}
