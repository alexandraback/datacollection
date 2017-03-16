#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define For(i, n) for (int i = 0; i < (int) n; ++i)
#define SIZE(x) ((int) (x).size())
#define mp(a, b) make_pair(a, b)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#ifndef DG
#define DG 0
#endif
#define LOG(...) (DG ? fprintf(stderr, __VA_ARGS__) : 0)
int r, c, n;

void addremain(vector <vector <bool> >& empty, int num) {
    if (num <= 0) return;
    for (int j = 1; j < c - 1; j++) {
        if (!empty [1] [j]) {
            empty [0] [j] = true;
            num --;
        }
        if (num == 0) return;
        if (!empty [r - 2] [j]) {
            empty [r-1] [j] = true;
            num --;
        }
        if (num == 0) return;
    }

    for (int i = 1; i < r - 1; i++) {
        if (!empty [i] [1]) {
            empty [i] [0] = true;
            num --;
        }
        if (num == 0) return;
        if (!empty [i] [c - 2]) {
            empty [i] [c-1] = true;
            num --;
        }
        if (num == 0) return;
    }
    if (empty [1] [1]) {
        empty [0] [0] = true;
        num --;
    }
    if (num == 0) return;
    if (empty [r - 2] [1]) {
        empty [r - 1] [0] = true;
        num --;
    }
    if (num == 0) return;
    if (empty [1] [c - 2]) {
        empty [0] [c - 1] = true;
        num --;
    }
    if (num == 0) return;
    if (empty [r - 2] [c - 2]) {
        empty [r - 1] [c - 1] = true;
        num --;
    }
}

int mycount(vector <vector <bool> >& empty) {
    int res = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (empty [i] [j]) {
                res += 4;
                if (i == 0 || i == r-1) res --;
                if (j == 0 || j == c-1) res --;
            }
        }
    }
    return res;
}

int main(){
    int T;
    scanf("%d", &T);
    For(cases, T){
        scanf("%d %d %d", &r, &c, &n);
        if (n <= (r * c + 1)/2) {
            printf("Case #%d: 0\n", cases+1);
            continue;
        }

        int res = 2*r*c - r - c;
        int spaces = r*c - n;
        if (r == 1) {
            if (c % 2 == 1) res -= 3* spaces;
            else {
                if (spaces = c/2) res -= 3*spaces - 1;
                else res -= 3* spaces;
            }
            printf("Case #%d: %d\n", cases+1, res);
            continue;
        }
        if (c == 1) {
            if (r % 2 == 1) res -= 3*spaces;
            else {
                if (spaces == r/2) res -= 3*spaces - 1;
                else res -= 3*spaces;
            }
            printf("Case #%d: %d\n", cases+1, res);
            continue;
        }

        if (spaces <= ((r - 2) * (c - 2) + 1)/ 2) {
            res -= 4*spaces;
            printf("Case #%d: %d\n", cases+1, res);
            continue;
        }

        int magic1 = ((r - 2) * (c - 2) + 1) / 2, magic2 = ((r - 2) * (c - 2)) / 2;

        vector <vector <bool> > empty1(r, vector <bool> (c, false)), empty2 = empty1;
        

        for (int i = 1; i < r-1; i++) {
            for (int j = 1; j < c-1; j++) {
                if (i%2 == j%2) empty1 [i] [j] = true;
                else empty2 [i] [j] = true;
            }
        }

        addremain(empty1, spaces - magic1);
        addremain(empty2, spaces - magic2);
        
        res -= max (mycount(empty1), mycount(empty2));
//        cout << mycount(empty1) << ' ' << mycount(empty2) << endl;
        printf("Case #%d: %d\n", cases+1, res);

    }

}
