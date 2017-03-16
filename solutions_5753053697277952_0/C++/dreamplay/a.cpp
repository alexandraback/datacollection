#include<bits/stdc++.h>
using namespace std;

//#pragma comment (linker, "/STACK:256000000")

typedef long long ll ;

#define endl '\n'
#define  MP make_pair
#define PB push_back
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define fileio freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
#define boost  ios_base::sync_with_stdio(false);
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
int mod = 1e9 + 7 ;
ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}
/*---------------------------------------------------------------------------------------------------------------------*/




int main(){
	fileio;
	int i, j, t, n;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		cin >> n;
		set< pair<int, char> > x;
		set< pair<int, char> > :: iterator it1, it2 ;
		for(i = 0; i < n; i++) {
			cin >> j;
			x.insert(MP(-j, 'A' + i));
		}
		while(x.empty() == false) {
			if(x.size() == 2) {
				it2 = it1 = x.begin();
				it2++;
				if(it1->F != it2->F) {
					cout << it1->S << " ";
					if(it1->F != -1)
						x.insert(MP(it1->F + 1, it1->S));
					x.erase(it1);
				}
				else {
					cout << it2->S << it1->S << " ";
					if(it2->F != -1)
						x.insert(MP(it2->F + 1, it2->S));
					x.erase(it2);
					if(it1->F != -1)
						x.insert(MP(it1->F + 1, it1->S));
					x.erase(it1);
				}
			}
			else {
					it2 = it1 = x.begin();
					it2++;
					cout << it1->S << " ";
					if(it1->F != -1)
						x.insert(MP(it1->F + 1, it1->S));
					x.erase(it1);
			}
		}
		cout << endl;
	}



	return 0 ;
}



