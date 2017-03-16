#include <cstdio>
#include <algorithm>
#define max_ti 1000000000000000
using namespace std;

int m[1010];
int ans_pos;
long long sol(long long ti, int b, int n, long long want_pos) {
    if(ti < 0) return 0;
    long long result = 0;
    long long ans_wait = max_ti;
    int temp_ans_pos=0;
    int cnt = 0;

    for(int i=0 ; i<b ; i++) {
        result += ti/m[i] + 1;
//        if(want_pos > 0) printf("%d %lld\n", m[i], ti);
        if(m[i] <= ti || ti == 0) {
            long long temp = ti%m[i];
            if(ti==0) temp = 0;

            if(temp == 0) {
                cnt++;
            }
            if(ans_wait != 0 && temp == 0 && cnt == want_pos) {
                temp_ans_pos = i;
                ans_wait = 0;
            }
//            else if(ans_wait != 0 && temp > ans_wait) { // near finish
//                ans_pos = i;
//                ans_wait = temp;
//            }
        }

    }
    if(result >= n) ans_pos = temp_ans_pos;
    return result;
}

long long bs(long long left, long long right, int b, long long n) {
    long long l = left, r = right;
    while( l<=r ) {
        long long mid = (l+r)/2;
        long long sol1 = sol(mid, b, n, 1);
        long long sol2 = sol(mid-1, b, n, 1);
        if(sol1 >= n && sol2 < n) {
            if(sol1 - sol2 > 1) {
                long long sol3 = sol(mid, b, n, n - sol2);
            }
            return mid;
        }
        else if(sol1 >= n) {
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
}

int main() {
    int tt;
    scanf("%d", &tt);
    for(int t=0 ; t<tt ; t++) {
        int b, n;
        scanf("%d%d", &b, &n);
        for(int i=0 ; i<b ; i++) {
            scanf("%d", &m[i]);
        }
        ans_pos = -1;
        long long ti = bs(0, max_ti, b, n);
//        printf("ti: %lld\n", ti);
        printf("Case #%d: %d\n", t+1, ans_pos+1);
    }
}
