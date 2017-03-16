#include <cstdio>

using namespace std;

int T,a,b;
int A[4][4],B[4][4];

int main() {
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%d",&T);
	for(int cs=1;cs<=T;++cs) {
		printf("Case #%d: ", cs);
		scanf("%d",&a);
		for(int i=0;i<4;++i) for(int j=0;j<4;++j) scanf("%d",&A[i][j]);
		scanf("%d",&b);
		for(int i=0;i<4;++i) for(int j=0;j<4;++j) scanf("%d",&B[i][j]);

		int ans,cnt=0;
		for(int i=0;i<4;++i) {
			for(int j=0;j<4;++j) if(A[a-1][i] == B[b-1][j])
				ans = A[a-1][i], cnt++;
		}

		if(cnt == 0) {
			printf("Volunteer cheated!\n");
		}
		else if(cnt > 1) {
			printf("Bad magician!\n");
		}
		else printf("%d\n",ans);
	}
}