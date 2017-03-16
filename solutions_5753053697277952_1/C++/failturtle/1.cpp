#include <bits/stdc++.h>

#define sz(z) (int)z.size()
#define fo(i,a,b) for (auto (i) = (a); (i) < (b); (i)++)
#define mp make_pair
#define pb push_back

using namespace std;

#define DEBUG

#ifdef DEBUG
#define D(x...) printf(x)
#else
#define D(x...) 
#endif

typedef long long ll;
typedef pair<int,int> ii;

int num[256];

int main() {
	int t;
	scanf("%d\n", &t);
	for (int _ = 1; _ <= t; _++) {
		printf("Case #%d: ", _);
		int n;
		scanf("%d", &n);
		int tot = 0;
		fo(i,0,n) {
			scanf("%d", num+i);
			tot += num[i];
		}
		string s;
		vector <string> v;
		int big;
		if (tot % 2 == 1) {
			big = 0;
			fo(i,1,n) {
				if (num[i] > num[big]) {
					big = i;
				}
			}
			num[big]--;
			s.clear();
			s += big + 'A';
			v.pb(s);
			tot--;
		}
		while (tot) {
			big = 0;
			fo(i,1,n) {
				if (num[i] > num[big]) {
					big = i;
				}
			}
			num[big]--;
			s.clear();
			s += big + 'A';
			big = 0;
			fo(i,1,n) {
				if (num[i] > num[big]) {
					big = i;
				}
			}
			num[big]--;
			s += big + 'A';
			tot -= 2;
			v.pb(s);
		}
		fo(i,0,sz(v)-1) {
			cout << v[i] << ' ';
		}
		cout << v.back() << endl;
	}
	
	return 0;
}
