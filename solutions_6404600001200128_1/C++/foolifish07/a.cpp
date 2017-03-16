#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>

#define LL long long 
using namespace std;
const int maxn = 1005;

int n;
int a[maxn];

int main(){

    int t; scanf("%d",&t);
    for(int it=1;it<=t;it++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);

        int ans1 = 0;
        for(int i=2;i<=n;i++){
            if ( a[i]<a[i-1] ) ans1 += a[i-1]-a[i]; 
        }

        int ans2 = 0 , r = 0;
        for(int i=2;i<=n;i++)
            r = max( r , a[i-1]-a[i] );
        for(int i=2;i<=n;i++){
            ans2 += min(r,a[i-1]);
            //else ans2 += r;
        }
        printf("Case #%d: %d %d\n" ,it, ans1 , ans2);        
    }

    return 0;
}