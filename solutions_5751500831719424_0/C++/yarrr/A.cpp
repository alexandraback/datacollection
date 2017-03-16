#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <stdint.h>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <bitset>
#include <deque>
#include <list>
#include <stack>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define foreach(it, v) for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define sz(v) int((v).size())

typedef pair < char, int > group_t;

const string FAIL = "Fegla Won";
const int inf = 1e9;

vector < group_t > get_group(const string & s)
{
  vector < group_t > groups;
  int i = 0;
  while(i < s.size())
  {
    int j = i;
    while(j < s.size() && s[i] == s[j])
      ++j;
    groups.push_back(make_pair(s[i], j - i));
    i = j;
  }
  return groups;
}

bool check_groups(const vector < group_t > & first,
                  const vector < group_t > & second)
{
  if(first.size() != second.size())
    return false;
  for(int i = 0; i < first.size(); i++)
    if(first[i].first != second[i].first)
      return false;
  return true;
}

void solve()
{
  int strings_count;
  cin >> strings_count;
  vector < string > strings(strings_count);
  for(int i = 0; i < strings_count; i++)
    cin >> strings[i];
  vector < vector < group_t > > groups;
  for(int i = 0; i < strings_count; i++)
    groups.push_back(get_group(strings[i]));
  bool fail = false;
  for(int i = 0; i < strings_count - 1; i++)
    fail |= !check_groups(groups[i], groups[i + 1]);
  if(fail)
  {
    cout << FAIL;
  }
  else
  {
    int result = 0;
    int groups_count = groups[0].size();
    for(int group = 0; group < groups_count; group++)
    {
      int current_result = inf;
      for(int target = 0; target < strings_count; target++)
      {
        int try_result = 0;
        for(int i = 0; i < strings_count; i++)
        {
          try_result += abs(groups[target][group].second - groups[i][group].second);
        }
        current_result = min(current_result, try_result);
      }
      result += current_result;
    }
    cout << result;
  }
}

int main()
{
  int tests;
  cin >> tests;
  for(int test = 1; test <= tests; test++)
  {
    cout << "Case #" << test << ": ";
    solve();
    cout << endl;
  }
  return 0;
}