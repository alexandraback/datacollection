// Headers 
#include<bits/stdc++.h>
using namespace std;
// Global declarations
typedef long long int ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;
const int INF = 1 << 29;
// Macros
#define mp make_pair
#define el putchar('\n')
#define sp putchar(' ')
#define Fill(a,val) memset(a,val,sizeof a)
#define all(a) a.begin(),a.end()
#ifndef ONLINE_JUDGE
#define tr(a, it) for (decltype(a.begin()) it = a.begin(); it != a.end(); ++it)
#else 
#define tr(a, it) for (typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#endif
#define in(n) scanf("%d",&n)
#define inl(n) scanf("%lld",&n)
#define out(n) printf("%d",n);
#define outl(n) printf("%lld",n);

pi p[30];

int main(){
	freopen("ip.in", "r", stdin);
	freopen("op.out", "w", stdout);
	int t;
	in(t);
	int cs = 1;
	while (t--){
		int n;
		in(n);
		int sum = 0;
		for (int i = 0; i < n; ++i)
			in(p[i].first),p[i].second=i, sum += p[i].first;
		sort(p, p + n);
		vector<string>ans;
		while (true){
			string temp;			
			--sum;
			--p[n - 1].first;
			temp += 'A' + p[n - 1].second;			
			sort(p, p + n);
			int score = sum >> 1; ++score;
			if (p[n - 1].first >= score){
				--sum;
				--p[n - 1].first;
				temp += 'A' + p[n - 1].second;
				sort(p, p + n);
			}
			ans.push_back(temp);
			if (sum <= 0)break;
		}
		printf("Case #%d: ", cs++);
		tr(ans, it){
			cout << (*it); sp;
		}el;
	}
	return 0;
}