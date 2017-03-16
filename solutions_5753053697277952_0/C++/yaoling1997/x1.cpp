#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 100;
int P[maxn],ans[10];
int n,i,T,tot,j,la;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int tt= 1;tt<=T;tt++){
		printf("Case #%d:",tt);
		scanf("%d",&n);
		tot= 0;
		memset(P,0,sizeof(P));
		for (i= 1;i<=n;i++){
			scanf("%d",&P[i]);
			tot+= P[i];
		}
		for (;tot;){
			printf(" ");
			la= 1;
			ans[1]= 1;
			for (i= 2;i<=n;i++)
				if (P[i]>P[ans[1]]) ans[1]= i;
			P[ans[1]]--;tot--;
			j= 1;
			for (i= 2;i<=n;i++)
				if (P[i]>P[j]) j= i;
			if (P[j]*2>tot){
				ans[++la]= j;
				P[j]--;
				tot--;
			}
			for (i= 1;i<=la;i++)
				printf("%c",ans[i]+'A'-1);
		}printf("\n");
	}return 0;
}
