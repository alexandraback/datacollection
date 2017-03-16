//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//const int N = 1e3 + 5;
//
//int a[N], B, n;
//
//long long cnt(long long t) {
//    long long res = B;
//    for(int i = 0; i < B; i++) {
//        //printf("#%lld\n", res);
//        res += t / a[i];
//    }
//    return res;
//}
//
//int get_id(long long t) {
//    long long cur = t == 0 ? 0 : cnt(t - 1);
//    for(int i = 0; i < B; ++i) {
//        if(t % a[i] == 0) {
//            if(++cur == n) {
//                return i + 1;
//            }
//        }
//    }
//    return -1;
//}
//
//int main() {
//    freopen("B-large.in", "r", stdin);
//    freopen("out.ads", "w", stdout);
//    int T, ncase = 0;
//    scanf("%d", &T);
//    while(T--) {
//        scanf("%d%d", &B, &n);
//        for(int i = 0; i < B; ++i) {
//            scanf("%d", &a[i]);
//        }
//        long long l = 0, r = 1LL << 52;
//        //long long l = 0, r = 62;
//        while(l < r) {
//            long long mid = (l + r) / 2;
//            //printf("%lld\n", cnt(mid));
//            if(cnt(mid) < n) {
//                l = mid + 1;
//            }
//            else {
//                r = mid;
//            }
//        }
//        //printf("t ==> ##%lld\n", r);
//        printf("Case #%d: %d\n", ++ncase, get_id(r));
//    }
//    return 0;
//}


#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 1e3 + 5;

int n, a[N];

int f1() {
    int res = 0;
    for(int i = 1; i < n; ++i) {
        if(a[i] < a[i - 1]) {
            res += a[i - 1] - a[i];
        }
    }
    return res;
}

int f2() {
    int speed = 0;
    for(int i = 1; i < n; ++i) {
        if(a[i] < a[i - 1]) {
            speed = max(speed, a[i - 1] - a[i]);
        }
    }
    //printf("#%d\n", speed);
    int res = 0;
    for(int i = 1; i < n; ++i) {
        int cur = a[i - 1] - speed;
        if(cur <= 0) {
            res += a[i - 1];
        }
        else {
            res += speed;
        }
    }
    return res;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.ads", "w", stdout);
    int T, ncase = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        printf("Case #%d: %d %d\n", ++ncase, f1(), f2());
    }
    return 0;
}
