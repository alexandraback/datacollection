#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector <int> VI;
typedef pair <int, int> PII;
const int MAXN = 1e6 + 7, Mo = 1e9 + 7;

int a[MAXN], n;
int a1, a2;

int main(){
	int t; scanf("%d", &t);
	for (int cas = 1; cas <= t; cas ++){
		printf("Case #%d: ", cas);
		scanf("%d", &n);
		for (int i=0; i<n; i++) scanf("%d", a+i);
		a1 = 0;
		int mx = 0;
		for (int i=1; i<n; i++)
			if (a[i] < a[i-1]){
				a1 += a[i-1] - a[i];
				mx = max(mx, a[i-1] - a[i]);
			}
		a2 = 0;
		for (int i=0; i<n-1; i++)
			a2 += min(mx, a[i]);
		printf("%d %d\n", a1, a2);
	}
	return 0;
}

