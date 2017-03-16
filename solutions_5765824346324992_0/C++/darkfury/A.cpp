#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
 
using namespace std;
#define LL int
#define pb push_back
#define pLL pair<LL,LL>
#define ff first
#define ss second
#define pii pair<LL,LL>
#define rep(i,a,b) for(LL i=a;i<=b;++i)
#define ld long double
#define tr(n) cin>>n
#define tr2(n,m) cin>>n>>m
#define tr3(a,b,c) cin>>a>>b>>c
#define mp make_pair
#define vLL vector<LL>
#define vpLL vector<pLL>
#define vii vector<pii>
#define vii vector<pii>
#define vld vector<ld>
#define pld pair<ld,ld>
#define vpld vector<pld>
#define Si set<LL>
#define SLL set<LL>
#define SpLL set<pLL>
#define Sii set<pii>
#define fill(a,v) memset(a,v,sizeof(a))
#define MOD 1000000007
#define NM 100005
#define LNM 20

LL poww(LL a, LL n)
{
	if(n==0)return 1;
	if(n==1)return a%MOD;
	LL v=poww(a,n/2);
	v=(v*v)%MOD;
	if(n%2)
	v=(v*a)%MOD;
	
	return v;
}

LL arr[15];
LL anse[50000007];
LL pre[15];
LL t,n;
int main()
{
	freopen("inputA.txt","r",stdin);
	freopen("outputA.txt","w",stdout);
	cin>>t;
	int cc=0;
	set<pLL> S;LL m;
	while(t--)
	{
		cc++;
		cin>>n;cin>>m;
		for(int i=1;i<=n;++i)cin>>arr[i];
	//	memset(freq,0,sizeof(freq));
		S.clear();
		LL lcm=arr[1];
		LL gcd=arr[1];
		for(int i=2;i<=25*25*25*25*25;++i)
		{
			int fl=0;
			for(int j=1;j<=n;++j)
			if(i%arr[j])fl=1;
			if(fl==0)
			{
			lcm=i;break;}
		}
	//	cout<<lcm<<"\n";
		LL nmax=0;
		for(int i=1;i<=n;++i)
		nmax+=lcm/arr[i];
		
		for(int i=0;i<=nmax+1;++i)
		anse[i]=0;
		LL cnt=0;
		for(int i=1;i<=n;++i)
		{
			cnt+=1;
			S.insert(pLL(arr[i],i));
			anse[i]=i;
			pre[i]=arr[i];
			
		}
		for(LL i=n+1;i<=nmax;++i)
		{
			pLL beg=(*(S.begin()));
			S.erase(S.begin());
			S.insert(pLL(beg.ff+arr[beg.ss],beg.ss));
			anse[i]=beg.ss;
		}
		LL ans=0;
		if(m%nmax==0)ans=nmax;
		else
		ans=m%nmax;
	//	cout<<nmax<<" "<<anse[1]<<"\n";
		cout<<"Case #"<<cc<<": "<<anse[ans]<<"\n";
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
