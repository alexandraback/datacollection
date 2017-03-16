#include <stdio.h>
#define min(a,b) a<b?a:b
int cnt[1 << 18];
int R, C, N;
int compute(int i)
{
        int val = 1,r,c,m,p;
        m = 0;
        r = m;
        p =0;
        c=p;
        for (r = 0; r < R; r++)
        {
                for (c = 0; c < C; c++)
                {
                        if (c > 0 && (i & (1 << (r * C + c))) && (i & (1 << (r * C + c - 1))))
                                val++;
                        if (r > 0 && (i & (1 << (r * C + c))) && (i & (1 << (r * C + c - C))))
                                val++;
                }
        }
        /*#include <bits/stdc++.h>
using namespace std;
 
int fpp[1000010];
 
void func() {
	memset(fpp, 0x3f, sizeof fpp);
	fpp[1] = 1;
	long long int i=0;
	long long int j = i+1;
	for( j = 1; j < 1000000; ++j) {
		std::string tmporary = std::to_string(j);
		std::reverse(tmporary.begin(), tmporary.end());
		long long int reverse = std::stoi(tmporary)-1;
		long long int ans = reverse  +1;
		fpp[j+1] = std::min(fpp[j+1], fpp[j] + 1);
		fpp[ans] = std::min(fpp[ans], fpp[j] + 1);
	}
}
 
int main() {
	//freopen("A-large (1)","r",stdin);
//freopen("outround1.txt","w",stdout);
	func();
	/*#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

const int N = 1000;
const int MOD = 1000000007;
int dp[N+1][N+1];

int DP(int n,int k)
{
	if(n<0 || k<0 || k>n) return 0;
	return dp[n][k];
}

int lucky(int d)
{
	return d==4 || d==7;
}

int calc(VI& a,int k)
{
	int n=a.size();
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(n-i<k) break;
		for(int d=0;d<a[i];d++)
			ans=(ans+DP(n-i-1,k-lucky(d)))%MOD;
		if(lucky(a[i])) k--;
	}
	return ans;
}

int calc(VI &a)
{
	int Lucky[14]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
	int ans=0;
	for(int i=0;i<14;i++)
		ans=(ans+calc(a,Lucky[i]))%MOD;
	return ans;
}

int main()
{
	int n,k,i,j;
	dp[0][0]=1;
	for(n=1;n<=N;n++)
	{
		dp[n][0]=8LL*dp[n-1][0]%MOD;
		for(k=1;k<=n;k++)
			dp[n][k]=(2LL*dp[n-1][k-1]+8LL*dp[n-1][k])%MOD;
	}
	int TST;
	scanf("%d",&TST);
	for(int tst=0;tst<TST;tst++)
	{
		char buf[N+2];
		scanf("%s",buf);
		n=strlen(buf);
		VI cur(n);
		for(i=0;i<n;i++) cur[i]=buf[i]-'0';
		int ans=calc(cur);

		scanf("%s",buf);
		n=strlen(buf);
		for(i=n-1;i>=0 && buf[i]=='9';i--);
		if(i>=0)
		{
			for(j=n-1;j>i;j--) buf[j]='0';
			buf[i]++;
		}
		cur=VI(n);
		for(i=0;i<n;i++) cur[i]=buf[i]-'0';
		ans=(calc(cur)+MOD-ans)%MOD;
		printf("%d\n",ans);
	}
	return 0;
}*/
/*
	int incr = 1;
	long long int t;
	cin>>t;
	long long int k;
	k =t;
	long long int y;
	y = k-t;
	y = k+1;
	y = y - k + t -1;
	long long int i =1;
	while(y--) {
		long long int n;
		cin>>n;
		cout<<"Case"<<" "<<"#"<<incr<<":"<<" "<<fpp[n]<<endl;
		long long int add = 1;
		incr = incr + add;
	}
	return 0;
}*/
        return val-1;
}
int main()
{
        int m=1,i,t;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d %d %d",&R,&C,&N);
                long long int p = R -1;
                p = p + 1;
                long long int q = C -1;
                q = q + 1;
                long long int r = N -1;
                r = r + 1;
                long long int mul = 10;
                mul = mul*10;
                	/*#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

const int N = 1000;
const int MOD = 1000000007;
int dp[N+1][N+1];

int DP(int n,int k)
{
	if(n<0 || k<0 || k>n) return 0;
	return dp[n][k];
}

int lucky(int d)
{
	return d==4 || d==7;
}

int calc(VI& a,int k)
{
	int n=a.size();
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(n-i<k) break;
		for(int d=0;d<a[i];d++)
			ans=(ans+DP(n-i-1,k-lucky(d)))%MOD;
		if(lucky(a[i])) k--;
	}
	return ans;
}

int calc(VI &a)
{
	int Lucky[14]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
	int ans=0;
	for(int i=0;i<14;i++)
		ans=(ans+calc(a,Lucky[i]))%MOD;
	return ans;
}

int main()
{
	int n,k,i,j;
	dp[0][0]=1;
	for(n=1;n<=N;n++)
	{
		dp[n][0]=8LL*dp[n-1][0]%MOD;
		for(k=1;k<=n;k++)
			dp[n][k]=(2LL*dp[n-1][k-1]+8LL*dp[n-1][k])%MOD;
	}
	int TST;
	scanf("%d",&TST);
	for(int tst=0;tst<TST;tst++)
	{
		char buf[N+2];
		scanf("%s",buf);
		n=strlen(buf);
		VI cur(n);
		for(i=0;i<n;i++) cur[i]=buf[i]-'0';
		int ans=calc(cur);

		scanf("%s",buf);
		n=strlen(buf);
		for(i=n-1;i>=0 && buf[i]=='9';i--);
		if(i>=0)
		{
			for(j=n-1;j>i;j--) buf[j]='0';
			buf[i]++;
		}
		cur=VI(n);
		for(i=0;i<n;i++) cur[i]=buf[i]-'0';
		ans=(calc(cur)+MOD-ans)%MOD;
		printf("%d\n",ans);
	}
	return 0;
}*/
                long long int ans = p * q * r * mul;
                for (i = 1; i < (1 << (p * q)); i++)
                {
                        cnt[i] = cnt[i - (i & -i)] + 1;
                        if (cnt[i] == r)
                               ans = min(ans, compute(i));
                }
                printf("Case #%d: %d\n", m++, ans);
        }
}