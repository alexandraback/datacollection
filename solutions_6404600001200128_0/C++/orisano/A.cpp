#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
inline int in(){int x;scanf("%d",&x);return x;}

int M[1010];
int D[1010];

int main()
{
  int T = in();
  for (int c = 1; c <= T; c++){
    int N = in();
    for (int i = 0; i < N; i++) M[i] = in();
    for (int i = 1; i < N; i++) D[i] = M[i - 1] - M[i];
    int metA = 0;
    for (int i = 1; i < N; i++) metA += max(D[i], 0);
    int metB = 0;
    int maxd = *max_element(D + 1, D + N);
    for (int i = 1; i < N; i++) metB += min(M[i - 1], maxd);
    printf("Case #%d: %d %d\n", c, metA, metB);
  }

  return 0;
}
