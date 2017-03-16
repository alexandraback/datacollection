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
const int MAXN = 105;
int board[MAXN][MAXN];
int cnt[MAXN], T;
set<int> get(int a) {
	set<int> ret;
	REP(i, 4) {
		REP(j, 4){
			int x; cin>>x;
			if(i == a) {
				cnt[x]++;
			}
		}
	}
	return ret;
}
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a-small.out", "w", stdout);
	cin>>T;
	REP(t, T){
		memset(cnt, 0, sizeof cnt);
		int a; cin>>a; get(a - 1);
		cin>>a; get(a - 1);
		int idx = -1;
		string ret = "";
		for(int i = 1; SIZE(ret) == 0 && i <= 16; i ++) {
			if(cnt[i] == 2){
				if (idx == -1) {
					idx = i;
				} else{
					ret = "Bad magician!";
					break;
				}
			}
		}
		if (SIZE(ret) == 0 && idx == -1) {
			ret = "Volunteer cheated!";
		}
		if (SIZE(ret) == 0) {
			cout<<"Case #"<<(t+1)<<": "<<idx<<endl;
		} else {
			cout<<"Case #"<<(t+1)<<": "<<ret<<endl;			
		}
	}
	return 0;
}
