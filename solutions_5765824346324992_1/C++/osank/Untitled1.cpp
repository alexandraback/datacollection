# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

// Input macros
#define s(n)                        scanf("%d",&n)
#define p(n)                        printf("%d\n",n)
#define pl(n)                       printf("%lld\n",n);
#define INF                         (int)1e9
#define EPS                         1e-9
// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define mod 1000000007LL

// Useful container manipulation / traversal macros
#define all(n)                      for(int i=0;i<n;i++)
#define alls(m)                     for(int j=0;j<m;j++)
#define rep(a,n)                    for(int i=a;i<n;i++)
#define each(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all1(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define init(Arr) memset((Arr), 0, sizeof (Arr))

inline ll binpow(ll x,ll n){ll res=1;while(n){if(n&1)res*=x;x*=x;n>>=1;}return res;}
inline ll powmod(ll x,ll n, ll _mod){ll res=1;while(n){if(n&1)res=(res*x)%_mod;x=(x*x)%_mod;n>>=1;}return res;}
inline ll mulmod(ll x,ll n, ll _mod){ll res=0;while(n){if(n&1)res=(res+x)%_mod;x=(x+x)%_mod;n>>=1;}return res;}
inline ll gcd(ll a,ll b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll a, b,c,d,i,j,k,n,m,t,ar[1000001],flag,w[1010][1010],ans;
string ch,ch2;
pii p;

bool myfunction (int i,int j) { return (i<j); }

int main()
{
	    freopen("in.txt","r",stdin);
	 	freopen("out.txt","w",stdout);
int cases;

s(cases);
for(t=1;t<=cases;t++)
{

	printf("Case #%d: ",t);
	
	cin>>m;
	cin>>n;
	for(i=0;i<m;i++)
	cin>>ar[i];
	int sol=0;
	for(i=0;i<m;i++)
	{
		if(sol)
			break;
		int fir,last,mid;

		fir=0;
		last=n;

//	cout<<i;
		while(last-fir>0)
		{
			//cout<<fir<<last<<" ";
			
			ll cur=0;
			mid=(fir+last)/2;
			a=mid*ar[i];
		//	cout<<a<<"\n";
			for(j=0;j<m;j++)
			{
				if(j>i)
				{
					cur+=a/ar[j];
					if(a%ar[j]!=0)
						cur++;
					
						

				}
				else
				{
					cur+=a/ar[j];
						cur++;
						
					}
			}
			if(cur==n)
			{
				sol=1;
				cout<<i+1<<"\n";
				break;
			}
			if(cur<n)
			{
				fir=mid+1;


			}
			else
			{
				last=mid;

			}



		}

	}


}


return 0;


}
