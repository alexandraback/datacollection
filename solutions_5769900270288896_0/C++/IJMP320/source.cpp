#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,n) for(int i=a;i<(int)(n);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define F first
#define S second
const int INF = 2000000000;
const int DX[4]={0,1,0,-1}, DY[4]={-1,0,1,0};
struct P{int x;int y;P(int X=0,int Y=0){x=X;y=Y;}};


int main() {
	int T;
	cin >> T;
	REP(t,T) {
		int R,C,N;
		cin >> R >> C >> N;
		if(N <= floor(R*C/2.0)) {
			printf("Case #%d: %d\n",t+1,0);
			continue;
		}

		int num = R*(C-1) + C*(R-1); // 壁の数(MAX)
		int add = (R*C-N);
		if(add==0) {
			printf("Case #%d: %d\n",t+1,num);
			continue;
		}

		vector<vector<bool> > b(R);
		REP(i,R) {
			b[i].resize(C);
			REP(j,C) {
				b[i][j] = false;
			}
		}

		REP(i,R) {
			REP(j,C) {
				if(i%2==0) {
					if(j%2==1) {
						N--;
						b[i][j] = true;
					}
				}
				else {
					if(j%2==0) {
						N--;
						b[i][j] = true;
					}
				}
			}
		}

		vector<int> c;
		REP(i,R) {
			REP(j,C) {
				if(!b[i][j]) {
					int t = 0;
					REP(k,4) {
						int ny = i+DY[k];
						int nx = j+DX[k];
						if(nx>=0 && nx<C && ny>=0 && ny<R) {
							if(b[ny][nx]) t++;
						}
					}
					c.PB(t);
				}
			}
		}

		sort(ALL(c));
		int ans = 0;
		REP(i,N) {
			ans += c[i];
		}
		printf("Case #%d: %d\n",t+1,ans);
	}
    return 0;
}

string IntToString(int number) {
	stringstream ss;
	ss << number;
	return ss.str();
}
int a[1000001];
int main_A() {
	REP(i,1000001) a[i]=INF;
	REP(i,21) {
		a[i]=i;
	}
	FOR(i,1,1000000) {
		string s = IntToString(i);
		reverse(ALL(s));
		a[i+1] = min(a[i+1],a[i]+1);
		int t = atoi(s.c_str());
		a[t] = min(a[t], a[i]+1);
	}

	int T;
	cin >> T;
	REP(t,T) {
		ll N;
		cin >> N;
		printf("Case #%d: %d\n",t+1,a[N]);
	}
	return 0;
}
