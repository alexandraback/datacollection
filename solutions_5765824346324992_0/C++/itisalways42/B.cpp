#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair< LL, LL > PII;

LL gcd(LL x, LL y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}

LL a[1010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,Case=0;
	cin>>t;
	while(t--)
	{
		Case++;
		LL n,m,lcm=1,cnt=0,ans;
		cin>>m>>n;
		for(int i=0; i<m; i++) {cin>>a[i]; lcm = (a[i]*lcm)/gcd(a[i],lcm);}
		for(int i=0; i<m; i++) cnt += lcm/a[i];
		n %= cnt; if(n==0) n += cnt;
		priority_queue<PII> q;
		for(int i=0; i<m; i++) q.push(mp(0,-i));
		for(int i=0; i<n; i++)
		{
			PII x = q.top(); q.pop();
			ans = -x.ss+1;
			q.push(mp(x.ff-a[-x.ss],x.ss));
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	return 0;
}
