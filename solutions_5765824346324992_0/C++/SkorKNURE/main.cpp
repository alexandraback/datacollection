#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//#define NAME "my"
#define NAME "B-small-attempt0"
//#define NAME "B-large"

int n, k;
int t[1000];

int64_t getReady(int64_t time) {
  int64_t ready = 0;
  for (int i = 0; i < n; i++) {
    ready += time / t[i];
    if (time % t[i]) ready++;
  }
  return ready;
}

void solveCase(int tc) {
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> t[i];
  int64_t lo = 0LL, hi = 1000000000LL * 1000000000;
  while (hi - lo > 1) {
    int64_t mid = (hi + lo)/2;
    if (getReady(mid) < k)
      lo = mid + 1;
    else
      hi = mid;
  }
  if (getReady(lo) < k) lo++;
  if (getReady(lo) < k) throw 1;
  cerr << lo << endl;
  vector<pair<int, int>> idx;
  int64_t total = getReady(lo);
  cerr << total << endl;
  for (int i = 0; i < n; i++) {
    if ((lo-1) % t[i] == 0)
      idx.push_back(make_pair(1, i));
  }
  sort(idx.begin(), idx.end());
  int delta = total - k;
  int pos = idx.size() - delta - 1;
  if (pos < 0) throw 2;
  int answer = idx[pos].second + 1;
  cerr << "Case #" << (tc + 1) << ": " << answer << endl;
  cout << "Case #" << (tc + 1) << ": " << answer << endl;
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
  double totalTime = clock()*1./CLOCKS_PER_SEC;
  fprintf(stderr, "Time: %.2lf sec\n", totalTime);
  return 0;
}
