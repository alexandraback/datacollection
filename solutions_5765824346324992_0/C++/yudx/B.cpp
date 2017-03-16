#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<iostream>

using namespace std;

typedef long long ll;

int n,a[1005],b;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T,I=1,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&b,&n);
        for(i=0;i<b;i++) scanf("%d",a+i);
        int r=0;
        ll aa=0,bb=1000000000000000000LL;
        if(n<=b) r=n;
        else
        {
            while(bb-aa>1)
            {
                ll x=(bb+aa)/2;
                ll nt=0;
                for(i=0;i<b;i++)
                {
                    nt=nt+(x+a[i]-1)/a[i];
                }
                if(nt>=n) bb=x;
                else aa=x;
            }
            ll x=aa,nn=0,nn2=0;
            for(i=0;i<b;i++) nn=nn+(aa+a[i]-1)/a[i];
            nn=n-nn;
            for(i=0;i<b;i++)
            {
                if(x%a[i]==0) --nn;
                if(!nn) {r=i+1;break;}
            }
            //printf("%lld %lld %lld\n",nn,nn2,x);
        }
        printf("Case #%d: %d\n",I++,r);
    }
    return 0;
}
