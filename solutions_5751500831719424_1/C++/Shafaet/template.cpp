#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <assert.h>
#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sz(x) (int)x.size()
#define inf (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define pii pair<int,int>
#define pll pair<i64,i64>
#define pmp make_pair
#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define sds(x) scanf("%s",x)
#define pfi(x) printf("%d\n",x);
#define uu first
#define vv second
using namespace std;
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/__gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
typedef  long long i64;
typedef unsigned long long ui64;
double log(double N,double B){  return (log10l(N))/(log10l(B)); }
vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
b.end(), *q ) ) q++;}return oot;
}

//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1<<(pos)))
#define off(n,pos)  n & ~(1<<pos)
#define ison(n,pos) (bool)(n & (1<<(pos)))
string toBin(int n){ string s; repv(i,32)s+=(ison(n,i)+'0');return s;}
bool eq(long double a,long double b){return fabs(a-b)<eps;}
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case #%d: ",++ks);

using namespace std;
vector<int>freq[10002];
string f(string s,int idx)
{
	string w;
	string w2;
//	int c=0;
	//int flag=0;
	rep(i,sz(s))
	{
		if(!i or s[i]==s[i-1]) w2+=s[i];
		
		if(i and s[i]!=s[i-1])
		{
			freq[idx].pb(sz(w2));
		//	cout<<">>"<<w2<<endl;
			w2=s[i];
		}
		if(i and s[i]==s[i-1]) {
			continue;
		}
		w+=s[i];
	}
	freq[idx].pb(sz(w2));
	//cout<<">>"<<w2<<endl;
	return w;
}
int main() {
		string inp[1111];
		READ("in");
		WRITE("out3");
		int t,ks=0;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
			set<string>ms;
			rep(i,n+1)freq[i].clear();
			rep(i,n){
				cin>>inp[i];
				string s=inp[i];
				string ret=f(s,i);
		//		cout<<ret<<endl;
				ms.insert(ret);
			}
			pks;
			if(sz(ms)>1)
			{
					puts("Fegla Won");
			}
			else
			{
				int ans=0;
				int lim=sz(freq[0]);
				rep(j,lim)
				{
					int mn=1<<28;
					repl(ban,105)
					{
						int need=0;
						rep(i,n)
						{
							need+=abs(freq[i][j]-ban);	
						}
						mn=min(mn,need);
					}
					ans+=mn;
					
				}
				cout<<ans<<endl;
			}
		}
	return 0;
}
