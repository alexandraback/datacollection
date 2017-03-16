#include <iostream>
#include <string>
#include <cstdio>
#include <stdint.h>
using namespace std;


int N;
int B;
int64_t barbers[1000];

int64_t F(int64_t t) {
  int64_t r = 0;
  for (int i = 0; i < B; i++) {
    r += (t + barbers[i] - 1) / barbers[i];
  }

  return r;
}

int64_t bsearch(int64_t low, int64_t high, int64_t f) {

  //cout << low << " " << high << ". mid: " << m << ": " << fm << endl;

  while (high - low != 1) {
    int64_t m = (low+high) / 2;
    int64_t fm = F(m);


    if (fm < f) low = m;
    else high = m;
  }

  return low;

  if (high - low == 1) {
    return low;
  }

  int m = (low+high) / 2;
  int fm = F(m);


  if (fm < f) return bsearch(m, high, f);
  else return bsearch(low, m, f);

}

void solve(int CASE) {
  cin >> B;
  cin >> N;


  int64_t fastest = 100000;
  for (int i = 0; i < B; i++) {
    cin >> barbers[i];
    fastest = min(fastest, barbers[i]);
  }

  int64_t t = bsearch(0, fastest * N, N);
  int64_t f = F(t);
  int b = -1;

  //cout << t << endl;
  //cout << f << endl;

  for (int i = 0; i < B; i++) {
    if (t % barbers[i] == 0) {
      ++f;

      if (f == N) {
        b = i;
        break;
      }
    }
  }

  printf("Case #%d: %d\n", CASE, b+1);
}

int main() {
  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    solve(i);
  }

  return 0;
}
