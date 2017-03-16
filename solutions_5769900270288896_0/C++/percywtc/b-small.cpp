#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<queue> 
using namespace std;
#define FOR(i,s,e) for (int i=s;i<e;i++)
#define FOE(i,s,e) for (int i=s;i<=e;i++)
#define FOD(i,s,e) for (int i=s;i>=e;i--)
#define SET(a,e) memset(a,e,sizeof(a))
#define LL long long
#define pb push_back

int T,R,C,N,V;
bool A[20][20];

void go(int x,int y,bool put,int tot) {
//	printf("%d %d %d %d\n",x,y,put,tot);
	if (x==R && y==0) {
		if (tot-put!=N) return;
		int ret=0;
//		FOR(i,0,R) FOR(j,0,C) printf("%d%c",A[i][j],(j==C-1)?'\n':0);
		FOR(i,0,R) FOR(j,0,C) {
			ret+=(A[i][j] && A[i][j+1]);
			ret+=(A[i][j] && A[i+1][j]);	
		}
		V=min(V,ret);
//		printf("%d\n\n",ret);
		return;
	}
	A[x][y]=put;
	go(x+(y+1==C),(y+1)%C,0,tot); 
	go(x+(y+1==C),(y+1)%C,1,tot+1); 
}

int main () {
	
	scanf("%d",&T);
	
	FOE(tc,1,T) {
		V=2147483647;
		SET(A,0);
		scanf("%d%d%d",&R,&C,&N);
		go(0,0,1,1);
		go(0,0,0,0);
		printf("Case #%d: %d\n",tc,V);
	}
	
	return 0;
}

