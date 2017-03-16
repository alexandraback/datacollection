#include <stdio.h>
#include <algorithm>
using namespace std;

long long timer[1002];
long long barber[1002];

long long Served(long long t, int b) {
  long long n_served = 0;
  for (int i = 0; i < b; ++i)
    n_served += t / barber[i];
  return n_served;
}

int main() {
  int t, b;
  long long n;
  scanf("%d", &t);
  for (int c = 1; c <= t; ++c) {
    scanf("%d%lld", &b, &n);
    for (int i = 0; i < b; ++i)
      scanf("%lld", &barber[i]);
    
    long long l = 0, r = 1e14;
    while (l < r) {
      long long m = (l + r) >> 1;
      if (Served(m, b) + b < n)
        l = m + 1; else r = m;
    }
    int my_barber = 0;
    if (l == 0) my_barber = n;
    else {
      for (int i = 0; i < b; ++i) 
        timer[i] = barber[i] * ((l - 1) / barber[i]);
      
      n -= Served(l - 1, b);
      for (int i = 0; i < n; ++i) {
        int min_time = 0;
        for (int j = 0; j < b; ++j)
          if (timer[j] < timer[min_time]) min_time = j;
        timer[min_time] += barber[min_time];
        my_barber = min_time + 1;
      }
    }
    printf("Case #%d: %d\n", c, my_barber);
  }
  return 0;
}