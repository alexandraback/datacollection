#include <string>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)

inline string i2s(int x) { ostringstream o; o<<x; return o.str(); }
inline int getint() { int x; scanf("%d",&x); return x; }
inline void OPEN(string name) {
	string in = name+".in"; freopen(in.c_str(),"r",stdin);
	string out = name+".out"; freopen(out.c_str(),"w",stdout);
}

// Powered By TimoAI 2.2


int mat1[4][4];
int mat2[4][4];

string solve(int r1,int r2) {
	r1--; r2--;

	int ans = -1;
	REP(i,4) {
		REP(j,4) {
			if(mat1[r1][i]==mat2[r2][j]) {
				if(ans==-1) {
					ans = mat1[r1][i];
					break;
				}
				else {
					return "Bad magician!";
				}
			}
		}
	}

	if(ans==-1) {
		return "Volunteer cheated!";
	}

	return i2s(ans);
}

int main() {
	OPEN("A");
	REP(ncase,getint()) {
		int ans1 = getint();
		REP(i,4) REP(j,4) mat1[i][j]=getint();
		int ans2 = getint();
		REP(i,4) REP(j,4) mat2[i][j]=getint();
		printf("Case #%d: %s\n",ncase+1,solve(ans1,ans2).c_str());
	}
	return 0;
}
