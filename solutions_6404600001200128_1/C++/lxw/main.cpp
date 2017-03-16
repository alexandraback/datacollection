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
int a[1010];
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
            scanf("%d",&a[i]);
        int sum1=0,sum2=0,ma=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]<a[i-1])
            {
                sum1+=a[i-1]-a[i];
                ma=max(ma,a[i-1]-a[i]);
            }
        }
        for(int i=1;i<=n-1;i++)
        {
            sum2+=min(a[i],ma);
        }
        printf("Case #%d: %d %d\n",cs++,sum1,sum2);
    }
    return 0;
}