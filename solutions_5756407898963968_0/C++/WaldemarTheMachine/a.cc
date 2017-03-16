#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <sstream>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

using namespace std;

#define FOR(i,n) for(int i = 0;i < n;i++)
#define FORR(i,n) for(int i = n-1;i >= 0;i--)
#define REP(i,a,b) for(int i = (a);i<(b);++i)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define sz(a) (int)(a).size()
#define CLEAR(a) memset(a, 0, sizeof(a))
#define INF 2000000000

typedef long long LL;



int main() {
  ios_base::sync_with_stdio(0);
  int t,a1,a2;
  int b[4][4];
  int c[4][4];
  int q[17];

  cin >> t;
  FOR(tt,t) {
  	cin >> a1;
  	FOR(j,4)
  	FOR(l,4)
  	cin >> b[j][l];

  	cin >> a2;
  	FOR(j,4)
  	FOR(l,4)
  	cin >> c[j][l];

  	CLEAR(q);
  	FOR(i,4)
  	q[b[a1-1][i]]++;

  	FOR(i,4)
  	q[c[a2-1][i]]++;

  	int ans = -1;
  	bool nans = false;

  	cout << "Case #" << tt + 1 << ": ";

  	FOR(i,17)
  	if (q[i] == 2) {
  		if (ans == -1)
  			ans = i;
  		else
  		{
  			cout << "Bad magician!\n";
  			nans = true;
  			break;
  		}
  	}

  	if (!nans && ans == -1) {
  		cout << "Volunteer cheated!\n";
  	} else if (!nans) {
  		cout << ans << '\n';
  	}
  }

  return 0;
}
