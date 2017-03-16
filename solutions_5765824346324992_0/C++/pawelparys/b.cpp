#include <string>
#include <cstring>
#include <cassert>
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


int N, ktory;
int tab[1000];

LL ile_wcz(LL czas) {
        LL ile_wcz = 0;
        REP(a, N)
            ile_wcz += (czas+tab[a]-1)/tab[a];
        return ile_wcz;
}

void licz() {
    scanf("%d%d", &N, &ktory);
    REP(a, N)
        scanf("%d", &tab[a]);
    LL l = 0, r = INF*(LL)INF/1000;
    while (l+1<r) {
        LL m = (l+r)/2;
        (ile_wcz(m)<ktory ? l : r) = m;
    }
    int zost = ktory-ile_wcz(l);
    REP(a, N)
        if (l%tab[a]==0 && !--zost) {
            printf("%d\n", a+1);
            return;
        }
    assert(0);
}

int main() {
    int TT;
    scanf("%d", &TT);
    REP(tt, TT) {
        printf("Case #%d: ", (tt+1));
        licz();
    }
}


