#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long in[1005], b, n;
long long check(long long t){
    int i, j;
    long long ret = 0;
    for(i=0;i<b;i++){
        ret += (t + in[i] - 1)/in[i];
    }
    return ret;
}
int main()
{
    int t, i, j, sum = 0;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&t);
    for(int cnt = 1;cnt <= t;cnt++){
        scanf("%lld %lld",&b,&n);
        for(i=0;i<b;i++){
            scanf("%lld",in+i);
        }
        //printf("%d\n",sum);

        long long ti = 1000000000000000010ll;
        long long l = 0, r = ti, m;
        if(check(0) < n){
            while(l < r - 1){
                m = (l+r)/2;
                //printf("%lld %lld %lld\n",l ,r, check(m));
                if(check(m) >= n)
                    r = m;
                else
                    l = m;
            }
        }
        //printf("%lld %lld\n", l, check(l));

        long long need = n - check(l);
        //printf("%lld\n",need);
        for(i=0;i<b && need > 0;i++)if(l%in[i] == 0)
            need --;
        printf("Case #%d: %d\n",cnt,i);
    }
    return 0;
}
