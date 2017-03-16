#include<iostream>
using namespace std;

const int maxn=1100;
int n,ca,num;
char ch[maxn][maxn];
int sum[maxn][maxn];
string str1,str2;
void solve()
{
	memset(sum,0,sizeof(sum));
	int tot;
	bool pp=true;
	for (int i=0; i<n; i++)
	{
		int len=strlen(ch[i]);
		tot=0;
		str2=str1; str1="";
		for (int j=0; j<len; j++)
			if ((j!=0) && (ch[i][j]==ch[i][j-1]))
			{
				++sum[i][tot];
			}
			else
			{
				str1+=ch[i][j];
				++tot;
			}
		if (i!=0)
		{
			if (str1!=str2) pp=false;
		}
	}
	
	printf("Case #%d: ",++ca);
	if (pp)
	{
		int ans=0;
		for (int i=0; i<tot; i++)
		{
			int ans1=1000000;
			for (int l=0; l<=200; l++)
			{
				int ret=0;
				for (int j=0; j<n; j++) ret+=abs(l-sum[j][i]);
				ans1=min(ans1,ret);
			}
			ans+=ans1;
		}
	}
	else printf("Fegla Won\n");
}
void init()
{
	scanf("%d",&num);
	while (num--)
	{
		scanf("%d",&n);
		for (int i=0; i<n; i++) scanf("%d",&ch[i]);
		solve();
	}
}
int main()
{	
	init();
	return 0;
}
