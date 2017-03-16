#include <cstdio>
#include <iostream>

using namespace std;

int m[1111];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int nTest;
  scanf("%d", &nTest);

  for (int test = 1; test <= nTest; test++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &m[i]);

    int result = 0;
    int max_rate = 0;
    // first way
    for (int i = 0; i < n - 1; i++) {
      if (m[i] > m[i + 1]) {
        result = result + m[i] - m[i + 1];
        if (m[i] - m[i + 1] > max_rate)
          max_rate = m[i] - m[i + 1];
      }
    }

    printf("Case #%d: %d ", test, result);

    result = 0;
    for (int i = 0; i < n - 1; i++) {
      if (m[i] < max_rate) result += m[i];
      else result += max_rate;
    }

    printf("%d\n", result);
  }

  return 0;
}
