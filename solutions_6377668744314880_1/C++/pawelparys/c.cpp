#include <string>
#include <cstring>
#include <vector>
#include <cmath> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
 
using namespace std;
 
#define REP(a,n) for(int a=0; a<(n); ++a)
#define FOR(a,b,c) for(int a=(b); a<=(c); ++a)
#define FORD(a,b,c) for(int a=(b); a>=(c); --a)
#define INIT(a, v) __typeof(v) a = (v)
#define FOREACH(a, v) for (INIT(a, (v).begin()); a!=(v).end(); ++a)
 
template<class T>
inline int size(const T&t){return t.size();}
 
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long LL;

#define INF 1000000000
#define PB push_back
#define MP make_pair
 
//////////////////////////////////////////


int N;
int x[3000], y[3000];
int sel;

struct Nr {
    int nr;
};

bool operator<(Nr A, Nr B){
    int xa = x[A.nr]-x[sel], ya = y[A.nr]-y[sel];
    int xb = x[B.nr]-x[sel], yb = y[B.nr]-y[sel];
    int pola = xa>0 ? 1 : xa<0 ? 3 : ya>0 ? 0 : 2;
    int polb = xb>0 ? 1 : xb<0 ? 3 : yb>0 ? 0 : 2;
    if (pola<polb) return 1;
    if (pola>polb) return 0;
    LL il = xa*(LL)yb-xb*(LL)ya;
    if (il<0) return 1;
    if (il>0) return 0;
    return xa+ya<xb+yb;
}

Nr lista[3000];

LL il_wek(int a, int b) { // ujemny -> a jest wczesniej niz b
    int xa = x[lista[a].nr]-x[sel], ya = y[lista[a].nr]-y[sel];
    int xb = x[lista[b].nr]-x[sel], yb = y[lista[b].nr]-y[sel];
    LL il = xa*(LL)yb-xb*(LL)ya;
    return il;
}

int pol(int a) {
    int xa = x[lista[a].nr]-x[sel], ya = y[lista[a].nr]-y[sel];
    int pola = xa>0 ? 1 : xa<0 ? 3 : ya>0 ? 0 : 2;
    return pola;
}

int ile_moich(int ja) {
    int ile_tu = 1;
    while (ja+ile_tu<N-1 && pol(ja)==pol(ja+ile_tu) && il_wek(ja, ja+ile_tu)==0)
        ++ile_tu;
    return ile_tu;
}


int licz_dla_sel() {
    if (N<=3)
        return 0;
    int best = INF;
    int xxx = 0;
    REP(a, N)
        if (a!=sel)
            lista[xxx++].nr = a;
    sort(lista, lista+N-1);
    int prz = 0, ile_pp = 0, ile_przec = 0;
    REP(ja, N-1) {
        int ile_tu = ile_moich(ja);
        ile_pp += ile_przec;
        ile_przec = 0;
        if (ja)
            ile_pp -= ile_tu;
        else
            prz = (ja+ile_tu)%(N-1);
        while (il_wek(ja, prz)<0) {
            prz = (prz+1)%(N-1);
            ++ile_pp;
        }
        while (il_wek(ja, prz)==0 && pol(ja)!=pol(prz)) {
            prz = (prz+1)%(N-1);
            ++ile_przec;
        }
        best = min(best, min(ile_pp, N-1-ile_pp-ile_tu-ile_przec));
        if (best==0)
            return 0;
        ja += ile_tu-1; // czyli ostatni z grupy
    }
    return best;
}

void licz() {
    scanf("%d", &N);
    REP(a, N)
        scanf("%d%d", x+a, y+a);
    REP(s, N) {
        sel = s;
        printf("%d\n", licz_dla_sel());
    }
}

int main() {
    int TT;
    scanf("%d", &TT);
    REP(tt, TT) {
        printf("Case #%d:\n", (tt+1));
        licz();
    }
}


