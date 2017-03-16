#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int infinity = 1e9 + 9;

int R, C, N;

vector<bool> bits(int m, int count)
{
  vector<bool> ans;
  for (int i = 0; i < count; ++i)
  {
    ans.push_back(m % 2 == 1);
    m /= 2;
  }
  return ans;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    // input
    scanf("%d %d %d", &R, &C, &N);
    
    // iterate
    int best = infinity;
    for (int m = 0; m < (1 << R*C); ++m)
    {
      vector<bool> mask = bits(m, R*C);
      
      int number = 0;
      int cost = 0;
      for (int i = 0; i < R*C; ++i) {
        // count occupants
        if (mask[i])
          number++;
        // right
        if (mask[i] && (i % C != C - 1) && mask[i + 1])
          cost++;
        // below
        if (mask[i] && (i / C != R - 1) && mask[i + C])
          cost++;
      }
      if (number == N)
        best = min(best, cost);
    }
    
    // output
    printf("Case #%d: %d\n", Ti, best);
  }
  return 0;
}
