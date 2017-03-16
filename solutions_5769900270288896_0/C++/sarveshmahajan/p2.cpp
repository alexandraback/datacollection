
//~        Author : Sarvesh Mahajan                             
//               IIIT,Hyderabad                                   
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define For(i,a,b) for(i=a;i<b;i++)
#define loop(i,b) for(i=0;i<b;i++)
#define Loop(i,b) for(i=1;i<=b;i++)
#define pi(n) cout<<n<<' '
#define si(n) cin>>n
const int MOD=1e9+7;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef long long LL;
#define F first
#define S second
#define sz(x) (int) x.size()
#define pLL(x) cout<<x<<' '
#define fill(x,c) memset(x,c,sizeof(x))
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#ifdef DEBUG
#define DB(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define DB2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
#define DB3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;
#else
#define DB(x)
#define DB2(x,y)
#define DB3(x,y,z)
#endif


int r,c;
const int inf=1e9;
int get(int mask,int n)
{
	int p=0,tmp=mask;
	while(tmp)
	{
		p+=(tmp%2);
		tmp/=2;
	}

	if(p!=n)
		return inf;

	int i,j,arr[100];
	for(i=0;i<r*c;++i)
		arr[i]=(mask>>i)&1;
	int a[100][100];
	int ct=0,ctr=0;
	
	for(i=0;i<r;++i)
	{
		loop(j,c)
		a[i][j]=arr[ct++];
	}

// V lines
	for(i=0;i<r;++i)
	{
		loop(j,c-1)
		{
			if(a[i][j]+a[i][j+1] == 2)
				ctr++;
		}
	}


	//H lines
	loop(i,c)
	{
		loop(j,r-1)
		{
			if(a[j][i]+a[j+1][i] == 2)
				ctr++;
		}
	}

	return ctr;
}

int main()
{
ios_base::sync_with_stdio(false);
int n,t,m,l,k,ans,i,j,res=0,fl;
t=1;
cin>>(t);
int T=t;
Loop(t,T)
{
	cin>>r>>c>>n;
	int p=r*c;
	int LT=(1<<p);
	int ret=inf;
	for(int mask=0;mask<LT;++mask)
		ret=min(ret,get(mask,n));
	printf("Case #%d: %d\n",t,ret);

}
return 0;
}
