#include<bits/stdc++.h>
#define X real()
#define Y imag()
//#define int ll
using namespace std;
typedef long long ll;
typedef complex<ll> P;
typedef pair<ll,ll> pll;
int n;
P ps[3010];
bool cmp(P a,P b)
{
	if(a.X!=b.X)
		return a.X<b.X;
	else
		return a.Y<b.Y;
}
ll cross(P a,P b)
{
	return a.X*b.Y-a.Y*b.X;
}
bool isl(P a,P b,P c)
{
	P n1=b-a, n2=c-b;
	ll t=cross(n1,n2);
	return t>=0;
}
pll conv(P a)
{
	return pll(a.X,a.Y);
}
vector<P> con;
void doit(vector<P> &ps)
{
	con.clear();
	sort(ps.begin(),ps.end(),cmp);
	for(int tt=0;tt<2;tt++)
	{
		vector<P> stk;
		for(int i=0;i<(int)ps.size();i++)
		{
			while(stk.size()>=2 && !isl(stk[stk.size()-2],stk.back(),ps[i]))
				stk.pop_back();
			stk.push_back(ps[i]);
		}
		for(int i=0;i<(int)stk.size()-1;i++)
			con.push_back(stk[i]);
		reverse(ps.begin(),ps.end());
	}
}
int ans[3010];
main()
{
	int T,no=1;
	cin>>T;
	while(no<=T)
	{
		cin>>n;
		map<pll,int> mp;
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			ps[i]=P(x,y);
			mp[conv(ps[i])]=i;
		}
		for(int i=0;i<n;i++)
			ans[i]=3010;
		for(int i=0;i<(1<<n);i++)
		{
			vector<P> np;
			for(int j=0;j<n;j++)
				if(i>>j&1)
				{
					np.push_back(ps[j]);
				}
			doit(np);
			int cut=n-np.size();
			for(P t:con)
			{
//				cout<<t<<endl;
				int ti=mp[conv(t)];
				ans[ti]=min(ans[ti],cut);
			}
		}
		if(n<=3)
			for(int i=0;i<n;i++)
				ans[i]=0;
		//ª`·NN=1,2ªºª¬ªp
		printf("Case #%d:\n",no++);
		for(int i=0;i<n;i++)
			cout<<ans[i]<<endl;
	}
}
