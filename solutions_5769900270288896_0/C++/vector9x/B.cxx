#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<int(n); i++)
#define ALL(v) (v).begin(),(v).end()
#define DBG(x) cerr<<__LINE__<<": " #x " = "<<x<<endl
#define endl '\n'
typedef long long ll;
using namespace std;
int R, C, neigh;

bool GET(int mask, int r, int c) {
	if(r>=R || c>=C) return false;
	
	return bool( mask&(1<<(r*C+c)) );
}

int unhappiness(const int mask) {
	int total = 0;
	REP(r,R) REP(c,C) {
		if(!GET(mask, r, c)) continue;
		total += GET(mask, r+1, c) + GET(mask, r,c+1);
	}
	return total;
}

int solve() {
	const int lim = R*C;
	int best = 1000000000;
	REP(mask, 1<<lim) {
		if(__builtin_popcount(mask)==neigh) {
			best = min(best, unhappiness(mask));
		}
	}
	return best;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    
    int T; cin>>T;
    REP(_t, T) {
        cout<<"Case #"<<_t+1<<": ";
        
        cin>>R>>C>>neigh;
        cout<<solve()<<endl;
    }
}
