#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define x first
#define y second
#define PB push_back
#define REP(i,n) for (int i = 0; i < int(n); ++i)
#define FORE(i,a,b) for (int i = int(a); i <= int(b); ++i)
#define debug(x) cerr << #x << " = " << x << endl;

typedef long long ll;
typedef long double ld;
typedef pair<char, int> P;
typedef vector<bool> Vb;
typedef vector<Vb> Mb;
typedef vector<char> Vc;
typedef vector<Vc> Mc;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<ll> Vll;
typedef vector<Vll> Mll;
typedef vector<P> Vp;
typedef vector<Vp> Mp;
typedef vector<string> Vs;
typedef vector<Vs> Ms;

typedef queue<int> Q;
typedef priority_queue<int> PQ;

template <class Ta, class Tb> inline Tb cast(Ta a) {stringstream ss; ss << a; Tb b; ss >> b; return b; };

const double EPS = 1e-9;
const int diri[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dirj[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

string uniq(string& s) {
    string ans = "";
    int r = s.size();
    ans+=s[0];
    for (int i=1;i<r;++i) if (s[i] != s[i-1]) ans+=s[i];
    return ans;
}

vector<P> f(string& s) {
    vector<P> ans(0);
    char c = s[0];
    int q = 1;
    for (int i=1;i<int(s.size());++i) {
        if (s[i]!=s[i-1]) {
            ans.push_back(P(c,q));
            q=1;
            c=s[i];
        }
        else q++;
    }
    if (q>0) ans.push_back(P(c,q));
    return ans;
}

const int INF = 100000000;
//a is like aaabbbbccc and b like abc
int cost(string &a, string& b) {
    vector<P> va = f(a);
    vector<P> vb = f(b);
    if (va.size()!=vb.size()) return INF;
    int ans=0;
    REP(i,va.size()) {
        if (va[i].x != vb[i].x) return INF; //different chars compressed
        ans+=abs(va[i].y-vb[i].y);
    }
    return ans;
}

int main() {
    int t; cin >> t;
    for (int cas=1; cas<=t;++cas) {
        cout << "Case #" << cas << ": ";
        int n; cin >> n;
        vector<string> v(n);
        REP(i,n) cin >> v[i];
        string w = uniq(v[0]);
        bool ok=1;
        REP(i,n) if (uniq(v[i])!=w) ok=0;
        if (!ok) cout << "Fegla Won" << endl;
        else {
            vector<vector<P> > w(n);
            REP(i,n) w[i]=f(v[i]);
            //cerr << "F calculated" << endl;
            int r=w[0].size();
            REP(i,n) if (w[i].size()!=r) cerr << "OOPS ERROR " << i << endl;
            int ans = 0;
            REP(i,r) { //for each character block
                //cerr << "testing block i = " << i << " of cas "<< cas <<  endl;
                //find the median
                vector<int> vm(n);
                REP(j,n) vm[j]=w[j][i].y;
                sort(vm.begin(),vm.end()); //can be done linear nth_element, n=100
                int med = vm[n/2]; //I guess this is enough
                int ret=0;
                REP(j,n) ret+=abs(w[j][i].y-med);
                if (n%2==0) {
                    med = vm[n/2-1];
                    int ret2=0;
                    REP(j,n) ret2+=abs(w[j][i].y-med);
                    if (ret2<ret) ret=ret2; //I think its never happening.
                }
                ans+=ret;
            }
            cout << ans << endl;
        }
    }
}
