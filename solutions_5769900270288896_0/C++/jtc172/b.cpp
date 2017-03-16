#include<cstdio>
#include<cstring>

int R,C,N,Ans,f[20][20];

void Dfs(int i,int j,int n,int a)
{
	if(a>=Ans)return;
	if(i==R&&!n)Ans=a;
	if(i==R)return;
	if(j==C){Dfs(i+1,0,n,a);return;}
	f[i][j]=0;
	Dfs(i,j+1,n,a);
	f[i][j]=1;
	if(i>0&&f[i-1][j])a++;
	if(j>0&&f[i][j-1])a++;
	Dfs(i,j+1,n-1,a);
}

int main()
{
	int TestCase,Case,i,j,k,bl;
//	freopen("b.in","rb",stdin);
//	freopen("b.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d%d%d",&R,&C,&N);
		Ans=R*C*2;
		Dfs(0,0,N,0);
		printf("Case #%d: %d\n",Case,Ans);
	}
	return 0;
}
