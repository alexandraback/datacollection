#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

#define sd(x) scanf("%d",&x);
#define slld(x) scanf("%lld",&x);
#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Fill(a, b) memset(a, b, sizeof(a))
#define INF 2000000009

typedef pair<int,int> PII;
typedef vector<int> VI;

int gcd(int a,int b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}

#define MAXN 101

int dp[MAXN][MAXN][2],cnt[MAXN],temp[MAXN];

int median(int ar[],int n)
{
	sort(ar,ar+n);
	return ar[n/2];
}

void solve()
{
	for(int i=0;i<MAXN;i++)
	{
		for(int j=0;j<MAXN;j++)
		{
			dp[i][j][0]=0;
			dp[i][j][1]=0;
		}
		cnt[i]=0;
		temp[i]=0;
	}
	int n,k=0,ans=0;
	string s;
	double mean=0;
	char last=' ';
	sd(n);
	for(int i=0;i<n;i++)
	{
		k=0;
		last=' ';
		cin>>s;
		for(int j=0;j<s.length();j++)
		{
			if(s[j]==last)
			{
				dp[i][k][0]++;
			}
			else
			{
				k++;
				dp[i][k][0]=1;
				dp[i][k][1]=s[j];
				last=s[j];
			}
			//printf("%d\n",dp[i][j][0]);
		}
		cnt[i]=k;
	}
	for(int i=1;i<n;i++)
	{
		if(cnt[i]!=cnt[i-1])
		{
			//printf("%d %d\n",cnt[i],cnt[i-1]);
			printf("Fegla Won\n");
			return;
		}
		else
		{
			for(int j=1;j<=cnt[i];j++)
			{
				if(dp[i][j][1]!=dp[i-1][j][1])
				{
					printf("Fegla Won\n");
					return;
				}
			}
		}
	}
	for(int j=1;j<=cnt[0];j++)
	{
		for(int i=0;i<n;i++)
		{
			temp[i]=dp[i][j][0];
		}
		int x=median(temp,n);
		for(int i=0;i<n;i++)
		{
			//printf("x %d %d\n",x,dp[i][j][0]);
			if(x>dp[i][j][0])ans=ans+x-dp[i][j][0];
			else ans=ans+dp[i][j][0]-x;
		}
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("in1.txt","r",stdin);
	freopen("out1.txt","w",stdout);

	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
}

