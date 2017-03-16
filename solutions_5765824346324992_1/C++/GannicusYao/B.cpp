#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1005] , n ;
int k , ans ;

long long check(long long time){
    long long result = 0 ;
    for (int i = 0 ; i < n ; i++){
        long long per = time / a[i] ;
        if (time % a[i] != 0) per++ ;
        result += per ;
    }
    return result ;
}

int main(){
    freopen("input.txt" , "r" , stdin) ;
    freopen("output.txt" , "w" , stdout) ;
    int _, cas = 0 ; scanf("%d", &_);
    while(_--) {
        scanf("%d%d",&n,&k) ;
        for (int i = 0 ; i < n ; i++) scanf("%d" , a+i) ;
        long long l = 0 , r = 1e16 , mytime;
        while (l <= r){
            long long mid = l + r >> 1 ;
            if (check(mid) < k){
                mytime = mid ;
                l = mid + 1 ;
            }else
                r = mid - 1 ;
        }
        long long need_to_assign = k - check(mytime);
        for (int i = 0 ; i < n ; i++){
            if (mytime % a[i] != 0) continue ;
            if (need_to_assign == 1){
                ans = i + 1 ;
                break ;
            }else need_to_assign-- ;
        }
        printf("Case #%d: %d\n",++cas,ans) ;
    }
    return 0;
}

