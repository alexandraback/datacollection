//Done by Ferran Alet

#include<bits/stdc++.h>

#define INF 2147483647
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) cerr << #x << " = " << x << endl
#define Debug(v) cerr << #v << " = "; for(int wow=0;wow<v.size();++wow) cerr<<v[wow]<<' '; cerr<<endl
#define DEBUG(M) cerr << #M <<":"<<endl; for(int iM=0;iM<M.size();++iM) { for(int jM=0;jM<M[iM].size();++jM) cerr<<M[iM][jM]<<' '; cerr<<endl;} cerr<<endl
#define FOR(x,y) for(int x=0;x<y;x++)
#define FORS(x,y) for(int x=0;x<int(y.size());++x)
#define FORU(x,y) for(int x=1;x<=y;x++)
#define RFOR(x,y) for(int x=y-1;x>=0;--x)
#define DRI(x) int x; cin>>x
#define DRII(x,y) int x,y; cin>>x>>y
#define DRIII(x,y,z) int x,y,z; cin>>x>>y>>z
#define PB push_back
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;
typedef vector<PII > VP;
typedef vector<VP> VVP;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("Bzero.out","w",stdout);
    freopen("Bzero.in","r",stdin);
    DRI(casos);
    FORU(cas,casos){
        DRIII(n,m,c);
        int t=n*m;
        int minim=INF;
        VVI v(n,VI(m));
        FOR(S,1<<(n*m)){
            if(__builtin_popcount (S)!=c) continue;
            int cont=0;
            FOR(i,n) FOR(j,m) v[i][j] = ((S>>(i*m+j))&1);
            //DEBUG(v); break;
            FOR(i,n){
                FOR(j,m){
                    if(j<m-1 && v[i][j] && v[i][j+1])++cont;
                    if(i<n-1 && v[i][j] && v[i+1][j]) ++cont;
                }
            }
            minim = min(minim,cont);
        }
        cout<<"Case #"<<cas<<": "<<minim<<endl;
    }
}
