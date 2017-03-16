#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int N = 107;
const int L = 107;
char s[N][L];
int len[N];
vector<pair<char, int> > p[N];
vector<int> q[L];
int main()
{
  int T;
  scanf("%d", &T);
  for( int t = 0; t < T; ++t )
    {
      int n;
      scanf("%d", &n);
      for( int i = 0; i < n; ++i )
	{
	  scanf("%s", s[i]);
	  len[i] = strlen(s[i]);
	  p[i].resize(0);
	  for( int j = 0; j < len[i]; )
	    {
	      char t = s[i][j];
	      int cnt(0);
	      for( ; j < len[i] && t == s[i][j]; ++j )
		++cnt;
	      p[i].push_back( make_pair( t, cnt) );
	    }
	}
      bool ok = true;
      for( int i = 0; i < p[0].size(); ++i )
	q[i].resize(0);
      for( int i = 0; ok && i < n; ++i )
	{
	  if( p[i].size() != p[0].size() )
	    ok = false;
	  for( int j = 0; ok && j < p[i].size(); ++j )
	    {
	      if( p[i][j].first != p[0][j].first )
		ok = false;
	      else
		q[j].push_back( p[i][j].second );
	    }
	}
      printf("Case #%d: ", t + 1 );
      if( ok )
	{
	  int ans(0);
	  for( int i = 0; i < p[0].size(); ++i )
	    {
	      sort( q[i].begin(), q[i].end() );
	      for( int j = 0, k = q[i].size() - 1; j < k; ++j, --k )
		ans += q[i][k] - q[i][j];
	    }
	  printf("%d\n", ans);
	}
      else
	printf("Fegla Won\n");
    }
  return 0;
}
