#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define debug(x) (cerr << #x << " = " << (x) << endl)
template<class I> void debug2(I b, I e) { while (b != e) cerr << *b++ << " "; cerr << endl; }

typedef long long int ll;
typedef unsigned long long int ull;

#define MAX 1000000
#define shift(i,j) (1 << ((i)*c+(j)))

int calc(int r, int c, int mask) {
    int res = 0;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int m = shift(i, j);
            if (mask & m) {
                if (i > 0 && (mask & shift(i-1,j)))
                    res++;
                if (j > 0 && (mask & shift(i,j-1)))
                    res++;
            }
        }
    }
    
    return res;
}

int solve() {
    int res = 2000000000;
    int r,c,n;
    cin >> r>>c>>n;
    int rc = r * c; // <= 16
    for (int mask = 0; mask < (1 << rc); mask++) {
        if (__builtin_popcount(mask) != n)
            continue;
        int t = calc(r, c, mask);
        res = min(res, t);
    }
    return res;
}

int main(){
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        printf("Case #%d: ", test);
        cout << solve() << endl;
    }
    
    return 0;
}
