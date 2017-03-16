#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


int N;
int mush[1000];

void solve(int CASE) {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> mush[i];
  }

  int lazy = 0;
  int rate = 0;
  for (int i = 1; i < N; i++) {
    if (mush[i] < mush[i-1]) {
      lazy += mush[i-1]-mush[i];

      rate = max(rate, mush[i-1] - mush[i]);
    }
  }

  int regular = 0;
  for (int i = 0; i < N-1; i++) {
    regular += min(mush[i], rate);
  }


  printf("Case #%d: %d %d\n", CASE, lazy, regular);
}

int main() {
  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    solve(i);
  }

  return 0;
}
