#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

typedef vector<int> vi;

int calc1(vi& v) {
    int eat = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i-1] > v[i]) {
            eat += v[i-1] - v[i];
        }
    }
    return eat;
}

int calc2(vi& v) {
    int n = v.size();
    int d = 0;
    for (int i = 1; i < v.size(); i++) {
        d = max(d, v[i-1] - v[i]);
    }

    int eat = 0;
    for (int i = 0; i < v.size()-1; i++) {
        eat += min(d, v[i]);
    }
    return eat;
}

int main() {
    int ncases;
    scanf("%d", &ncases);
    For(cc, ncases) {
        int n;
        scanf("%d", &n);
        vi v(n);
        For(i, n) scanf("%d", &v[i]);

        printf("Case #%d: %d %d\n", cc+1, calc1(v), calc2(v));
    }
}
