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
int tab[10000];

void licz() {
    scanf("%d", &N);
    int maxdiff = 0;
    int res1 = 0, res2 = 0;
    REP(a, N)
        scanf("%d", tab+a);
    REP(a, N-1) {
        maxdiff = max(maxdiff, tab[a]-tab[a+1]);
        res1 += max(0, tab[a]-tab[a+1]);
    }
    REP(a, N-1)
        res2 += min(tab[a], maxdiff);
    printf("%d %d\n", res1, res2);
}

int main() {
    int TT;
    scanf("%d", &TT);
    REP(tt, TT) {
        printf("Case #%d: ", (tt+1));
        licz();
    }
}


