#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

#define N 1005
#define P 1005
#define INF 1LL<<61
#define LL  long long
#define MOD 1000000007
#define MOD_S 10007
#define MID ((l + r)/2)
#define lx (x<<1)
#define rx ((x<<1)|1)

int m[1005];
int b,n;

LL getNum(LL t){
    if(t <0 ) return 0;
    LL tot = 0;
    for(int i=1;i<=b;i++){
        tot += (t/m[i]) + 1;
    }
    return tot;
}

bool can(LL t){
    if(getNum(t) >= n){
        return true;
    }
    return false;
}

int main(){
    //freopen("in.txt","r",stdin);
    int ttt;
    scanf("%d",&ttt);
    
    for(int cas=1;cas<=ttt;cas++){
        scanf("%d %d",&b,&n);
        LL right = 1;
        LL left = 0;
        int mmax = 1;
        for(int i=1;i<=b;i++){
            scanf("%d",&m[i]);
            mmax = max(mmax,m[i]);
        }
        right = (LL)mmax * n;
        LL ans = -1;
        while(left <= right){
            LL mid = (left + right)/2;
            if(can(mid)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        LL tot = getNum(ans-1);
        int tt;
        for(tt=1;tt<=b;tt++){
            if( ans % m[tt] == 0){
                tot++;
            }
            if(tot == n){
                break;
            }
        }
        
        printf("Case #%d: %d\n",cas,tt);
    }
    return 0;
}