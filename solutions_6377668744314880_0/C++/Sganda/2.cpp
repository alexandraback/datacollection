#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define LL long long
#define sd(x) scanf("%d", &x)
#define sld(x) scanf("%lld", &x)
#define MOD 1000000007
#define SQ 112345
#define N 1123456
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, A, B) for (int I = A; I <= B; ++I)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define PII pair<int,int>

// Reference from http://stanford.edu/~liszt90/acm/notebook.html#file8

#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define REMOVE_REDUNDANT 0

typedef double T;
const T EPS = 1e-7;
struct PT {
  T x, y;
  PT() {}
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

#ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

#ifdef REMOVE_REDUNDANT
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
#endif
}
vector<PT> v, h;
PT a[100];
int ans[100];

int get(PT p1, PT p2, PT p3){
    if((p1.y - p3.y) * (p2.x - p3.x) == (p2.y - p3.y) * (p1.x - p3.x))
        return 1;
    return 0;
}

int solve(){
    v.clear();
    int n, i, x, y, j, k;
    /*n = 4;
    {
        PT p(0, 0);
        v.PB(p);
    }
    {PT p(10, 0);
    v.PB(p);}
    {PT p(0, 10);
    v.PB(p);}
    {PT p(5, 5);
    v.PB(p);}
    ConvexHull(v);
    cout<<v.size()<<endl;
    return 0;*/
    cin>>n;
    for(i = 1; i <= n; i++){
        cin>>x>>y;
        PT p(x, y);
        v.PB(p);
        a[i] = p;
        ans[i] = n - 1;
    }
    for(i = 0; i < (1<<n); i++){
        h.clear();
        int cn = 0;
        for(j = 0; j < n; j++){
            if((1<<j) & i){
                h.PB(a[j + 1]);
                cn++;
            }
        }
        ConvexHull(h);
        for(k = 0; k < h.size(); k++){
            PT p = h[k];
        }
        for(k = 0; k < h.size(); k++){
            PT p = h[k];
            for(j = 1; j <= n; j++){
                if(p == a[j] && (i & (1<<(j - 1) ))){
                    ans[j] = min(ans[j], n - cn);
                }
            }

            for(j = 1; j <= n; j++){
                if(k != (h.size() - 1)){
                    if(get(h[k], h[k + 1], a[j])  && (i & (1<<(j - 1) ))){
                        ans[j] = min(ans[j], n - cn);
                    }
                }
                else{
                    if(get(h[k], h[0], a[j]) && (i & (1<<( j - 1) ))){
                        ans[j] = min(ans[j], n - cn);

                    }
                }
            }
        }
    }
    REP(i, 1, n){
        cout<<ans[i]<<endl;
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1, o = 1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<o++<<":"<<endl;
        solve();
    }
    return 0;
}
