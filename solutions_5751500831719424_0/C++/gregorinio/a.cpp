#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

string convert(string s)
{ 
    string res;
    for(int i=0;i<s.size();i++)
    {
    	if(res.size()==0)
    	{
    	     res.pb(s[i]);
    	     continue;
    	}
    	if(s[i]!=res[res.size()-1])res.pb(s[i]);
    }		
    return res;
}

int solve(int test)
{
    wez(n);
    vector<string> v,g;
    v.clear(); g.clear();
    vector<int> tab[142];
    for(int i=0;i<140;i++)tab[i].clear();
    for(int i=0;i<n;i++)
    {
    	string s;
    	cin>>s;
    	g.pb(s);
    	v.pb(convert(s));
    }	
    sort(v.begin(),v.end());
    bool ok=1;
    for(int i=0;i<n-1;i++)if(v[i]!=v[i+1])ok=0;
    printf("Case #%d: ",test);
    if(!ok)
    {
    	printf("Fegla Won\n");
    	return 0;
    }	
    for(int i=0;i<n;i++)
    {
    	int cnt=0;
    	for(int j=0;j<g[i].size();j++)
    	{
    		if(j==0)
    		{
    			cnt++;
    			//continue;
    		}
    		else if(g[i][j]!=g[i][j-1])
    		{
    			tab[i].pb(cnt);
    			cnt=1;
    		}
    		else cnt++;
    		if(j==g[i].size()-1)tab[i].pb(cnt);
    	}
    }
    /*printf("\n");
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<tab[i].size();j++)printf("%d ",tab[i][j]);
    	printf("\n");
    }*/
    int res=0;
    for(int i=0;i<tab[0].size();i++)
    {
    	int temp=99999999;
    	for(int literki=1;literki<=100;literki++)
    	{
    		int count=0;
    		for(int j=0;j<n;j++)
    		{
    			count+=max(tab[j][i]-literki,literki-tab[j][i]);
    		}
    		temp=min(temp,count);
    	}
    	res+=temp;
    }
    printf("%d\n",res);
    return 0;
}

int main()
{
    wez(t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;   
}
