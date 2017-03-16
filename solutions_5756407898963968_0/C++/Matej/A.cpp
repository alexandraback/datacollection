#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int L, x;
set<int> S[2];
vector<int> I(4);
vector<int>::iterator it;

int main()
{
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    // input
    for (int k = 0; k <= 1; ++k)
    {
      S[k].clear();
      scanf("%d", &L);
      for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
        {
          scanf("%d", &x);
          if (i == L)
            S[k].insert(x);
        }
    }

    // solve
    it = set_intersection(S[0].begin(), S[0].end(), S[1].begin(), S[1].end(), I.begin());
    int intersectionSize = it - I.begin();
    
    // output
    printf("Case #%d: ", Ti);
    if (intersectionSize == 0)
      printf("Volunteer cheated!\n");
    else if (intersectionSize > 1)
      printf("Bad magician!\n");
    else
      printf("%d\n", I[0]);
  }
  return 0;
}
