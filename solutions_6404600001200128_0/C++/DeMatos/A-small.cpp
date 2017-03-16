#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("inputAsmall.txt", "r", stdin);
	freopen("outputAsmall.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int test = 1; test<=t; test++) {
		int n;
		int case1 = 0, case2 = 0;
		vector<int> m;
		m.clear();
		scanf("%d", &n);
		for(int i = 0; i<n; i++) {
			int x;
			scanf("%d", &x);
			m.push_back(x);
		}
		for(int i = 1; i<n; i++) {
			if(m[i] < m[i-1]) {
				case1+= m[i-1]-m[i];
			}
		}
		for(int i = 1; i<n; i++) {
			if(m[i] < m[i-1]) {
				int aux = (m[i-1]-m[i]);
				case2 = max(aux, case2);
			}
		}
		int auxCase2 = 0;
		for(int i = 0; i<n-1; i++) {
			auxCase2 += min(m[i], case2);
		}
		printf("Case #%d: %d %d\n", test, case1, auxCase2);
	}	
	return 0;
}