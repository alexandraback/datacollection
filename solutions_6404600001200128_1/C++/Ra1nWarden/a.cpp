#include <cstdio>
#include <algorithm>
#define MAXN 1005

using namespace std;

int v[MAXN];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    int first = 0;
    for(int i = 1; i < n; i++) {
      if(v[i] < v[i-1])
	first += v[i-1] - v[i];
    }
    int second = 0;
    double rate = 0.0;
    for(int i = 1; i < n; i++) {
      if(v[i] < v[i-1]) {
	rate = max(rate, (v[i-1] - v[i]) / 10.0);
      }
    }
    for(int i = 0; i < n - 1; i++) {
      second += min((int) (rate * 10), v[i]);
    }
    printf("Case #%d: %d %d\n", kase, first, second);
  }
  return 0;
}
