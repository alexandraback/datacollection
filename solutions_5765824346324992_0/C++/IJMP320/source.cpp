#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

int gcd(int a, int b) {
	if(a<b) swap(a,b);
	while (b) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int lcm(int a, int b) {
	return a / gcd(a,b) * b;
}

int lcm_n(vector<int> &numbers) {
	int l;
	l = numbers[0];
	for (int i = 1; i < numbers.size(); i++) {
		l = lcm(l, numbers[i]);
	}
	return l;
}

int main() {
	int T;
	cin >> T;
	REP(t,T) {
		int B,N;
		cin >> B >> N;
		vector<int> m(B);
		REP(i,B) cin >> m[i];

		int l = lcm_n(m);

		vector<int> a(1,-1);
		for(ll i=0;i<l;i++) {
			REP(j,B) {
				if(i % m[j] == 0) {
					a.PB(j+1);
				}
			}
		}
		int k = (N % (a.size()-1));
		if(k==0) k=a.size()-1;
		int ans = a[k];
		printf("Case #%d: %d\n",t+1,ans);
	}
	return 0;
}
