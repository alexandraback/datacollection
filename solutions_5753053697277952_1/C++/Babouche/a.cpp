// solution by Olivier Marty

//#define ONLINE_JUDGE
#include <bits/stdc++.h>
#define fin(i, n) for(int i = 0; i < n; i++)
#define fin2(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

#ifndef ONLINE_JUDGE
  #define debug(a) cerr << #a << " = " << (a) << endl
#else
  #define debug(a)
#endif

int N;
int Pi[26];

void parse() {
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
    scanf("%d", Pi+i);
}

void print(char l, int n) {
  for(; n >= 2; n -= 2)
    printf(" %c%c", 'A'+l, 'A'+l);
  if(n)
    printf(" %c", 'A'+l);
}

void solve() {
  int m1 = -1, m2 = -1;
  for(int i = 0; i < N; i++)
    if(m1 < 0 || Pi[i] >= Pi[m1]) {
      m1 = i;
    }
  for(int i = 0; i < N; i++)
    if(i != m1 && (m2 < 0 || Pi[i] >= Pi[m2])) {
      m2 = i;
    }
  int d = Pi[m1] - Pi[m2];
  print(m1, d);
  for(int i = 0; i < N; i++) {
    if(i != m1 && i != m2)
      print(i, Pi[i]);
  }
  for(int i = 0; i < Pi[m2]; i++)
    printf(" %c%c", 'A' + m1, 'A' + m2);
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; i++) {
    parse();
    printf("Case #%d:", i);
    solve();
    printf("\n");
    #ifdef DEBUG
		  fprintf(stderr, "%d / %d = %.2fs | %.2fs\n", i, T, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / i * T) / CLOCKS_PER_SEC);
    #endif
  }
  return 0;
}
