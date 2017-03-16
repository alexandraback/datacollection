//
//  main.cpp
//  dasd
//
//  Created by 刘鑫伟 on 15/3/28.
//  Copyright (c) 2015年 刘鑫伟. All rights reserved.
//
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>

using namespace std;
long long a[1010];
long long b[10];
long long gcd(long long p,long long q)
{
    if(q==0)  return p;
    else return gcd(q,p%q);
}
int main()
{
    int t;
    int cs=1;
    scanf("%d",&t);
    while(t--)
    {
        memset(b,0,sizeof(b));
        long long m,p,n;
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        if(m<=n) p=m;
        else
        {
            long long tmp=a[1];
            for(int i=2;i<=n;i++)
            {
                long long tt=gcd(tmp,a[i]);
                tmp=(tmp*a[i])/tt;
            }
            long long sum=0;
            for(int i=1;i<=n;i++)
                sum+=(tmp/a[i]);
            while(m>=sum)
                m-=sum;
            if(m==0) m=sum;
            for(int i=1;i<=m;i++)
            {
                long long mi=1,mmi=b[1];
                for(int j=2;j<=n;j++)
                {
                    if(mmi>b[j])
                    {
                        mmi=b[j];
                        mi=j;
                    }
                }
                b[mi]+=a[mi];
                if(i==m)
                {
                    p=mi;
                    break;
                }
            }
        }
        printf("Case #%d: %lld\n",cs++,p);
    }
    return 0;
}