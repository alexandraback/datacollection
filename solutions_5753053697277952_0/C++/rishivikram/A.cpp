#include<bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define eps 1e-9
#define sqr(x) ((x)*(x))
#define SET(a,b) memset((a),(b),sizeof((a)))
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define endl "\n"

const int MOD = 1e9+7;

typedef long long ll;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

inline bool EQ(double a,double b) { return fabs(a - b) < 1e-9; }
inline void set_bit(int & n, int b) { n |= pw(b); }
inline void unset_bit(int & n, int b) { n &= ~pw(b); }

inline void check(ll &x) {
	if(x>=MOD)
		x%=MOD;
}

int main() {
//	freopen("TASK.in","r",stdin);	
//	freopen("TASK.out","w",stdout);
	int t;
	cin>>t;
	int cc=0;
	while(t--) {
		++cc;
		int n;
		cin>>n;
		priority_queue< pair<int,char> > pq;
		int rem=0;
		for(int i=1;i<=n;i++) {
			int x;
			scanf("%d",&x);
			pq.push(mp(x,i+65-1));
			rem+=x;
		}
		cout<<"Case #"<<cc<<": ";
		int printed=0;
		while(!pq.empty()) {
			if(sz(pq)==1) {
				cout<<"galat"<<endl;
				if(printed) cout<<" ";
				if(pq.top().ff==1) rem--,cout<<pq.top().ss;
				else rem-=2,cout<<pq.top().ss<<pq.top().ss;
				pq.pop();
			}
			else {
				pair<int,char> z = pq.top();
				pq.pop();
				pair<int,char> zz = pq.top();
				pq.pop();
				if(printed) cout<<" ";
				pair<int,char> zzz;
				zzz.ff=-1;
				if(!pq.empty()) zzz = pq.top();
				if(zzz.ff==-1) {
					if(z.ff==zz.ff) {
						cout<<z.ss<<zz.ss;
						rem-=2;
						z.ff-=1;
						zz.ff-=1;
						if(z.ff!=0) pq.push(z);
						if(zz.ff!=0) pq.push(zz);
					}
					else {
						cout<<"galat"<<endl;
					}
				}
				else {
					if(z.ff>=2) {
						int temp = rem - 2;
						int maxi=max(0,z.ff-2);
						maxi=max(maxi,zz.ff);
						if(maxi>temp/2) {
							z.ff-=1;
							zz.ff-=1;
							cout<<z.ss<<zz.ss;
							pq.push(z);
							rem-=2;
							if(zz.ff!=0) pq.push(zz);
						}
						else {
							cout<<z.ss<<z.ss;
							z.ff-=2;
							rem-=2;
							if(z.ff!=0) pq.push(z);
							pq.push(zz);
						}
					}
					else {
						if(rem==3) {
							rem--;
							cout<<z.ss;
							pq.push(zz);
						}
						else {
							rem-=2;
							cout<<z.ss<<zz.ss;
						}
					}
				}
			}
			printed++;
		}
		cout<<endl;
	}
	return 0;
}