
#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> P;
typedef vector<int> VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4) { a4 = in(a4, b4); }
int t[2][5][5];
int main(){
    int cas;
    cin >> cas;
    fup(c, 1, cas) {
        int a, b;
        cin >> a;
        fup(i, 1, 4) fup(j, 1, 4) cin >> t[0][i][j];
        cin >> b;
        fup(i, 1, 4) fup(j, 1, 4) cin >> t[1][i][j];
        
        VI odp;
        fup(i, 1, 16) {
            int ok = 0;
            fup(j, 1, 4) if (t[0][a][j] == i) ok++;
            fup(j, 1, 4) if (t[1][b][j] == i) ok++;
            if (ok == 2) odp.PB(i);
        }
        printf("Case #%d: ", c);
        if (siz(odp) == 0) cout << "Volunteer cheated!" << endl;
        else
        if (siz(odp) > 1) cout << "Bad magician!" << endl;
        else cout << odp[0] << endl;
        

    }

	return 0;
}

