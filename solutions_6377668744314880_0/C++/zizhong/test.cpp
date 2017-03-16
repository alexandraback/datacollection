#include <vector>
#include<cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, double> PID;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef pair<PII, int> PIP;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
void solveBsmall(int ncase) {
    // Mk <= 25
    int b, n;
    cin >> b >> n;
    vector<int> barber(b);
    for(int i = 0; i < barber.size(); i ++) {
        cin >> barber[i];
    }
    ll lcm = 1;
    for(auto x : barber) {
        lcm = lcm * x / gcd(lcm, x);
    }
    ll batch = 0;
    for(auto x : barber) {
        batch += lcm / x;
    }
    n %= batch;
    if (n == 0) n = batch;
    vector<int> barberBusy(b, 0);
    int ret = 0;
    while(1) {
        for(int i = 0; i < b; i ++) {
            if (barberBusy[i] == 0) {
                n --;
                barberBusy[i] = barber[i];
                if (n == 0) {
                    ret = i + 1;
                    break;
                }
            }
        }
        for(int i = 0; i < b; i ++) barberBusy[i] --;
        if (ret > 0) break;
    }
    cout << "Case #" << ncase << ": " << ret << endl;
}


struct Point {
    ll x, y, id;
};

bool cmp(const Point &a, const Point &b){
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

bool mult(Point sp, Point ep, Point op){
    return (sp.x-op.x)*(ep.y-op.y) >= (ep.x-op.x)*(sp.y-op.y);
}

void Graham(vector<Point>& p, int n, vector<int>& res, int& top){
    int i, len;
    top = 1;
    sort(p.begin(), p.end(), cmp);
    for(i = 0; i < 3 && i < n; i ++) res[i] =i;
    if (n < 3) return;
    for(i = 2; i < n; i ++){
        while(top && mult(p[i], p[res[top]], p[res[top-1]])) top --;
        res[++ top] = i;
    }
    len = top;
    res[++ top] = n - 2;
    for(i = n - 3; i >= 0; i --){
        while(top != len && mult(p[i], p[res[top]], p[res[top-1]])) top --;
        res[++ top] = i;
    }
}
bool online(Point A, Point B, Point C) {
    ll temp=(B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
    if(temp!=0||(C.x>max(A.x,B.x)||C.x<min(A.x,B.x)||C.y>max(A.y,B.y)||C.y<min(A.y,B.y))) return false;
    return true;
}
void solveCsmall(int ncase) {


    int n;
    cin >> n;
    vector<Point> pvec(n);
    for(int i = 0; i < n; i ++) {
        cin >> pvec[i].x >> pvec[i].y;
        pvec[i].id = i;
    }
    vector<int> ret(n, n);
    for(int k = 0; k < (1 << n); k ++) {
        vector<Point> ps;
        for(int i = 0; i < n; i ++) {
            if (k & (1 << i)) {
                ps.push_back(pvec[i]);
            }
        }
        int cost = n - ps.size();
        vector<int> res(100);
        int top = 0;
        if (ps.size() < 3) {
            for(int i = 0; i < ps.size(); i ++) {
                int pid = ps[i].id;
                ret[pid] = min(ret[pid], cost);
            }
            continue;
        }
        Graham(ps, ps.size(), res, top);
        for(int i = 0; i <= top; i ++) {

            int pid = ps[res[i]].id;
            ret[pid] = min(ret[pid], cost);
        }
        for(int i = 0; i <= top; i ++) {
            for(int j = 0; j < ps.size(); j ++) {
                if (online(ps[res[(i - 1 + top + 1) % (top + 1)]], ps[res[i]], ps[j])) {
                    int pid = ps[j].id;
                    ret[pid] = min(ret[pid], cost);
                }
            }
        }
    }
    cout <<"Case #" << ncase << ":" << endl;
    for(auto x : ret) cout << x << endl;

}
void solve(int ncase) {
    solveCsmall(ncase);
}

int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    //freopen("in.txt", "r", stdin);

    freopen("C-small-attempt0.in", "r", stdin);
    //freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //init();
    int T = 1;
    cin >> T;
    //scanf("%d", &T);
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
