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

int idx=1;

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		cout << "Case #" << idx << ": ";
		idx++;
		int n;
		cin >> n;
		vector<int> vec(n);
		for(int i=0;i<n;i++){
			cin >> vec[i];
		}
		int ans1=0,ans2=0;
		for(int i=1;i<n;i++){
			if(vec[i]<vec[i-1]){
				ans1+=vec[i-1]-vec[i];
			}
		}
		int max_diff=0;
		for(int i=1;i<n;i++){
			if(vec[i-1]-vec[i]>max_diff){
				max_diff=vec[i-1]-vec[i];
			}
		}
		for(int i=0;i<n-1;i++){
			if(vec[i]>max_diff){
				ans2+=max_diff;
			}
			else ans2+=vec[i];
		}
		cout << ans1 << " " << ans2 << "\n";
	}
	return 0;
}
