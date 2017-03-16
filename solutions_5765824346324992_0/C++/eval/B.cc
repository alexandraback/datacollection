
#include <cstdio> 
#include <algorithm> 

#define N 5

using namespace std; 

typedef long long int ll; 

ll B[N]; 
ll S[N];

int m; 
ll n;

ll gcd(ll a, ll b) { 
	if (b == 0) { 
		return a; 
	}
	return gcd(b, a % b); 
}

ll lcm(ll B[N], int m) {
	ll res = 1L; 
	for (int i = 0; i < m; i++) { 
		res = res * B[i] / gcd(res, B[i]); 
	}
	return res; 
}

int extract_min() {
	ll v = 1000000000L * 26L; 
	int pos = -1;
	for (int i = 0; i < m; i++) { 
		if (S[i] < v) { 
			v = S[i]; 
			pos = i; 
		}
	}
	return pos; 
}
int main() { 
	int T; 
	scanf("%d", &T); 
	for (int t = 1; t <= T; t++) { 
		scanf("%d%lld", &m, &n); 
		for (int i = 0; i < m; i++) { 
			scanf("%lld", B+i); 
			S[i] = 0L; 
		}
		
		ll L = lcm(B, m); 
		ll people = 0L;
		for (int i = 0; i < m; i++) { 
			people += L/B[i]; 
		}
		n = n % people; 
		if (n == 0) { 
			n += people; 
		}

		for (ll i = 1; i <= n; i++) { 
			int pos = extract_min(); 
			S[pos] += B[pos]; 
			if (i == n) {
				printf("Case #%d: %d\n", t, pos + 1); 
			}
		}

	}
	return 0; 
}
