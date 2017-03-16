#include<bits/stdc++.h>
#define LOCAL
#define DEBUG
#define si(n) scanf("%d",&n)
#define sl(n) cin>>n
#define sf(n) scanf("%f",&n)
#define pn(n) printf("%d\n",n)
#define ps(n) printf("%d ",n)
#define pln(n) cout<<n<<endl
#define pnl() printf("\n")
#define pls(n) cout<<n<<" "
#define pl(n) cout<<n
#define FOR(i,j,n) for(i=j;i<=n;i++)
#define FORR(i,j,n) for(i=j;i>=n;i--)
#define SORT(n) std::sort(n.begin(),n.end())
#define FILL(n,a) std::fill(n.begin(),n.end(),a)
#define ALL(n) n.begin(),n.end()
#define rsz resize
#define pb push_back
#define MAXINT std::numeric_limits<int>::max()
#define MININT std::numeric_limits<int>::min()
#define getchar gc
#define putchar pc
#define iOS std::ios_base::sync_with_stdio(false)
#define endl "\n"
#define INF 1000000000000000005LL
#ifdef DEBUG
    #define debug(x) cout << #x << " = " << x << endl
#else
    #define debug(x)
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef pair<int,int> pii;
 
/**************** TEMPLATE ENDS HERE *************************/
priority_queue< pair<int,char> > q;
const int MAXN=30;
int p[MAXN];
int main() {
	int t,tt,n,i;si(t);
	FOR(tt,1,t) {
		while(!q.empty()) q.pop();
		si(n);
		int sum=0;
		FOR(i,0,n-1) {
			si(p[i]);
			sum+=p[i];
			q.push(make_pair(p[i],i+'A'));
		}
		cout<<"Case #"<<tt<<": ";
		while(!q.empty()) {
			pair<int,char> f,s;
			f=q.top();
			q.pop();
			assert(!q.empty());
			if(sum==3 && f.first==1) {
				cout<<f.second<<" ";
				sum-=1;
				continue;
			}
			s=q.top();
			q.pop();
			cout<<f.second<<s.second<<" ";
			f.first--;s.first--;
			sum-=2;
			if(f.first>0) q.push(f);
			if(s.first>0) q.push(s);
		}
		pnl();
	}
}