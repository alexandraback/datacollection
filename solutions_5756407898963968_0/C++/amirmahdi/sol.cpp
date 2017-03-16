#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>

#define rep(i,n) for(int i=0;i<n;i++)
#define VI vector<int>
#define pb(x) push_back(x)
#define ll long long
#define For(i,a,b) for(int i=a;i<b;i++)
#define sz(s) int(s.size())
using namespace std;

int a[5][5];
int b[5][5];
int d[20];

int main() {
	int t;
	cin >> t;
	rep(g,t){
		memset(d,0,sizeof(d));
		int r1,r2;
		cin >> r1;
		r1--;
		rep(i,4)
			rep(j,4)
				cin >> a[i][j];
		cin >> r2;
		r2--;
		rep(i,4)
			rep(j,4)
				cin >> b[i][j];
		rep(i,4)
			d[a[r1][i]]++;
		rep(i,4)
			d[b[r2][i]]++;
		int cnt = 0, ind ;
		for(int i=1;i<=16;i++)
			if(d[i] == 2){
				cnt++;
				ind = i;
			}
		cout << "Case #" << g+1 << ": " ;
		if(cnt == 1)
			cout << ind << endl;
		else if(cnt > 1)
			cout << "Bad magician!" << endl;
		else
			cout << "Volunteer cheated!" << endl;
	}
	return 0;
}
