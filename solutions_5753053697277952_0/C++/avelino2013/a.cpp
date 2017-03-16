#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, T=1, n, p[33];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int cnt=0;
		for(int i=0; i<n; i++) {
			scanf("%d", &p[i]);
			cnt+=p[i];
		}
		printf("Case #%d:", T++);
		while(cnt) {
			int m=0, id=0, m1=0, id1=0;
			for(int i=0; i<n; i++) if(p[i]>=m) m=p[i], id=i;
			for(int i=0; i<n; i++) if(p[i]>m1) m1=p[i], id1=i;
			if(2*m1>(cnt-1) || 2*m>(cnt-1)) printf(" %c%c", 'A'+id, 'A'+id1), cnt-=2, p[id]--, p[id1]--;
			else printf(" %c", 'A'+id), cnt--, p[id]--;
		}
		printf("\n");
	}
	return 0;
}
