#include <vector>
#include <map>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <time.h>
#include <string>
#include <cstring>
using namespace std;
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define deb(x) cout << #x << ": " << x << endl;

bool conv(string a, string b)
{
  int lpos = 0, rpos = 0;
  while(true)
  {
    if(lpos == a.size() && rpos == b.size())
      break;
    if(lpos == a.size())
      return false;
    if(rpos == b.size())
      return false;

    if( a[lpos] != b[rpos] )
      return false;

    char c = a[lpos];
    while(lpos < a.size() && a[lpos] == c)
      lpos++;
    while(rpos < b.size() && b[rpos] == c)
      rpos++;
  }
  return true;
}

vector<int> getcnts(string a)
{
  int lpos = 0;
  vector<int> ret;
  while(lpos < a.size())
  {
    char c = a[lpos];
    int next = 0;
    while(lpos < a.size() && a[lpos] == c)
    {
      next++;
      lpos++;
    }
    ret.push_back(next);
  }
  for(int i = 0; i < ret.size(); i++)
  {
    //cout << ret[i] << ' ';
  }
  //cout << endl;
  return ret;
}

int main()
{
  int tests;
  cin >> tests;
  for(int tcase = 1; tcase <= tests; tcase++)
  {
    
    
    int N;
    cin >> N;
    vector<string> reps;
    for(int i = 0; i < N; i++)
    {
      string buff = "";
      cin >> buff;
      reps.push_back(buff);
    }
    bool good = true;
    for(int i = 1; i < N; i++)
    {
      if(!conv(reps[0], reps[i]))
        good = false;
    }
    if(!good)
    {
      printf("Case #%d: ", tcase);
      printf("Fegla Won\n");
      continue;
    }


    vector< vector<int> > allcnts;
    for(int i = 0; i < N; i++)
    {
      allcnts.push_back(getcnts(reps[i]));
    }
    int sts = allcnts[0].size();
    int ret = 0;
    for(int i = 0; i < sts; i++)
    {
      int mn = -1;
      for(int total = 1; total <= 100; total++)
      {
        int T = 0;
        for(int idx = 0; idx < N; idx++)
        {
          T += abs(allcnts[idx][i]-total);
        }
        if(mn == -1 || T < mn)
          mn = T;
      }
      ret += mn;
    }
    printf("Case #%d: %d\n", tcase,ret);
  }
}

      
      
