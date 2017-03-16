#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pl;

#define sl(x) scanf("%I64d",&x)
#define pl(x) printf("%I64d\n",x)
#define sf(x) sort(x.begin(),x.end(),func)
#define s(x) sort(x.begin(),x.end())
#define all(v) v.begin(),v.end()
#define rs(v) { s(v) ; r(v) ; }
#define r(v) {reverse(all(v));}
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define f(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)

const ll mod = 1000000007;
const ll inf = LLONG_MAX;
const ll ninf = LLONG_MIN;
const ld eps = 1e-12;
const ll N = 1000005;
const ll M = 5005;
const ll LOGN = 19;
ll n;
ll p[500];
int main()
{
    FILE *fin = freopen("A-large.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("A-large.out", "w", stdout);
	ll t;
	cin >> t;
	ll tt = 1;
	while(t--)
    {
        cin >> n;
        ll sum = 0;
        f(i, n)
        {
            cin >> p[i];
            sum += p[i];
        }
        cout << "Case #" << tt++ << ": ";
        while(sum > 0)
        {
            ll ma = 0, to = 0;
			f(i, n)
			{
				if(ma < p[i]) ma = p[i];
			}
			ll pt = 0, p2 = 0;
			f(i, n)
			{
				if(p[i]==ma)
				{
					++to;
					pt = i;
				}
			}
			if(to==1)
			{
			    cout << (char)(pt + 'A') << " ";
				p[pt]--;
				sum--;
			}
			else if(to==2)
			{
				f(i, n)
				{
					if(p[i]==p[pt] && i!=pt) p2=i;
				}
				cout << (char)(pt + 'A');
				cout << (char)(p2 + 'A') << " ";
				p[pt]--;
				p[p2]--;
				sum -= 2;
			}
			else
			{
			    cout << (char)(pt + 'A') << " ";
				p[pt]--;
				sum--;
			}
        }
        cout << "\n";
    }
    return 0;
}
