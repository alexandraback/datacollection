#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,n;
}a[30];
int cmp(node u,node v){
	return u.n>v.n;
}
int main()
{
	int T,ca=0;
	freopen("ina.txt","r",stdin);
	freopen("outa.txt","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof a);
		int n,ans;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			a[i].x=i;
			scanf("%d",&a[i].n);
		}
		sort(a+1,a+1+26,cmp);
		printf("Case #%d: ", ++ca);
		for (;a[1].n>a[2].n;a[1].n--){
			printf("%c ", a[1].x+'A'-1);
		}
		for (int i=26;i>2;i--)
			for (;a[i].n;a[i].n--){
				printf("%c ", a[i].x+'A'-1);
			}
		for (;a[2].n;a[2].n--)
			printf("%c%c ", a[2].x+'A'-1,a[1].x+'A'-1);
		puts("");
	}
}