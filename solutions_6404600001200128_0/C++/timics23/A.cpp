#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int T,N,m[10100];

int main() {
    freopen("input.in","r",stdin);
    freopen("outputA","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        printf("Case #%d: ",t);
        scanf("%d",&N);
        int rate = 0, x = 0;
        for(int i=1;i<=N;++i) {
            scanf("%d",&m[i]);
            if(m[i-1] > m[i]) {
                x += (m[i-1] - m[i]);
                rate = max(rate,m[i-1]-m[i]);
            }
        }
        int curr = m[1], y = 0;
        for(int i=2;i<=N;++i) { 
            y += min(curr, rate);
            curr = m[i];
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}
