#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

long long  getN(long long day, vector<int> &m)
{
  long long ret = 0;
  int b = m.size();
  for (int i = 0; i < b; i ++)
    ret += day / (long long)m[i] + 1;
  return ret;
}

int main()
{
  ifstream cin("2.in");
  ofstream cout("2.out");

  int t, T;
  cin >> T;
  for (t = 1; t <= T; t ++)
  {
    cout << "Case #" << t << ": ";
    int b, n;
    cin >> b >> n;
    vector<int> m(b, 0);
    long long  minM = 0x7fffffff;
    for (int i = 0; i < b; i ++)
    {
      cin >> m[i];
      if (m[i] < minM)  minM = m[i];
    }
    if (n <= b)
    {
      cout << n << endl;
      continue;
    }
    long long l = 0, r = (long long)minM * (long long)(n - 1);
    long long  ret = -1;
    while (l <= r)
    {
      long long mid = l + (r - l) / 2;
      long long  tn = getN(mid, m);
      long long  pn = getN(mid - 1, m);
      if (tn < n)
      {
        l = mid + 1;
      }
      else
        if (pn >= n)
        {
          r = mid - 1;
        }
        else
        {
          long long  rest = n - pn;
          for (int i = 0; i < b; i ++)
            if (mid % (long long)m[i] == 0)
            {
              rest --;
              if (rest == 0)
              {
                ret = i + 1;
                break;
              }
            }
          break;
        }
    }
    cout << ret << endl;
  }
  return 0;
}

    
