#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

#define LL long long
using namespace std;

int n,m,r,c;
int ans;
int cnt2 , cnt3 , cnt4;
int gao(int n){
    int res = 0;
    while ( n>0 ){
        if ( cnt2>0 ){
            res += 2; cnt2--;
        }
        else if ( cnt3>0 ){
            res += 3; cnt3--;
        }
        else res += 4; cnt4--;
        n--;
    }
    return res;
}

int main(){

    int t; scanf("%d",&t);
    for(int it=1;it<=t;it++){
        scanf("%d%d%d",&r,&c,&n);
        printf("Case #%d: ",it);

        int m1 = r*c/2;
        int m2 = r*c-m1;
        if ( max(m1,m2)>=n ){
            printf("0\n");
            continue;
        }
        if ( r==1||c==1 ){
            if ( m1<m2 ) ans = 2*(n-m2);
            else ans = 1+2*(n-m2-1);
            printf("%d\n",ans  );
            continue;
        }

        ans = 123456789;
        if ( m1<m2 ){
            cnt2 = 4; cnt3 = r+c-2-4; cnt4 = m2-cnt2-cnt3;
            ans = min(ans , gao(n-m1));
            cnt2 = 0; cnt3 = r+c-2; cnt4 = m1-cnt2-cnt3;
            ans = min(ans , gao(n-m2));
        }
        else {
            cnt2 = 2; cnt3 = (r+c)-2-2; cnt4 = m1-cnt2-cnt3;
            ans = min(ans , gao(n-m1));
        }
        printf("%d\n" , ans);
    }

    return 0;
}