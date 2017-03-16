#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define repi(i,a,b) for(int i=a;i<b;++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define vi vector<int>
#define sc(a) scanf("%d",&a)
#define pb(x) push_back(x)

int a[18][18];
int r,c,n;
int pmin=1000;
void findans(int p=0,int x=0,int k=0)
{
	int i = 1 + x/c;
	int j = 1+(x%c);
	if(k>=n)
	{
		/*
		if(pmin>p)
		{
			for(int i=1;i<=r;++i)
			{
				for(int j=1;j<=c;++j)
					cout<<a[i][j]<<" ";
				cout<<endl;
			}
		}*/
		pmin = min(pmin,p);
	
		return;
	}
	if(x==r*c)return;
	a[i][j]=1;
	int pd = p + (a[i][j-1] + a[i][j+1] + a[i-1][j] + a[i+1][j]);
	findans(pd,x+1,k+1);
	a[i][j]=0;
	findans(p,x+1,k);
}	
int main()
{
	int t;
	cin>>t;
	//int r,c,n;
	repi(t_in,1,t+1)
	{
		for(int i=0;i<18;++i)for(int j=0;j<18;++j)a[i][j]=0;
		cout<<"Case #"<<t_in<<": ";
		cin>>r>>c>>n;
		//cout<<r<<" "<<c<<" "<<n<<endl;
		pmin = 10000;
		findans();
		cout<<pmin<<endl;
	}
	return 0;
}