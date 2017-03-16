#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> strs;
int m;
vector<vector<char> > chars;
vector<vector<int> > counts;

inline int ABS(int x)
{
  return (x < 0) ? (-x) : x;
}

void count_chars(const string &str, vector<char> &chars, vector<int> &counts)
{
  chars.clear();
  counts.clear();
  int m = 0;
  for (int i = 0; i < str.length(); ++i)
  {
    if ((m == 0) || (str[i] != chars[m - 1]))
    {
      chars.push_back(str[i]);
      counts.push_back(0);
      ++m;
    }
    ++counts[m - 1];
  }
}

int main()
{
  int cases;
  cin >> cases;
  for (int t = 1; t <= cases; ++t)
  {
    printf("Case #%d: ", t);
    int n;
    cin >> n;
    strs.clear();
    for (int i = 0; i < n; ++i)
    {
      string str;
      cin >> str;
      strs.push_back(str);
    }

    chars.resize(n);
    counts.resize(n);
    for (int i = 0; i < n; ++i)
    {
      count_chars(strs[i], chars[i], counts[i]);
    }

    bool flag = true;
    int ans = 0;
    for (int k = 0; k < n; ++k)
    {
      if (chars[k].size() != chars[0].size())
      {
        flag = false;
        break;
      }
      for (int i = 0; i < chars[0].size(); ++i)
        if (chars[k][i] != chars[0][i])
        {
          flag = false;
          break;
        }
      if (!flag) flag = false;
    }
    
    if (flag)
    {
      for (int k = 0; k < chars[0].size(); ++k)
      {
        vector<int> numcounts;
        for (int i = 0; i < n; ++i)
          numcounts.push_back(counts[i][k]);
        sort(numcounts.begin(), numcounts.end());
        int median = numcounts[numcounts.size() / 2];
        for (int i = 0; i < n; ++i)
        {
          ans += ABS(counts[i][k] - median);
        }
      }
      printf("%d\n", ans);
    }
    else
    {
      printf("Fegla Won\n");
    }
  }
  return 0;
}
