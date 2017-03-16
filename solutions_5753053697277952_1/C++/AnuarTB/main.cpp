#include <bits/stdc++.h>

#define F first
#define S second
#define llong long long 
#define ullong unsigned long long 
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define sz(v) (int)v.size()

using namespace std;

const int MXN = (int)1e6 + 10;
const int INF = (int)1e9 + 7;
const llong LINF = (llong)1e18 + 10;
const double EPS = (double)1e-9;
const double PI = (double)acos(-1.0); 

int n, T;
int a[MXN];

int main(){
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	scanf("%d", &T);
	for(int tests = 1; tests <= T; ++tests){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}       
		printf("Case #%d: ", tests);
		int mn = *min_element(a, a + n);
		int mx_id;
		while(1){
		  mx_id = max_element(a, a + n) - a;
			if(a[mx_id] == mn){
				break;
			}	
			printf("%c ", char(mx_id + 'A'));
			a[mx_id]--;
		}
  	for(int i = 0; i < n - 2; ++i){
  		for(int j = 0; j < mn; ++j){
  			printf("%c ", char(i + 'A'));
  		}
  	}
  	for(int i = 0; i < mn; ++i){
  		printf("%c%c ", char(n - 2 + 'A'), char(n - 1 + 'A'));
  	}
  	printf("\n");
  }
	return 0;
}