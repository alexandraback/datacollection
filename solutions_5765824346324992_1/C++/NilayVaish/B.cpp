#include <cassert>
#include <list>
#include <map>
#include <vector>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int main()
{
  int T; scanf("%d\n", &T); for (int ii = 1; ii <= T; ++ii)
  {
    int b, n; scanf("%d %d\n", &b, &n);
    vector<long long int> M(b); for (int i = 0;i < b; ++i) scanf("%lld", &M[i]);
    long long int lo = 0, hi = 100000LL * 10000000000LL;
    while (hi - lo > 1)
    {
      long long int mid = (lo + hi) / 2;
      long long int served = 0;
      for (int i = 0; i < b; ++i)
      {
        long long int x = mid / M[i] + 1;
        served += x;
      }

      //printf("mid: %lld, served: %lld\n", mid, served);
      if (served < n) lo = mid;
      else hi = mid;
    }
    
    long long shi = 0, slo = 0;
    for (int i = 0; i < b; ++i)
    {
      long long int x = hi / M[i] + 1;
      shi += x;
    }
    for (int i = 0; i < b; ++i)
    {
      long long int x = lo / M[i] + 1;
      slo += x;
    }
    //printf("%lld %lld\n", slo, shi);

    int index = -1;
    if (slo >= n)
    {
      long long int finished = 0;
      for (int i = 0; i < b; ++i)
      {
        if (lo % M[i] != 0)
        {
          long long int x = lo / M[i] + 1;
          finished += x;
        }
        else
        {
          long long int x = lo / M[i];
          finished += x;
        }
      }

      long long int m = n - finished; assert(m > 0);
      for (int i = 0; i < b; ++i)
      {
        if (lo % M[i] == 0)
        {
          m--; if (m == 0) { index = i; break; }
        }
      }
    }
    else
    {
      long long int finished = 0;
      for (int i = 0; i < b; ++i)
      {
        if (hi % M[i] != 0)
        {
          long long int x = hi / M[i] + 1;
          finished += x;
        }
        else
        {
          long long int x = hi / M[i];
          finished += x;
        }
      }

      long long int m = n - finished; assert(m > 0);
      for (int i = 0; i < b; ++i)
      {
        if (hi % M[i] == 0)
        {
            m--; if (m == 0) { index = i; break; }
        }
      }
    }
    printf("Case #%d: %d\n", ii, index + 1);
  }
  return 0;
}
