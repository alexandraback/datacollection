//
//  main.cpp
//  General
//
//  Created by Shakib Ahmed on 4/27/15.
//  Copyright (c) 2015 Shakib Ahmed. All rights reserved.
//

//Bismillahir Rahmanir Rahmeem

#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<stdlib.h>
#include<string>
#include<set>
#include<iomanip>
#define INF 1e9
#define lld long long int
#define CLR(a) memset(a,0,sizeof(a))
#define RESET(a) memset(a,-1,sizeof(a))
#define act(a) memset(a,1,sizeof(a))
#define setinf(a) memset(a,0b01111111,sizeof(a));
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("output.txt","w",stdout);
#define ui unsigned int
#define came "came"
#define pii pair<int,int>
#define plii pair<long long int, int>
#define pll pair<long long,long long>
#define pic pair<int,char>
#define ninf (-1e9)-2
#define inf (1e9)+2
#include<fstream>
#include <assert.h>
#include <bitset>

#define foreach(x) for(__typeof(x.begin()) it=x.begin(); it!=x.end();it++)

using namespace std;
#define pid pair<int,double>
#define pdi pair<double,int>

#define PB push_back
#define MP make_pair
#define pri(x) printf("%d\n",x)
#define pi 3.14159265359
#define F first
#define S second
#define vit vector<int>::iterator

//Problem A. Counter Culture

int r,c;
int n;

int memo[16][17][1<<16];

int cal(int indx, int place, int mask)
{
    if(place==0)
    {
        return 0;
    }
    else if(indx==r || place<0)
    {
        return 1e9;
    }
    else
    {
        int cnt=1<<c;
        int i,j;
        int nmask,cost;
        int &ret=memo[indx][place][mask];
        if(ret!=-1)
        {
            return ret;
        }
        ret=1e9;
        for(i=0;i<cnt;i++)
        {
            nmask=0;
            cost=0;
            bool f=false;
            for(j=0;j<c;j++)
            {
                if(i & 1<<j)
                {
                    if(mask & 1<<j)
                    {
                        cost+=1;
                    }
                    if(f==true)
                    {
                        cost+=1;
                    }
                    nmask|=1<<j;
                    f=true;
                    
                }
                else
                {
                    f=false;
                }
            }
            int v=cost+cal(indx+1,place-(int)__builtin_popcount(i),nmask);
            ret=min(ret,v);
        }
        return ret;
    }
}

int main(int argc, const char * argv[])
{
    FRO
    FROut
    
    int t;
    scanf("%d",&t);
    
    int ca;
    
    for(ca=1;ca<=t;ca++)
    {
        RESET(memo);
        scanf("%d %d %d",&r,&c,&n);
        if(r<c)
        {
            swap(r,c);
        }
        int res=cal(0,n,0);
        printf("Case #%d: %d\n",ca,res);
    }
    
    return 0;
}




