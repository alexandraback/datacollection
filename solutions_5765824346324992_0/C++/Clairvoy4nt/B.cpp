#include <cstring>
#include <map>
#include <numeric>
#include <sstream>
#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cctype>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb(x) push_back((x))
#define REP(i,x,y) for(int i = x; i < int(y); i++)
#define FOR(it,A) for(typeof (A.begin()) it = A.begin(); it!= A.end(); it++)
#define CUA(x) (x) * (x)
#define mp(x,y) make_pair((x),(y))
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
#define I (1LL << 40)
#define sz size()
#define oo (1<<30)
#define EPS (1e-9)

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<pii> vii;
typedef vector<string> vs;
typedef vector<int> vi;

ll MCM(ll a, ll b){
	return (a/__gcd(a,b)) * b;
}

void solve(int caso){
	int B,N;
	cin >> B >> N;

	vi bb(5);
	vi aa(5);
	int mn = 100000;
	int nmn = mn;
	ll mcm = 1;
	REP(i,0,B){
		cin>>bb[i];
		mn = min(bb[i],mn);
		mcm = MCM(mcm, bb[i]);
	}
	if(N<=B){
			printf("Case #%d: %d\n",caso, N);
			return;
		}
	aa = bb;
	int barber=100;
	int entran = 0;
	int T = 0;
	while(T < mcm){
		T+=mn;
		REP(i,0,B){
			aa[i]-=mn;
			if(aa[i]==0){
				aa[i] = bb[i];
				entran++;
			}
			nmn = min(nmn,aa[i]);
		}
		mn = nmn;
		nmn = oo;
	}
	//REP(i,0,B) cout<<aa[i]<<" ";
	//cout<<endl;
	//cout << T<< endl;
	//cout<<entran<<endl;
	if(N > entran){
		if (N%entran==0) N = entran;
		else N = N - N/entran * entran;
	}
	//cout << "nuevo N: "<<N<<endl;
	if(N<=B){
		printf("Case #%d: %d\n",caso, N);
		return;
	}
	N-=B;
	mn=oo;
	REP(i,0,B) mn = min(bb[i],mn);
	T = 0;
	while(T < mcm){
		T+=mn;
		REP(i,0,B){
			aa[i]-=mn;
			if(aa[i]==0){
				aa[i] = bb[i];
				N--;
				if(N==0){
					barber = i+1;
					break;
				}
			}
			nmn = min(nmn,aa[i]);
		}
		mn = nmn;
		nmn = oo;
	}
	printf("Case #%d: %d\n",caso, barber);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	int T;
	cin >> T;

	REP(i,1,T+1){
		solve(i);
	}

	
		
	return 0;
}






