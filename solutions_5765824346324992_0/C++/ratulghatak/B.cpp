#include<bits/stdc++.h>

using namespace std;

#define ll long long int 
#define ss1(a) scanf("%d",&a)
#define ss2(a,b) scanf("%d %d",&a,&b)
#define ss3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loope(i,a,b) for(int i=a;i<=b;i++)
#define loopd(i,a,b) for(int i=a;i>=b;i--)
#define Loop(i,a,b) for(ll i=a;i<b;i++)
#define Loope(i,a,b) for(ll i=a;i<=b;i++)
#define Loopd(i,a,b) for(ll i=a;i>=b;i--)

#define pii pair<int,int>
typedef vector<int> vi; 
typedef vector< vi > vvi;  
#define setzero(a) fill(a,a+sizeof(a),0);
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define DEBUG if(0)

ll gcd(ll a,ll b){ return (b==0)?a:gcd(b,a%b); } ll lcm(ll a, ll b) { return (a*b)/gcd(a,b); }
ll modpow(ll a, ll n, ll mod){ ll res=1; while(n){ if(n&1)res=(res*a)%mod; a=(a*a)%mod; n>>=1; } return res; }
ll lpow(ll a, ll n){ ll res=1; while(n){ if(n&1)res*=a; a*=a; n>>=1; } return res; }
/*******************************MAIN CODE STARTS*******************************/

struct comp {
    bool operator() (const pair<ll,ll> &a, const pair<ll,ll> &b) {
		if(a.S==b.S)
		{
			return a.F > b.F; 
		}
        return a.second > b.second;
    }
};

priority_queue<pair<ll,ll> , vector<pair<ll,ll> > , comp > q;

ll n,N;
ll a[1010];
ll h[100000010];
ll til=0,mx;
void Scan()
{
	cin>>n>>N;
	til=1;mx=0;
	loop(i,0,n)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
		//q.push(mp(i,0));
		//til=lcm(a[i],til);
	}
	//cout<<til<<endl;
	return;
}

ll Out()
{
	/*ll k=0;
	while(1) 
	{
		ll x=q.top().F,y=q.top().S;
		if(y==til) break;
										//cout<<x+1<<" "<<y<<" "<<k+1<<endl; getchar();
		h[k]=x; if(k==N-1) return x+1;
		k++;
		q.pop();
		pair<ll,ll> pp= mp(x,y+a[x]); q.push(pp);
	}
	cout<<k<<endl;
	return h[(N-1)%k]+1;*/
	
	ll lo=0,hi=mx*N,mid;
	while(lo<hi)
	{
		mid=lo+(hi-lo)/2;
		ll k=0;
		loop(i,0,n)
		{
			k+=(mid/a[i])+1;
		}
		if(k>=N) hi=mid;
		else lo=mid+1;
	}
	//cout<<lo<<endl;
	ll p=0;
	loop(i,0,n)
	{
		p+=(lo/a[i])+1;
		if(lo%a[i]==0) p--;
	}
	loop(i,0,n)
	{
		if(lo%a[i]==0) p++;
		if(p==N) return (ll)(i+1);
	}
	
}
int main()
{
	int t;cin>>t;
	loope(z,1,t)
	{
		Scan();
		printf("Case #%d: %lld\n",z,Out());
	}	
	return 0;
}
