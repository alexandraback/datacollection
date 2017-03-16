#include <iostream>
#include <stack>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

#define A first
#define B second

int max(int a, int b)
{
  if (a < b) return b;;
  return a;
}

int main()
{
  int i, j, k, n, T;
  cin >> T;
  for (int t=1; t<=T; ++t)
  {
    vector<string> strings;
    vector<int> pos;
    vector<int> len;
    cin >> n;
    for (i=0; i<n; ++i)
    {
      string s;
      cin >> s;
      strings.push_back(s);
      pos.push_back(0);
      len.push_back(s.length());
    }
    int result = 0;
    bool finish = false;
    while (!finish)
    {
      int count[101];
      for (j=0; j<=100; ++j)
        count[j] = 0;
      char prevChar = strings[0][pos[0]];
      for (j=0; j<n; ++j)
      {
        string s = strings[j];
        char c = s[pos[j]];
        int streak = 0;
        for (k=pos[j]; k<len[j] && s[k] == c; ++k)
          ++streak;
        finish |= (k >= len[j]);
        ++count[streak];
        pos[j] = k;
        if (prevChar != c)
          count[0] = -1-n;
      }
      // for (j=0; j<n; ++j)
      // {
        // cout << j << ": " << pos[j] << " " << len[j] << endl;
      // }
      if (count[0] == 0)
      {
        int minTotal = 1000000;
        for (j=1; j<=100; ++j)
        {
          int total = 0;
          for (k=1; k<=100; ++k)
          {
            //if (count[k] > 0) cout << (max(k-j, j-k)) << " " << count[k] << endl;
            total += max(k-j, j-k) * count[k];
          }
          if (total < minTotal)
            minTotal = total;
        }
        // cout << minTotal << "---" << endl;
        result += minTotal;
      }
      else if (count[0] != n)
      {
        result = -1;
        break;
      }
    }
    for (i=0; i<n; ++i)
      if (pos[i] < len[i]) result = -1;
    if (result == -1)
      cout << "Case #" << t << ": Fegla Won\n";
    else
      cout << "Case #" << t << ": " << result << "\n";
  }
	return 0;
}
