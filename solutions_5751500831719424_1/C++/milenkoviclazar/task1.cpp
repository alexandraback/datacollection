#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;
const int oo = 0x7f7f7f7f;

int tsts, n, idx[MAXN], cnt[MAXN];
string s[MAXN];

int main()
{
  freopen("A-large.in", "r", stdin);
  freopen("my.out", "w", stdout);
  cin >> tsts;
  for (int tno = 1; tno <= tsts; tno++)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> s[i];
    }
    printf("Case #%d: ", tno);
    int ret = 0;
    memset(idx, 0, sizeof idx);
    while (idx[0] < s[0].size())
    {
      //Fegla Won
      for (int i = 0; i < n; i++)
      {
        if (s[i][idx[i]] != s[0][idx[0]])
        {
          ret = -1;
          break;
        }
      }
      if (ret == -1)
      {
        puts("Fegla Won");
        break;
      }
      memset(cnt, 0, sizeof cnt);
      int maxcnt = 0;
      for (int i = 0; i < n; i++)
      {
        while (idx[i] + 1 < s[i].size() && s[i][idx[i] + 1] == s[i][idx[i]])
        {
          cnt[i]++;
          idx[i]++;
          maxcnt = max(maxcnt, cnt[i]);
        }
      }
      int best = oo;
      for (int mid = 0; mid <= maxcnt; mid++)
      {
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
          curr += abs(cnt[i] - mid);
        }
        best = min(best, curr);
      }
      ret += best;
      for (int i = 0; i < n; i++)
      {
        idx[i]++;
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (ret != -1 && idx[i] != s[i].size())
      {
        ret = -1;
        puts("Fegla Won");
        break;
      }
    }
    if (ret != -1)
    {
      printf("%d\n", ret);
    }
  }
  return 0;
}
