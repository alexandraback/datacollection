#include<cstdio>
#include<cmath>
typedef long long LL;
int main()
{
    int t, n;
    double c,f,x;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&t);
    for(int cnt = 1;cnt <= t;cnt++){
        scanf("%lf%lf%lf",&c,&f,&x);
        n = 0;
        double inc = 2.0, prevt = x/inc, t, t0 = 0;
        while(1){
            n++;
            t0 += c/inc;
            inc += f;
            t = t0 + x/inc;
            if(t > prevt)
                break;
            prevt = t;
        }
        printf("Case #%d: %.7lf\n",cnt, prevt);
    }
    return 0;
}
