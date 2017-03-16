#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int tcs, n, v[1005], a1, a2, a3;
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		scanf("%i", &n);
		a1 = 0;
		a2 = 0;
		for(int i=0;i<n;i++){
			scanf("%i", &v[i]);
			if (i && v[i] < v[i-1]) a1 += v[i-1] - v[i];
			if (i) a2 = max(a2, v[i-1] - v[i]);
		}
		a3 = a2 * (n-1);
		for(int i=0;i<n-1;i++){
			if (a2 > v[i]) a3 -= (a2 - v[i]);
		}
		printf("Case #%i: %i %i\n", tc, a1, a3);
	}
}