#include <vector>
#include <string>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

typedef pair<int,int > PII;
const int INF = 1000000000;
template<class T> inline int size(const T&c) { return c.size(); }
inline string i2s(int x) { ostringstream o; o<<x; return o.str(); }
inline int getint() { int x; scanf("%d",&x); return x; }
inline void OPEN(string name) {
	string in = name+".in"; freopen(in.c_str(),"r",stdin);
	string out = name+".out"; freopen(out.c_str(),"w",stdout);
}

// Powered By TimoAI 2.2

vector<PII> nums[128];
int N;
char temp[128];
int dp[128];

inline int myabs(int x) {
	return x<0 ? -x: x;
}

int calc(int index) {
	int &ret=dp[index];
	if(ret>=0) return ret;
	ret=INF;
	FOR(target,1,102) {
		int cost = 0;
		REP(i,N) {
			cost += myabs(target - nums[i][index].ST);
		}
		ret = min(ret, calc(index+1) + cost);
	}
	return ret;
}

string solve() {
	int target = size(nums[0]);
	REP(i,N) {
		if(size(nums[i])!=target) return "Fegla Won";
		REP(j,target) {
			if(nums[i][j].ND!=nums[0][j].ND) {
				return "Fegla Won";
			}
		}
	}
	FOR(i,0,target) dp[i]=-1;
	dp[target]=0;
	int ret = calc(0);
	return i2s(ret);
}

int main() {
	OPEN("A");
	REP(nc,getint()) {
		N=getint();
		REP(i,N) {
			nums[i].clear();
			scanf("%s",temp);
			char last = temp[0];
			int ctr = 1;
			for(int j=1;temp[j];j++) {
				if(temp[j]==last) {
					ctr++;
				}else {
					nums[i].PB(MP(ctr,last));
					last=temp[j];
					ctr=1;
				}
			}
			nums[i].PB(MP(ctr,last));
		}

		printf("Case #%d: %s\n",nc+1,solve().c_str());
	}
	return 0;
}
