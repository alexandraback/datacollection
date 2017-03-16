#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1005] ;
int n , ans ;

int main(){
    freopen("input.txt" , "r" , stdin) ;
    freopen("output.txt" , "w" , stdout) ;
    int _, cas = 0 ; scanf("%d", &_);
    while(_--) {
        int ans1 = 0 , ans2 = 0 ;
        scanf("%d",&n) ;
        for (int i = 0 ; i < n ; i++) scanf("%d",a+i) ;
        for (int i = 0 ; i + 1 < n ; i++)
            if (a[i] > a[i + 1])
                ans1 += a[i] - a[i + 1] ;
        int per = 0 ;
        for (int i = 0 ; i + 1 < n ; i++)
            per = max(a[i] - a[i + 1] , per) ;
        for (int i = 0 ; i + 1 < n ; i++)
            ans2 += min(per , a[i]) ;
        printf("Case #%d: %d %d\n",++cas,ans1,ans2) ;

    }
    return 0;
}
