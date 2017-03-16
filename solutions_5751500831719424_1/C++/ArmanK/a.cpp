//In the name of God
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>

#define X first
#define Y second
// #define X real()
// #define Y imag()
// #define cin fin
// #define cout fout

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int maxn = 100;

int tests, n;
string s[maxn], t[maxn];
vector<int> vc[maxn];

inline vector<int> solve (string s)
{
  vector<int> ret;
  for(int j = 0, i = 0 ; i < s.size();)
    {
      while(j < s.size() && s[i] == s[j])
	j ++;
      ret.push_back(j - i);
      i = j;
    }
  return ret;
}

inline string uniq (string s)
{
  string ret;
  for(int j = 0, i = 0 ; i < s.size() ;)
    {
      ret.push_back(s[i]);
      while(j < s.size() && s[i] == s[j])
	j ++;
      i = j;
    }
  return ret;
}

int main ()
{
  ios_base :: sync_with_stdio(0);
  cin >> tests ;
  for(int counter = 1 ; counter <= tests ; counter++)
    {
      cout << "Case #" << counter << ": " ;
      int ans = 0;
      cin >> n ;
      for(int i = 0 ; i < n ; i++)
	{
	  cin >> s[i] ;
	  t[i] = uniq(s[i]);
	  vc[i] = solve(s[i]);
	}
      bool ok = 0;
      for(int i = 0 ; i < n ; i++)
	if(t[i] != t[0])
	  {
	    cout << "Fegla Won" << endl ;
	    ok = 1;
	    break;
	  }
      if(ok)
	continue;
      for(int i = 0 ; i < vc[0].size() ; i++)
	{
	  vector<int> v;
	  for(int j = 0 ; j < n ; j++)
	    v.push_back(vc[j][i]);
	  sort(v.begin(), v.end());
	  for(int j = 0 ; j < v.size() ; j++)
	    ans += abs(v[j] - v[v.size() / 2]);
	}
      cout << ans << endl ;
    }
}
