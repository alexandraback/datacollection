#include <iostream>
#include <vector>
#include <sstream>
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
  vector< vector<int> > count(N, vector<int>(game[0].size(), 0));
  chars[0] = game[0][0];
  ++count[0][0];
  f(i, game[0].size()-1) {
    if (game[0][i] != game[0][i+1])
      chars[c++] = game[0][i+1];
    ++count[0][c-1];
  }
  f(i, game.size()-1) {
    int p = 0;
    f(j, game[i+1].size()) {
      while (game[i+1][j] != chars[p]) {
        if (count[i+1][p++] == 0) return "Fegla Won";
      }
      count[i+1][p]++;
    }
    if (++p != c) return "Fegla Won";
  }
  int sum = 0;
  f(i, c) sum += abs(count[0][i] - count[1][i]);
  return itoa(sum);
}

int main() {
  int T; cin >> T;
  for (int C = 1; C <= T; ++C) {
    cout << "Case #" << C << ": " << solve() << endl;
  }
}
