#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <set> 
#include <sstream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define REP(i,a) for(int i=0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define SIZE(c) (int)c.size()
#define ALL(c) (c).begin(),(c).end() 
typedef pair<int, int> PII;
const int INF = 1000000000;
int N;
int idx[105];
string getUnique(string a){
	string ret = "";
	ret += a[0];
	for(int i = 1; i < SIZE(a); i ++){
		if(a[i] == a[i - 1]) continue;
		ret += a[i];
	}
	return ret;
}
int solve(vector<string> v){
	memset(idx, 0, sizeof idx);
	int tot = 0;
	while(true){
		vector<int> a;
		for(int i = 0; i < SIZE(v); i ++) {
			a.push_back(1);
			idx[i] ++;
	//		cout<<"here "<<i<<" "<<idx[i]<<" "<<v[i]<<endl;
			while(idx[i] < SIZE(v[i]) && v[i][idx[i] - 1] == v[i][idx[i]]) {
//				cout<<"now here "<<i<<" "<<idx[i]<<" "<<SIZE(v[i])<<endl;
				idx[i] ++;
				a[i]++;
			}
		}

		int mn = INF;
		REP(i, SIZE(a)){
			int tmp = 0;
			REP(j, SIZE(a)) if (i != j){
				tmp += abs(a[i] - a[j]);
			}
			mn = min(mn, tmp);
		}
		//cout<<mn<<" "<<v[0]<<endl;
		tot += mn;
		if(idx[0] == SIZE(v[0])) break;
	}
	return tot;
}
int main() {
	//freopen("a.in", "r", stdin); 
	freopen("a.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-small-attempt1.in", "r", stdin); freopen("A-small-attempt1.out", "w", stdout);
	//freopen("A-small-attempt2.in", "r", stdin); freopen("A-small-attempt2.out", "w", stdout);
	//freopen("A-small-attempt3.in", "r", stdin); freopen("A-small-attempt3.out", "w", stdout);
	
	//freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	
	int nT;
	cin>>nT;
	for (int t=1; t<=nT; t++) {
		cin>>N;
		vector<string> v;
		REP(i, N){
			string a; cin>>a;
			v.push_back(a);
		}
		vector<string> p;
		REP(i, N) p.push_back(getUnique(v[i]));
		bool ok = true;
		for(int i = 1; i < N; i ++) {
			if(p[i] != p[i - 1]) {
				ok = false;
				break;
			}
		}
		printf("Case #%d: ", t);
		if (!ok) {
			cout<<"Fegla Won"<<endl;
		} else {
			cout<<solve(v)<<endl;
		}

	}
	return 0;
}
