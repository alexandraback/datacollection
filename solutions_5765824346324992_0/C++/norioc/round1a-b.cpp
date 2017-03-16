#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

typedef vector<int> vi;

template <class T>
T gcd(T m, T n) {
    T r = m % n;
    while (r != 0)
        m = n, n = r, r = m % n;
    return n;
}

template <class T>
T lcm(T n, T m) {
    return n / gcd(n, m) * m;
}

struct Barber {
    vi v;
    int work; // free if zero
};

int calcSmallInput(int nth, vi& v) {
    int cm = 1;
    for (int i = 0; i < v.size(); i++) {
        cm = lcm(cm, v[i]);
    }
//    printf("LCM:%d\n", cm);
    assert(cm > 0);

    Barber bs[10];
    const int n = v.size();
    int p = 0;
    for (int i = 0; i < n; i++) {
        bs[i].v.push_back(p++);
        bs[i].work = v[i];
        if (p == nth) {
            // printf("found1 i:%d\n", i);
            return i+1;
        }
    }

    for (int i = 0; i < cm; i++) {
        for (int j = 0; j < n; j++) {
            assert(bs[j].work > 0);
            bs[j].work--;
            if (bs[j].work == 0) {
                bs[j].v.push_back(p++);
                bs[j].work = v[j];
                if (p == nth) {
                    // printf("found i:%d j:%d\n", i, j);
                    return j+1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        assert(bs[i].work == v[i]);
        // 最後の一人を取り除く
        assert(bs[i].v.size() > 1);
        bs[i].v.pop_back();
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += bs[i].v.size();
    }

#if 0
    printf("TOTAL:%d\n", total);    
    for (int i = 0; i < n; i++) {
        printf("i:%d size:%d\n", i, (int)bs[i].v.size());
        for (int j = 0; j < bs[i].v.size(); j++) {
            printf(" %d", bs[i].v[j]);
        }
        printf("\n");
    }
#endif    
    for (int i = 0; i < n; i++) {
        const vi& w = bs[i].v;
        for (int j = 0; j < w.size(); j++) {
            if ((nth-1) % total == w[j]) {
                // printf(">> found\n");
                return i+1;
            }
        }
    }

    return -1;
}

int main() {
    int ncases;
    scanf("%d", &ncases);

    For(cc, ncases) {
        int B, N;
        scanf("%d %d", &B, &N);
        vi v(B);
        For(i, B) scanf("%d", &v[i]);
        printf("Case #%d: %d\n", cc+1, calcSmallInput(N, v));
    }
}

