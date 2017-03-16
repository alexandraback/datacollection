#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define inf 1000000000
#define maxn 1000000

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define sin scanint
#define bitcount(x) __builtin_popcount(x)
#define fill(s, p) memset(s, p, sizeof(s));
#define gc getchar

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

ll modpow(ll a, ll b)
{
	ll x=1ll, y=a;
	while(b){
		if(b%2)
			x=(x*y)%MOD;
		y=(y*y)%MOD;
		b/=2;
	}
	return x;
}

ll gcd(ll a, ll b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b, a%b);
}

int mat[20][20], occ[20][20];
pii bit[20];
vector< pii > v;

int main()
{
	#ifndef ONLINE_JUDJE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t, r, c, n, a, b, d, x, y, m, ans, i, j, k, diffx, diffy, cnt, cnum=1;
	sin(t);
	while(t--){
		sin(r);
		sin(c);
		sin(n);
		ans = inf;
		k=0;
		for(i=0; i<r; i++){
			for(j=0; j<c; j++){
				mat[i][j] = k;
				bit[k] = make_pair(i, j);
				k++; 
			}
		}
		m = r*c;
		for(i=0; i<(1<<m); i++){
			if(bitcount(i)!=n)
				continue;
			//fill(occ, 0);
			v.clear();
			for(j=0; j<m; j++){
				if(i&(1<<j)){
					//occ[bit[j].first][bit[j].second] = 1;
					v.pb(bit[j]);
				}
			}
			//for(j=0; j<v.size(); j++)
			//	cout << v[j].first << " " << v[j].second << endl;
			cnt = 0;
			for(j=0; j<v.size(); j++){
				for(k=j+1; k<v.size(); k++){
					diffx = abs(v[j].first-v[k].first);
					diffy = abs(v[j].second-v[k].second);
					if((diffx==0 && diffy==1) || (diffx==1 && diffy==0))
						cnt++;
				}
				//cout << cnt << endl;
			}
			ans = min(ans, cnt);
		}
		printf("Case #%d: %d\n", cnum++, ans);
	}
	return 0;
}