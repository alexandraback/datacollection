#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <numeric>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define SIZEOF(a) (sizeof(a)/sizeof((a)[0]))

int a;
int b[4][4];
int c;
int f[4][4];

void Solve()
{
	vector<int> v(17, 0);

	FOR(j,4) v[b[a-1][j]]++;
	FOR(j,4) v[f[c-1][j]]++;
	int cnt = 0;
	int ans = 0;
	FOR(i,v.size()) if(v[i]==2){
		++cnt; ans = i;
	}
	if(cnt == 1){
		cout << ans << endl; return;
	}
	if(cnt == 0){
		cout << "Volunteer cheated!" << endl; return;
	}
	cout << "Bad magician!" << endl;
	return;
}

int main()
{
	int n; cin >> n;
	FOR(t, n){
		cin >> a;
		FOR(i,4) FOR(j,4) cin >> b[i][j];
		cin >> c;
		FOR(i,4) FOR(j,4) cin >> f[i][j];
		cout << "Case #" << t+1 << ": ";
		Solve();
	}
	return 0;
}
