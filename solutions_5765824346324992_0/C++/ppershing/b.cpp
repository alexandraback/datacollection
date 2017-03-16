#include <stdio.h>
#define FOR(x, n) for (int x=0; x<n; x++)
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <cassert>
#define MAXM 200000


using namespace std;

typedef long long int ll;


int data[MAXM];
int n, m;

int is_ok(ll time) {
  ll customers = 0;
  FOR(q, n)
    customers += 1 + (time / data[q]);
  //printf("time %lld, customers %lld\n", time, customers);
  return customers >= m;
}

void solve(int testcase) {
  scanf("%d %d", &n, &m);
  FOR(q, n) scanf("%d", &data[q]);
  if (m <= n) {
    printf("Case #%d: %d\n", testcase+1, m);
    return;
  }
  ll left = 0;
  ll right = 1000000000000000ll;
  ll middle;
  while (left + 1 < right) {
    middle = (left + right) / 2;
    if (is_ok(middle)) right = middle; else left = middle;
  }
  //printf("time %d\n", left+1);
  ll current_time = left + 1;
  FOR(q, n) m -= 1 + (current_time - 1) / data[q];
  int barber = -1;
  assert(m > 0);
  FOR(q, n) {
    if (current_time % data[q] == 0) m--;
    if (!m) {barber=q; break;}
  }

  printf("Case #%d: %d\n", testcase+1, barber+1);
}


int main() {
  int T;
  scanf("%d", &T);
  FOR(q, T) solve(q);
}
