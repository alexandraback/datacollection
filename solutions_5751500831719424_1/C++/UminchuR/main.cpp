#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MT(a,b,c) MP(a, MP(b, c))

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define MOD 1000000007

char str[111][111];
int idx[111];
int cnt[111];

void solve(){
	int n;
	cin>>n;
	memset(idx, 0, sizeof(idx));
	REP(i,n)cin>>str[i];
	int ret=0;
	while(1){
		int flag=0;
		memset(cnt, 0, sizeof(cnt));
		char tmp=str[0][idx[0]];
		REP(i,n){
			while(str[i][idx[i]]==tmp){
				idx[i]++;
				cnt[i]++;
			}
			if(idx[i]==strlen(str[i]))flag=1;
		}
		sort(cnt, cnt+n);
		if(cnt[0]==0){
			cout << "Fegla Won" << endl;
			return;
		}
		int ttret=1000000;
		REP(j,101){
			int tret=0;
			REP(k,n)tret+=abs(j-cnt[k]);
			ttret=min(ttret, tret);
		}
		ret+=ttret;
		if(flag){
			REP(i,n)if(idx[i]!=strlen(str[i]))flag=0;
			if(!flag){
				cout << "Fegla Won" << endl;
				return;
			}
			break;
		}
	}
	cout << ret << endl;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin>>T;
	REP(t,T){
		printf("Case #%d: ", t+1);
		solve();
	}
	return 0;
}