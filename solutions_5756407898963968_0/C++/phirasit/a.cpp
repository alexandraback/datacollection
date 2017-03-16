#include <stdio.h>
#include <vector>

#define PB push_back
#define N 4

using namespace std;

int t,a,b;

int main() {
	scanf("%d",&t);
	for(int Case = 1;Case <= t;Case++) {
		scanf("%d",&a);
		vector<int> V,ans;
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				int v;
				scanf("%d",&v);
				if(i == a) {
					V.PB(v);
				}
			}
		}
		scanf("%d",&b);
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				int v;
				scanf("%d",&v);
				if(i == b) {
					for(int k=0;k<V.size();k++) {
						if(V[k] == v) {
							ans.PB(v);
						}
					}
				}
			}
		}
		printf("Case #%d: ",Case);
		if(ans.size() > 1) {
			printf("Bad magician!\n");
		}else if(ans.size() < 1) {
			printf("Volunteer cheated!\n");
		}else {
			printf("%d\n",ans[0]);
		}
	}
	return 0;
}
