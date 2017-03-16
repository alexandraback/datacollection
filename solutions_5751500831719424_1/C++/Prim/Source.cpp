#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define vi vector <int>
#define vii vector <pair<int,int> >
#define ll long long
#define f first
#define s second

using namespace std;

int t, i, j, t1, n, cnt, e, tmp, ans;
vector <string> vs;
vi v;
vector <pair<char,int> > g [101];
char c;

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("D.out", "w", stdout);

	scanf ("%d", &t);
	for(t1 = 1; t1 <= t; ++t1){
		scanf ("%d", &n);
		vs.clear();
		vs.resize(n);
		for(i = 0; i < n; i++) cin>>vs[i];

		for(i = 0; i < n; i++){
			c = vs[i][0];
			cnt = 1;
			for(j = 1; j < vs[i].size(); j++){
				if(vs[i][j] == c) cnt++;
				else{
					g[i].pb(mp(c,cnt));
					c = vs[i][j];
					cnt = 1;
				}
			}
			g[i].pb(mp(c,cnt));
		}
		/////////////////////////////////////////////
		cnt = g[0].size();
		for(i = 1; i < n; i++){
			if(g[i].size() != cnt){
				cout<<"Case #"<<t1<<": "<<"Fegla Won"<<endl;
				goto hell;
			}
		}
		ans = 0;
		for(j = 0; j < cnt; j++){
			c = g[0][j].f;
			v.clear();
			for(i = 0; i < n; i++){
				if(g[i][j].f != c){
					cout<<"Case #"<<t1<<": "<<"Fegla Won"<<endl;
					goto hell;
				}
				v.pb(g[i][j].s);
			}
			e = 1000000;
			for (i = 0; i < v.size(); i++){
				tmp = 0;
				for (int k = 0; k < v.size(); k++){
					if (i == k) continue;
					tmp += abs(v[k] - v[i]);
				}
				e = min(e, tmp);
			}
			ans += e;
		}
		cout<<"Case #"<<t1<<": "<<ans<<endl;

hell : ;
		for(i = 0; i < 101; i++)g[i].clear();
	}

	return 0;
}