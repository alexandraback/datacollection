#include <bits/stdc++.h>

using namespace std;

int tsts, n;
string a, b;

int main()
{
  freopen("A-small-attempt1.in", "r", stdin);
  freopen("my.out", "w", stdout);
  cin >> tsts;
  for (int tno = 1; tno <= tsts; tno++)
  {
    cin >> n;
    if (n > 2)
    {
      for (int i = 0; i < n; i++)
      {
        cin >> a;
      }
      continue;
    }
    cin >> a >> b;
    printf("Case #%d: ", tno);
    int ret = 0;
    for (int ida = 0, idb = 0; ida < a.size() || idb < b.size(); ida++, idb++)
    {
      //Fegla Won
      if (a[ida] != b[idb])
      {
        puts("Fegla Won");
        ret = -1;
        break;
      }
      int cnta = 1, cntb = 1;
      while (ida + 1 < a.size() && a[ida + 1] == a[ida])
      {
        cnta++;
        ida++;
      }
      while (idb + 1 < b.size() && b[idb + 1] == a[ida])
      {
        cntb++;
        idb++;
      }
      ret += abs(cnta - cntb);
    }
    if (ret != -1)
    {
      printf("%d\n", ret);
    }
  }
  return 0;
}

