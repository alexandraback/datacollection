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

ld arr[1005];
int t,n;
int main()
{
	freopen("inputA.txt","r",stdin);
	freopen("outputA.txt","w",stdout);
	cin>>t;
	int cc=0;
	while(t--)
	{
		cc++;
		cin>>n;
		ld maxi=0;
		for(int i=1;i<=n;++i)
		{
			cin>>arr[i];
			
		}
		ld ans1=0;
		for(int i=1;i<=n-1;++i)
		{
			maxi=max(maxi,arr[i]-arr[i+1]);
			ans1+=(max((ld)0.0,arr[i]-arr[i+1]));
		}
		LL anse=ans1;
		ld rate=maxi/10.00;
		LL anse2=0;
		for(int i=1;i<=n-1;++i)
		{
			anse2+=(min((LL)arr[i],(LL)maxi));
		}
		cout<<"Case #"<<cc<<": "<<anse<<" "<<anse2<<"\n";
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
