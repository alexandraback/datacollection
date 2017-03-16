#include <iostream>
#include <vector>
#include <set>

using namespace std;

//#define NAME "my"
#define NAME "A-small-attempt0"
//#define NAME "A-large"

int n;
int d[1001];

int can(int k) {
  int ret = 0;
  int have = d[0];
  for (int i = 1; i < n; i++) {
    int eat = min(k, have);
    have -= eat;
    if (have > d[i]) return -1;
    ret += eat;
    have = d[i];
  }
  cerr << "a = " << k << endl;
  return ret;
}

void solveCase(int tc) {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> d[i];
  int answer1 = 0;
  for (int i = 0; i < n-1; i++)
    if (d[i+1] < d[i])
      answer1 += d[i] - d[i+1];
  int answer2 = -1;
  for (int i = 0; i <= 11000; i++) {
    int cur = can(i);
    if (cur != -1) {
      answer2 = cur;
      break;
    }
  }
  if (answer2 == -1) throw 1;
  cerr << "Case #" << (tc + 1) << ": " << answer1 << " " << answer2 << endl;
  cout << "Case #" << (tc + 1) << ": " << answer1 << " " << answer2 << endl;
}

void initialize() {
}

int main() {
  freopen(NAME".in", "rt", stdin);
  freopen(NAME".out", "wt", stdout);
  int T;
  cin >> T;
  initialize();
  for (int i = 0; i < T; i++) {
    solveCase(i);
  }
  return 0;
}
