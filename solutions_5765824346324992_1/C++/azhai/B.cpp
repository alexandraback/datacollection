#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int B_MAX = 1024;
const long long M_MAX = 100100;
int B;
long long N;
long long times[B_MAX];

bool can_serve(long long t) { // I can be serviced on or before time t
  long long served = 0;
  for (int i = 0; i < B; i++) {
    served += t / times[i];
  }
  return (N - served) <= (long long) B;
}

void init() {
  cin >> B >> N;
  for (int i = 0; i < B; i++)
    cin >> times[i];
}

void solve_case(int t) {
  init();

  long long low = 0; long long high = M_MAX * N;
  while (low < high) {
    long long mid = (low + high) / 2;
    if (can_serve(mid))
      high = mid;
    else
      low = mid + 1;
  }
  long long serve_time = low;
  // cout << "serve time " << serve_time << endl;

  long long served = 0;
  vector<int> avail;
  for (int i = 0; i < B; i++) {
    served += serve_time / times[i];
    if (serve_time % times[i] == 0)
      avail.push_back(i);
    else
      served++;
  }
  // cout << "num served " << served << endl;
  assert(served < N);
  assert(N - served <= avail.size());
  int answer = avail[N - served - 1] + 1;

  cout << "Case #" << t << ": " << answer << "\n";
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
