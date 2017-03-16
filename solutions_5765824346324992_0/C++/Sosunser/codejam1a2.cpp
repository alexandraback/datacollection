#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int t,b,n,m[10010],ans1,ans2,rate;

long long check(long long mid){
    long long num = b;
    for(int i = 0; i < b; i++) num += mid/m[i];
    return num;
}
int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&t);
    for(int k = 1; k <= t; k++){
        scanf("%d%d",&b,&n);
        for(int i = 0; i < b; i++) scanf("%d",&m[i]);
        long long low = 0, high = 100000000000000;
        while(low < high){
            long long mid = (high+low)/2;
            if(check(mid) >= n) high = mid;
            else low = mid+1;
        }
        long long num = check(low)-n;
        for(int i = b-1; i >= 0; i--){
            if(low%m[i] == 0){
                if(num-- == 0){
                    printf("Case #%d: %d\n",k,i+1);
                    break;
                }
            }
        }
    }
}