//Shubham Vijayvargiya

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define sz(a) (int)(a.size())
#define set(a,b) memset(a,b,sizeof(a))
#define let(x,a) __typeof(a) x(a)
#define rep(i, begin, end) for (ll i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(v) (v).begin(),(v).end()
#define sll(x) { scanf("%lld",&x); }
#define si(x) { scanf("%d",&x); }
#define slf(x) { scanf("%lf",&x); }
#define pll(x) { printf("%lld\n",x); }
#define pi(x) { printf("%d\n",x); }
#define tcases() long long testcases; cin>>testcases ; while(testcases--)

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " = " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " = " << arg1<<" | ";__f(comma+1, args...);
}

#else
#define trace(...)
#endif

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<long long,long long> pll;
typedef vector<long long> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;

const ll mod=1000000007;
//-----------------------------------------------------------------------------------------------------------------------------------------------//
ll a[30];

int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll tccc;
	sll(tccc);
	for(int tcc=1;tcc<=tccc;tcc++){
		cout<<"Case #"<<tcc<<": ";
		ll n,cnt=0;
		sll(n);
		rep(i,0,n){
			sll(a[i]);
			if(a[i]!=0){
				cnt++;
			}
		}
		while(cnt>0){
			if(cnt==2){
				ll i1=-1,i2=-1;
				rep(i,0,n){
					if(a[i]!=0){
						if(i1==-1){
							i1=i;
							a[i]--;
						}
						else{
							i2=i;
							a[i]--;
						}
					}
				}
					cout<<char('A'+i1)<<char('A'+i2)<<" ";
			}
			else{
				ll mx=0,ans=-1;
				rep(i,0,n){
					if(a[i]>mx){
						mx=a[i];
						ans=i;
					}
				}
				cout<<char(ans+'A')<<" ";
				a[ans]--;
			}
			cnt=0;
			rep(i,0,n){
				if(a[i]!=0)
					cnt++;
			}
		}
		cout<<endl;
	}

	return 0;
}


