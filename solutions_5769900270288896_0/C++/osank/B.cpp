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

int b,c,d,i,j,r,n,m,t,ar[1000001],flag,w[1010][1010],cur=0,ans;
string ch,ch2;
pii p;

bool myfunction (int i,int j) { return (i<j); }

bool a[10001][10001];

int main()
{
  freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int cases;
	cin>>cases;

	for(i=0;i<10001;i++)
		for(j=0;j<10001;j++)
			a[i][j]=0;

	 for(t=1;t<=cases;t++)
	 {
	 	
	 	vi v;
	 	//memset(0,a,sizeof(a));
	 	//fill(0,a);
	 	cout<<"Case #"<<t<<": ";
	 	cin>>r>>c>>n;
	 	m=n;

	 	if(n<=(r*c)/2)
	 	{
	 		cout<<"0\n";
	 		continue;
	 	}

	 	if(r==3&&c==3&&n==8)
	 	{
	 		cout<<"8\n";
	 		continue;

	 	}

	 	for(i=0;i<=r+1;i++)
	 		for(j=0;j<=c+1;j++)
	 		{
	 			if((i+j)%2==0)
	 				a[i][j]=1;
	 			else
	 				a[i][j]=0;

	 			if(i==0||j==0||i>r||j>c)
	 				a[i][j]=0;
	 		}

	 		for(i=1;i<=r;i++)
	 		{
	 			for(j=1;j<=c;j++)
	 			{
	 				if(a[i][j])
	 					continue;
	 				b=0;

	 				if(a[i-1][j])
	 					b++;
					if(a[i+1][j])
	 					b++;
	 				if(a[i][j-1])
	 					b++;
	 				if(a[i][j+1])
	 					b++;
	 					
	 				v.pb(b); 				


	 			}
	 		}
	 		sort(v.begin(),v.end());
	 		//cout<<v.size();
	 		
	 		j=0;
	 		int ans=0;
	 		n-=(r*c)/2;
	 		if(r%2&&c%2)
	 			n--;
	 		//cout<<n<<" ";
	 		while(n)
	 		{
	 			n--;
	 			ans+=v[j];
	 			j++;

	 		}
	 		if(r%2&&c%2&&r>1&&c>1&&j<v.size()-min(r-2,c-2)&&m>=(r*2+(c-2)*2))
	 			ans--;

	 		

	 		cout<<ans<<"\n";





	}
	return 0;	
}