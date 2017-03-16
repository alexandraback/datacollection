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
struct data
{
    long long x,y;
}a[20];
long long cross(int p1,int p2,int p3)
{
    return (a[p2].x-a[p1].x)*(a[p3].y-a[p1].y)-(a[p2].y-a[p1].y)*(a[p3].x-a[p1].x);
}
int b[20][2];
int main()
{
    int t;
    int cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld",&a[i].x,&a[i].y);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j!=i)
                {
                    int ll=0,r=0;
                    for(int l=1;l<=n;l++)
                    {
                        if(l!=i&&l!=j)
                        {
                            long long tmp=cross(i,j,l);
                            if(tmp>0) ll++;
                            else if(tmp<0) r++;
                        }
                    }
                    if((i==1&&j==2)||(j==1&&i>1))
                    {
                       b[i][0]=ll;
                       b[i][1]=r;
                    }
                    else
                    {
                        b[i][0]=min(ll,b[i][0]);
                        b[i][1]=min(r,b[i][1]);
                    }
                }
            }
        }
        printf("Case #%d:\n",cs++);
        for(int i=1;i<=n;i++)
        {
            printf("%d\n",min(b[i][0],b[i][1]));
        }
    }
    return 0;
}