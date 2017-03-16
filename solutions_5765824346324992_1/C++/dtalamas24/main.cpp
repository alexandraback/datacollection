#include <bits/stdc++.h>

using namespace std;

long long A[100005], casos, ctos, n, x, y, mid, son, res;

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%lld",&casos);
    for(long long v=1; v<=casos; v++){
        scanf("%lld%lld",&ctos,&n);
        for(int i=1; i<=ctos; i++){
            scanf("%lld",&A[i]);
        }
        x=0;
        y=1000000000000000LL;
        while(x<y){
            mid=(x+y+1)/2;
            son=0;
            for(int i=1; i<=ctos; i++){
                son=son+ceil(1.0*mid/A[i]);
            }
            if(son>=n){
                y = mid-1;
            }
            else {
                x = mid;
            }
        }

        mid=x;
        son=0;
        for(int i=1; i<=ctos; i++){
            son=son+ceil(1.0*mid/A[i]);
        }
        for(int i=1; i<=ctos; i++){
            if(mid%A[i]==0){
                ++son;
                if(son==n){
                    res=i;break;
                }

            }
        }
        printf("Case #%lld: %lld\n",v,res);
    }
    return 0;
}
