#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<int(n); i++)
#define ALL(v) (v).begin(),(v).end()
#define DBG(x) cerr<<__LINE__<<": " #x " = "<<x<<endl
#define endl '\n'
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin>>T;
    REP(_t, T) {
        cout<<"Case #"<<_t+1<<":"<<" ";
        
        int N; cin>>N;
        vector<int> data(N); 
		REP(i,N) cin>>data[i];
		
		int res1=0;
		int maxdif=0;
		REP(i,N-1) {
			res1 += max(0, data[i]-data[i+1]);
			maxdif = max(maxdif, data[i]-data[i+1]);
		}
		
		int res2=0;
		REP(i, N-1) {
			res2 += min(data[i], maxdif);
		}
		
		cout<<res1<<" "<<res2<<endl;
        
    }
}
