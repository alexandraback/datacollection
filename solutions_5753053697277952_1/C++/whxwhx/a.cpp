#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 100;
int a[N];
int main(){
	int T, t = 0; scanf("%d",&T);
	while (T--){
		t++; printf("Case #%d: ",t);
		int n, sum = 0; scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]), sum += a[i];
		while (sum){
			int mx = 0, cnt = 0;
			rep(i,1,n) if (a[mx] < a[i]) { mx = i; cnt = 1; } else {
				if (a[mx] == a[i]) cnt++;
			}
			if (cnt == 2) {
				int t = a[mx];
				rep(i,1,n) if (a[i] == t) cout <<(char)('A'+i-1), a[i]--;
				sum -= 2;
			}
			else cout <<(char)('A'+mx-1), sum--, a[mx]--;
			cout <<' ';
		}
		cout <<endl;
	}
	return 0;
}