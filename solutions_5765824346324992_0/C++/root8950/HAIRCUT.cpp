/********************

	root8950

*********************/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
#define ft first
#define sd second
#define MAXN MOD
#define mp make_pair
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
#define pb push_back
#define MOD 1000000007
#define PIE 3.141592653589
#define inf INT_MAX/2
#define ASST(X,L,R) assert(X >= L && X <= R)

int primes[]={2,3,5,7,11,13,17,19,23};
int idx=1;

int find_lcm(vector<int> &vec){
	int lcm=vec[0];
	int n=vec.size();
	for(int i=1;i<n;i++){
		lcm=(vec[i]*lcm)/(__gcd(vec[i],lcm));
	}
	return lcm;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		cout << "Case #" << idx << ": ";
		idx++;
		int b,n;
		cin >> b >> n;
		vector<int> m(b);
		for(int i=0;i<b;i++){
			cin >> m[i];
		}
		int lcm=find_lcm(m);
		int ans=0;
		int one_cycle=0;
		for(int i=0;i<b;i++){
			one_cycle+=lcm/m[i];
		}
		n=n%one_cycle;
		if(n==0){
			int small=inf;
			int index;
			for(int i=b-1;i>=0;i--){
				if(small>m[i]){
					small=m[i];
					index=i+1;
				}
			}
			ans=index;
		}
		else if(n>=1 && n<=b){
			ans=n;
		}
		else{
			n=n-b;
			vector<int> snap=m;
			while(ans==0){
				for(int j=0;j<b;j++){
					snap[j]--;
				}
				for(int j=0;j<b;j++){
					if(snap[j]==0 && n!=1){
						n--;
						snap[j]=m[j];
					}
					else if(snap[j]==0 && n==1){
						ans=j+1;
						break;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
