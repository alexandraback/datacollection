#include<iostream>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<sstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<numeric>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;

const int INF = 0X3F3F3F3F;
const double PI = acos(-1.0); //3.1415926535897932384626433832795;
const double EPS = 1e-11;
const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1}; //4 direction

#define FOR(i,s,e) for(int i=(s);i<=(int)(e);++i)
#define FORD(i,s,e) for(int i=(s);i>=(int)(e);--i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REPD(i,n) for(int i=(n)-1;i>=0;--i)
#define CLR(x) memset((x),0,sizeof(x));
#define MEM(a,b) memset((a),b,sizeof(a));
#define PRV(v) REP(vi,v.size()) cout << v[vi] << ' ';cout << endl

inline int sgn(double x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }
//inline string tolower(string s){ REP(i,s.SZ) s[i] = tolower(s[i]); return s; }
//inline string toupper(string s){ REP(i,s.SZ) s[i] = toupper(s[i]); return s; }

template<class T> inline T sqr(const T& x) { return x * x; }
template<class T> inline int toint(const T& x){ stringstream ss; ss << x; int r; ss >> r; return r; } 
template<class T> inline int todouble(const T& x){ stringstream ss; ss << x; double r; ss >> r; return r; } 
template<class T> inline string tostr(const T& x) { ostringstream os(""); os << x; return os.str(); }
template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}//NOTES:stov(
template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}

typedef long long LL;
typedef double DB;
typedef stringstream SS;
typedef set< int > SI;
typedef pair< int, int > PII;
typedef vector< int > VI;
typedef vector< VI > VVI;
typedef vector< string > VS;
typedef map< string, int > MSI;
typedef map< int, int > MII;

const int MAXN = 110;
int dp[MAXN][MAXN];
int n, len;
bool flag;
string s[MAXN];

int main() {
    freopen("A-small-attempt1.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    freopen("A-small.out", "w", stdout);
    int cas;
    cin>>cas;
    //cout<<cas<<endl;
    //scanf("%d", &cas);
    //getchar();
    //string s;
    REP(T, cas) {
        cin>>n;
        int ans = 0;
        flag = true;
        REP(i,n) {
            cin>>s[i];
            //cout<<s[i]<<endl;
            //len = max(len, s[i].length());
        }
        if (n == 2) {
            int i = s[0].length(), j = s[1].length();
            while(i > 0 && j > 0) {
                if (s[0][i-1] != s[1][j-1]) {flag = false; break;}   
                char now = s[0][i-1];
                while(i > 0 && j > 0 && s[0][i-1] == now && s[1][j-1] == now) --i, --j;
                while(s[0][i-1] == now && i > 0) ++ans, --i;
                while(s[1][j-1] == now && j > 0) ++ans, --j;
            }       
            if (i + j > 0) flag = false;     
        }
        else {
            
        }
        if (flag)
            printf("Case #%d: %d\n", T+1, ans);   
        else
            printf("Case #%d: Fegla Won\n", T+1);
    }
    return 0;
}
