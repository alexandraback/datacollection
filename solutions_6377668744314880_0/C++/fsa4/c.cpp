#include <bits/stdc++.h>
#define fr(i, a, b) for(int i = (a), __ = (b); i < __; i++)
#define inf 0x3f3f3f3f
#define st first
#define pb push_back
#define nd second
#define eps 1e-9

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct PT {
	ll x, y;
	PT() {}
	PT(ll x, ll y) : x(x), y(y) {}
	PT operator +(const PT &p) {return PT(x+p.x, y+p.y);}
	PT operator -(const PT &p) {return PT(x-p.x, y-p.y);}
	ll operator *(const PT &p) {return x*p.x + y*p.y;}
	ll operator %(const PT &p) {return x*p.y - p.x*y;}
	bool operator < (const PT &p) const {
		if(x != p.x) return x < p.x;
		return y < p.y;
	}
} arr[3010];

bool comp1(PT a, PT b){
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool comp2(PT a, PT b){
	return a%b > 0 || a%b == 0 && a*a < b*b;
}

vector<PT> hull(vector<PT> p){
	int N = p.size();
	PT o = *min_element(p.begin(), p.end(), comp1);
	fr(i, 0, N) p[i] = p[i] - o;
	sort(p.begin(), p.end(), comp2);
	int w = N-1; while(w && p[w]%p[w-1] == 0) w--;
	reverse(p.begin()+w, p.end());
	
	int m = 0;
	for(int i = 1; i < N; i++){
		while(m && (p[i]-p[m-1])%(p[m]-p[m-1]) > 0) m--;
		p[++m] = p[i];
	}
	p.resize(++m);
	fr(i, 0, m) p[i] = p[i] + o;
	return p;
}

int n, qtd[100000], mark[100000];
map<PT, int> mapa;

int main(){
	int t, caso = 1;
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		ll a, b;
		mapa.clear();
		
		fr(i, 0, n){
			scanf("%lld %lld", &a, &b);
			arr[i] = PT(a, b);
			mapa[arr[i]] = i;
		}
				
		fr(i, 1, 1<<n){
			vector<PT> p;
			qtd[i] = 0;
			fr(j, 0, n){
				if(i & (1<<j)){
					qtd[i]++;
					p.pb(arr[j]);
				}
			}
			
			p = hull(p);
			
			mark[i] = 0;
			fr(j, 0, p.size()){
				mark[i] |= (1 << (mapa[p[j]]));
			}
		}
		
		printf("Case #%d:\n", caso++);
		fr(j, 0, n){
			int ans = 0;
			fr(i, 0, 1<<n){
				if(mark[i] & (1<<j)){
					ans = max(ans, qtd[i]);
				}
			}
			
			printf("%d\n", n-ans);
		}
	}

	return 0;
}

