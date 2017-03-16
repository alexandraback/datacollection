#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 110
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,te,T,t,u,an;
int a[N][N];
char p[N],s[N];
int main() {
	freopen("repe.in","r",stdin);
	freopen("repe.out","w",stdout);
	scanf("%d",&T);
	For(te,1,T) {
		printf("Case #%d: ",te);
		scanf("%d",&n);
		scanf("%s",p+1);
		m=strlen(p+1);
		t=0;
		for (i=1;i<=m;i=j) {
			for (j=i;j<=m&&p[j]==p[i];j++);
			s[++t]=p[i];
			a[t][1]=j-i;
		}
		For(i,2,n) {
			scanf("%s",p+1);
			m=strlen(p+1);
			for (j=1,k=1;j<=m;j=u,k++) {
				for (u=j;u<=m&&p[u]==p[j];u++);
				if (k>t||s[k]!=p[j]) {
					printf("Fegla Won\n");
					goto yy1;
				}
				a[k][i]=u-j;
			}
			if (k<=t) {
				printf("Fegla Won\n");
				goto yy1;
			}
		}
		an=0;
		For(i,1,t) {
			int mi=100000000;
			sort(a[i]+1,a[i]+n+1);
			k=0;
			For(j,1,n) k+=a[i][j];
			u=0;
			For(j,1,n) {
				k-=a[i][j];
				u+=a[i][j];
				int A=a[i][j]*j-u+k-a[i][j]*(n-j);
				mi=min(mi,A);
			}
			an+=mi;
		}
		printf("%d\n",an);
		yy1:;
	}
	return 0;
}
