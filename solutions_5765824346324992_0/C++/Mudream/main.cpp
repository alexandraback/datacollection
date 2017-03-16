#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long int int64;

int64 Btime[1000];int Bcnt;

int64 get_before_m(int64 r){
    int64 ret = 0;
    for(int lx = 0;lx < Bcnt;lx++)
        ret += (r+Btime[lx]-1)/Btime[lx];
    return ret;
}

int main(){
    int T; scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int64 n; scanf("%d %lld", &Bcnt, &n);
        for(int lx = 0;lx < Bcnt;lx++)
            scanf("%lld", Btime + lx);
        int64 a = 0, b = 1000000000000000L;
        while(a < b-1){
            int64 test = (a+b+1)/2;
            if(get_before_m(test) >= n)
                b = test;
            else
                a = test;
        }
        n -= get_before_m(a);
        int rr = 0;
        int ans = 0;
        for(int lx = 0;lx < Bcnt;lx++){
            rr += a%Btime[lx] == 0;
            if(rr == n){
                ans = lx+1;
                break;
            }
        }
        printf("Case #%d: %d\n", lt, ans);
    }
    return 0;
}
