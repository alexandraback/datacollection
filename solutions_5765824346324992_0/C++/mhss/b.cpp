#include <bits/stdc++.h>

using namespace std;

#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)
#define fre(a,b) for(int a = adj[b]; ~a; a = ant[a])
#define cl(a,b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%lld", &a)
#define sc2(a,b) scanf("%lld%lld", &a, &b)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)

#define iter(a) __typeof((a).begin())
#define fore(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

const int oo = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vii;

#define N 1009

ll n, l, a[N], ans, soma;

int main() {
	int cn = 1;
	ll t;
	sc(t); while (t--) {
		sc2(n, l);
		soma = 0ll;
		rp(i, n) {
			sc(a[i]);
			soma += a[i];
		}
		if (l <= n) ans = l;
		else {
			ll low = *min_element(a, a+n);
			ll hi = (soma*l)/n + 10ll, mid;
			while (low+1 < hi) {
				mid = (low+hi-1)/2ll;
				ll cnt = 0;
				rp(i, n) cnt += (mid+a[i])/a[i];
				
				//db(low _ hi _ mid _ cnt);
				if (cnt >= l) hi = mid+1;
				else low = mid+1;
			}
			//db(low);
			
			int c2 = 0;
			rp(i, n) c2 += (low+a[i]-1)/a[i];
			//db(c2);
			int dif = l-c2;	
			rp(i, n) {
				if (low%a[i] == 0) {
					//db(i);
					dif--;
					if (dif == 0) {
						ans = i+1;
						break;
					}
				}
			}
		}
		printf("Case #%d: %lld\n", cn++, ans);
	}
	return 0;
}

