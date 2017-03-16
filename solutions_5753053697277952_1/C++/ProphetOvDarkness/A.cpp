#include <bits/stdc++.h>

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin(); i!=(n).end(); i++)

#define sz(x) (int) x.size()
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define uu first
#define vv second
#define mem(x, y) memset(x, y, sizeof(x));

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdll(x, y) scanf("%lld %lld", &x, &y)
#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%lld\n", x)
#define pfll(x, y) printf("%lld %lld\n", x, y)
#define pflll(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define eps 1e-9
#define OK printf("ok\n")
#define DB(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pii;

inline int setBit(int N, int pos) { return N=N | (1<<pos); }
inline int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


int n, arr[28], cpy[28];
vector <string> out;

struct data {
    int cnt;
    char x;
    data() {}
    data(int _cnt, char _x) {
        cnt = _cnt;
        x = _x;
    }
    bool operator < (const data &p) const {
        return (cnt < p.cnt);
    }
};

inline bool fuck() {
    int i, tot=0;
    rep(i, n) tot += arr[i];
    rep(i, n) if(arr[i] > tot-arr[i]) {
//        DB(arr[i]);
//        DB(tot);
        return true;
    }
    return false;
}

inline bool check() {
    for(auto x:out) {
        for(auto y:x) {
            arr[ y-'A' ]--;
        }
        if(fuck()) return false;
    }
    return true;
}

void solve() {
    priority_queue <data> q;
    int i;
    rep(i, n) q.push(data(arr[i], i+'A'));
    while(!q.empty()) {
        data u = q.top();
        q.pop();
//        cout << u.x << " " << u.cnt << endl;
        string now;
        now += u.x;
        if(!q.empty() && q.top().cnt == u.cnt) {
            data v = q.top();
            q.pop();
            now += v.x;
            v.cnt--;
            if(v.cnt > 0) q.push(v);
        }
        u.cnt--;
        if(u.cnt > 0) q.push(u);
        out.pb(now);
    }
    int siz = sz(out);
    if(siz >= 2 && sz(out[siz-1])==1) swap(out[siz-1], out[siz-2]);
//    rep(i, n) cpy[i] = arr[i];
//    if(!check()) {
//        pfi(n);
//        rep(i, n) cout << cpy[i] << " "; puts("");
//        for(auto x : out) printf(" %s", x.c_str());
//        puts("");
//        exit(0);
//    }
    for(auto x : out) printf(" %s", x.c_str());
    puts("");
}

int main() {
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int test, kase=1, i;

    sdi(test);
    while(test--) {
        out.clear();
        sdi(n);
        rep(i, n) sdi(arr[i]);
        printf("Case #%d:", kase++);
        solve();
    }

    return 0;
}
