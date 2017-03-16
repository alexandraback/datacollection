#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<LL, LL> pii;



//convex hull template copied from zju template written by me and my teammates
#define VEC pii
#define x first
#define y second
vector<pii> convex_hull(vector<pii> p) {
    if (p.size() <= 3) return p;
    vector<pii> r;
    REP(i, p.size()) {
        int succ = false;
        REP(j, p.size())
            if (j != i) {
                int good = true;
                REP(k, p.size()) {
                    pii a; a.x = p[k].x - p[i].x; a.y = p[k].y - p[i].y;
                    pii b; b.x = p[j].x - p[i].x; b.y = p[j].y - p[i].y;
                    LL cmp = a.x * b.y- a.y * b.x;
                    if (cmp > 0) {
                        good = false; break;
                    }
                }
                if (good) {
                    succ = true;
                    break;
                }
            }
        if (succ)
            r.pb(p[i]);

    }
    return r;
}


int main(){
    int caseNumber;
    //scanf("%d", &caseNumber);
    cin>>caseNumber;
    REP(caseN, caseNumber) {
        int N;
        cin>>N;
        vector<int> R(N, N);
        vector<VEC> D;
        map<VEC, int> M;
        REP(i, N) {
            VEC d;
            cin>>d.x>>d.y; D.pb(d);
            M[d] = i;
        }

        REP(i, 1<<N) {
            int pop = __builtin_popcount(i);
            vector<VEC> r, r2;
            REP(j, N)
                if (i & (1<<j))
                    r.pb(D[j]);
            if (r.size() > 3)
                r2 = convex_hull(r);
            else 
                r2 = r;
            // cout<<i<<' '<<r2.size()<<endl;
            REP(j, r2.size()) {
                int id = M[r2[j]];
                R[id] = min(R[id], N - pop);
            }

        }
        if (N <= 3) REP(i, N) R[i] = 0;
    	printf("Case #%d:\n", caseN + 1);
        REP(i, N) cout<<R[i]<<endl;
    }
    return 0;
}