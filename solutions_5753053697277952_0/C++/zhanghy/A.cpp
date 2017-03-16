#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int T,N;
int p[1000];

bool balance(int sum) {
	int t1 = 0,t2 = 0;
			for (int i = 1;i <= N; i++) {
				if (t1 < p[i]) {
					t1 = p[i]; t2 = i;
				}
			}
	if (t1 > sum / 2) return false;
	else return true;
}

int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int kase = 1;kase <= T; kase++) {
		scanf("%d",&N);
		int sum = 0;
		printf("Case #%d:",kase);
		for (int i = 1;i <= N; i++) {
			scanf("%d",&p[i]);
			sum += p[i];
		}
		//cout<<sum<<endl;
		while (sum > 0) {
			int t1 = 0,t2 = 0;
			for (int i = 1;i <= N; i++) {
				if (t1 < p[i]) {
					t1 = p[i]; t2 = i;
				}
			}
			sum--; p[t2]--;
			
			printf(" %c",char('A'+t2-1));
			if (balance(sum)) {
				continue;
			} else if (sum > 0){
				t1 = 0; t2 = 0;
				for (int i = 1;i <= N; i++) {
				if (t1 < p[i]) {
					t1 = p[i]; t2 = i;
				}
				}
				p[t2]--;
				printf("%c",char('A'+t2-1));	
				sum--;
			}
		}
		printf("\n");
	}
}