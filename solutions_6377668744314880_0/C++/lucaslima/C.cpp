#include <bits/stdc++.h>

using namespace std;

#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rep(a,b) fr(a,0,b)
#define fst first
#define snd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

const int oo = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int,int> pii;

struct PT {
    ll x, y, id;
    PT() {}
    PT(ll x, ll y, int id = -1) : x(x), y(y), id(id) {}
    
    PT operator+(const PT &q) const { return PT(x+q.x, y+q.y); }
    PT operator-(const PT &q) const { return PT(x-q.x, y-q.y); }
    PT operator*(ll t) const { return PT(x*t, y*t); }
    PT operator/(ll t) const { return PT(x/t, y/t); }
    PT operator-() const { return PT(-x, -y); }
    ll operator%(const PT &q) const { return x*q.y - y*q.x; }
    bool operator <(const PT &p)       const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
};

ostream& operator << (ostream& os, const PT p) {
    return os << "(" << p.x << "," << p.y << ")";
}

vector<PT> ConvexHull(vector<PT> P) {
    int n = P.size(), k = 0; vector<PT> H(2*n);
    sort(P.begin(), P.end());
    for (int i = 0; i < n; i++) {
        while (k >= 2 && (H[k-1]-H[k-2])%(P[i]-H[k-2]) < 0) k--;
        H[k++] = P[i];
    }
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && (H[k-1]-H[k-2])%(P[i]-H[k-2]) < 0) k--;
        H[k++] = P[i];
    }
    H.resize(k);
    return H;
}

int main() {
    //ios_base::sync_with_stdio(false);
    
    int T;
    scanf("%d", &T);
    int caso = 1;
    while (T--) {
        int N;
        scanf("%d", &N);
        vector<PT> P(N);
        rep(i,N) P[i].id = i;
        rep(i,N) scanf("%lld %lld", &P[i].x, &P[i].y);
        vector<int> ans(N, oo);
        rep(mask,1<<N) {
            vector<PT> P2;
            rep(j,N) if (mask & (1 << j)) {
                P2.push_back(P[j]);
            }
            vector<PT> H = ConvexHull(P2);
            rep(i,H.size()) {
                //printf("%lld\n", H[i].id);
                ans[H[i].id] = min(ans[H[i].id], N - __builtin_popcount(mask));
            }
        }
        printf("Case #%d:\n", caso++);
        rep(i,N) printf("%d\n", ans[i]);
    }    
    
    return 0;
}
