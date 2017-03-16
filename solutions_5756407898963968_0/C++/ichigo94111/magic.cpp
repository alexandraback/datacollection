#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
int a[2];
int g[2][5][5];
int round=0;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int flag=0;
		int res;
		for(int l=0;l<=1;l++){
			scanf("%d",&a[l]);
			for(int i=1;i<=4;i++)
				for(int j=1;j<=4;j++)
					scanf("%d",&g[l][i][j]);
		}
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				int x=g[0][a[0]][i];
				int y=g[1][a[1]][j];
				if(x==y){
					flag++;
					res=x;
				}
			}
		}
		printf("Case #%d: ",++round);
		if(!flag) printf("Volunteer cheated!\n");
		else if(flag==1) printf("%d\n",res);
		else printf("Bad magician!\n");
	}
	return 0;
}