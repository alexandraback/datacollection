#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int t, n, b;
int m[2000];
int q[2000];

typedef pair<int, int> pii;

int main()
{
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt)
  {
    vector<int> seq;

    printf("Case #%d: ", tt);

    scanf("%d%d", &b, &n);
    for (int i = 0; i < b; ++i)
    {
      scanf("%d", &m[i]);
      q[i] = m[i];
    }

    if (n <= b)
      printf("%d\n", n);
    else
    {
      int ma = 0, me = 0;
      for (int i = 1; i < b; ++i)
      {
        if (q[i] < q[me])
          me = i;
        if (q[i] > q[ma])
          ma = i;
      }

      for (int i = 1; i <= b; ++i)
        seq.push_back(i);

      while (q[me] != q[ma])
      {
        seq.push_back(me + 1);
        q[me] += m[me];
        me = 0;
        ma = 0;
        for (int i = 1; i < b; ++i)
        {
          if (q[i] < q[me])
            me = i;
          if (q[i] > q[ma])
            ma = i;
        }
      }

      n--;
      int s = seq.size();
      printf("%d\n", seq[n % s]);
    }
  }

  return 0;
}
