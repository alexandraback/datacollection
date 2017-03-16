#include <cstdio>
#include <cassert>

const int MAXB = 1111;

int b, n;
int barber[MAXB];

void Init() {
  assert(scanf("%d%d", &b, &n) == 2);
  for (int i = 0; i < b; ++i) {
    assert(scanf("%d", barber + i) == 1);
  }
}

bool Check(long long t) {
  long long served = b;
  for (int i = 0; i < b; ++i)
    served += t / barber[i];
  return served >= n;
}

int Rank(long long t) {
  if (!t) return n;
  long long served = b;
  --t;
  for (int i = 0; i < b; ++i)
    served += t / barber[i];
  return n - served;
}

void Work() {
  long long l = 0, r = n * 100001ll;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (!Check(mid))
      l = mid + 1;
    else
      r = mid;
  }
  int rank = Rank(l);
  for (int i = 0; i < b; ++i) {
    if (l % barber[i] == 0) {
      if (--rank == 0) {
        printf("%d\n", i + 1);
        return;
      }
    }
  }
}

int main() {
  int cases;
  assert(scanf("%d", &cases) == 1);
  for (int i = 1; i <= cases; ++i) {
    printf("Case #%d: ", i);
    Init();
    Work();
  }
  return 0;
}
