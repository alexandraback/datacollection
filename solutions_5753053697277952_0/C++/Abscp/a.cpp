#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std; 
int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	int T, a[30];
	scanf("%d",&T);
	for(int test=1; test<=T; ++test) {
		int n;
		scanf("%d", &n);
		printf("Case #%d:", test);
		for(int i=0; i<n; ++i) scanf("%d",&a[i]);
		if(n == 2) {
			for(int i=0; i<a[0]; ++i)
				printf(" AB");
			printf("\n");
			continue;
		}
		
		while(1) {
			int s = 0;
			for(int i=0; i<n; ++i) s += a[i];
			if(s == 2) {
				printf(" ");
				for(int i=0; i<n; ++i)
					if(a[i])
						printf("%c", 'A' + i);
				printf("\n");
				break;
			}
			int t=-1, mi=0;
			for(int i=0; i<n; ++i)
				if(a[i] > mi) {
					mi = a[i];
					t = i;
				}
			printf(" %c", 'A' + t);
			a[t]--;
		}
		printf("\n");
	}
	return 0;
}
