#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef pair<int,int> P;

void solve(){
	int n;
	int p[30];
	int sum = 0;
	cin >> n;
	rep(i,n) cin >> p[i];
	rep(i,n) sum += p[i];
	int cnt = 0;
	while(true){
		cnt++;
		bool end = true;
		int M = -1;
		int a1 = -1, a2 = -1;
		rep(i,n){
			if(p[i] > 0) end = false;
			if(p[i] > M){
				M = p[i];
				a1 = i;
				a2 = -1;
			} else if(p[i] == M){
				a2 = i;
			}
		}
		if(end) break;
		if(sum == 3 && a2 != -1) a2 = -1;
		char o1, o2;
		o1 = 'A'+a1;
		if(a2 == -1){
			p[a1]--;
			sum--;
			if(cnt == 1) printf("%c",o1);
			else printf(" %c",o1);
		} else{
			p[a1]--;
			p[a2]--;
			sum -= 2;
			o2 = 'A'+a2;
			if(cnt == 1) printf("%c%c",o1,o2);
			else printf(" %c%c",o1,o2);
		}
	}
	printf("\n");
}

int main(){
	int T;
	cin >> T;
	rep(i,T){
		printf("Case #%d: ",i+1);
		solve();
	}
	
}