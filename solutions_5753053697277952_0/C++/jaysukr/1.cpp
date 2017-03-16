#include<bits/stdc++.h>

#define repi(n) for(int i=0;i<(n);++i)
#define repj(n) for(int j=0;j<(n);++j)
#define repr(i,m,n) for(int i=(m);i<=(n);++i)
#define rep1i(n) for(int i=1;i<=(n);++i)
#define sz(a) int((a).size)
#define pb(v) push_back(v)
#define mp(a,b)	make_pair((a),(b))
#define all(v) (v).begin(),(v).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i!=(c).end();++i)
#define pre(c,v) ((c).find()!=(c).end)
#define vpre(c,v) (find(all(c))!=(c).end())
#define nl cout<<endl

#define fi first
#define sec second

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vii;
typedef vector<vl> vll;
typedef pair<int,int> ii;



int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int test;
	cin >> test;
	for(int cs=1;cs<=test;++cs)
	{
		int n;
		cin >> n;
		vi a(n+1);
		int sum=0;
		repi(n){
		
			cin >> a[i];
			sum+=a[i];
		}
		a[n]=-1;
		
		cout << "Case #" << cs <<": ";
		while(sum>0)
		{
			int f=n,s=n,t=n;
			repi(a.size())
			{
				if(a[i]>0 && a[i]>a[f])
				{
					f=i;
				}
			}
			repi(a.size())
			{
				if(a[i]>0 && i!=f && a[i]>a[s])
				{
					s=i;
				}
			}
			repi(a.size())
			{
				if(a[i]>0 && i!=s && i!=f && a[i]>a[t])
				{
					t=i;
				}
			}
			if(sum%2 && f!=n)
			{
				if((a[f]-1)*2<sum && a[s]*2<sum && a[t]*2<sum)
				{
					cout << (char)('A'+f) << " ";
					a[f]--;
					sum-=1;
					continue;
				}
			}
	//		cout << sum << " " << f <<" " << s <<" " << t<< endl;
			if(f!=n && s!=n) // top two exists
			{
				if((a[f]-1)*2<sum && (a[s]-1)*2<sum && (a[t]*2<sum))
				{
					cout << (char)('A'+f) << (char)('A'+s) << " ";
					a[f]--;
					a[s]--;
					sum-=2;
					continue;
				}
				if((a[f]-2)*2<sum && a[s]*2<sum && a[t]*2<sum && a[f]>=2)
				{
					cout << (char)('A'+f) << (char)('A'+f) << " ";
					a[f]--;
					a[f]--;
					sum-=2;
					continue;
				}
			}
			cout << "ERROR\n";
		}
		cout << endl;
	}

  	return 0;
}

