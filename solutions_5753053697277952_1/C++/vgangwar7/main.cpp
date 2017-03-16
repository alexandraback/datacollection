//
//  main.cpp
//  1C
//
//  Created by VIVEK GANGWAR on 08/05/16.
//  Copyright © 2016 VIVEK GANGWAR. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <bitset>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <assert.h>
#include <deque>
#include <ctime>

#define ALL(i,n)    for(i = 0; i < (n); i++)
#define FOR(i,a,b)  for(i = (a); i < (b); i++)
#define SET(p)      memset(p,-1,sizeof(p))
#define CLR(p)      memset(p,0,sizeof(p))
#define S(n)	    scanf("%d",&n)
#define P(n)	    printf("%d\n",n)
#define Sl(n)	    scanf("%lld",&n)
#define Pl(n)	    printf("%lld\n",n)
#define Sf(n)       scanf("%lf",&n)
#define Ss(n)       scanf("%s",n)
#define LL long long
#define ULL unsigned long long
#define pb push_back
#define pi pair <int ,char>
using namespace std;
int p[1001];
int main()
{
    int t,p1=1;
    cin>>t;
    while(t--)
    {
        int n;
        priority_queue < pair <int ,char> > q1;
        cin>>n;
        char ch='A';
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
            char ch1=ch+i;
            q1.push({p[i],ch1});
        }
        bool flag =false;
        cout<<"Case #"<<p1<<": ";
        while(!q1.empty())
        {
            pair <int ,char> p1 =q1.top();
            if(p1.first==1&&q1.size()==3)
            {
                q1.pop();
                cout<<p1.second<<" ";
                continue;
            }
            q1.pop();
            pair <int ,char> p2;
            if(!q1.empty())
            {
                p2 =q1.top();
                q1.pop();
                flag =true;
            }
            cout<<p1.second<<p2.second<<" ";
            if(flag)
            {
                p1.first-=1;
                p2.first-=1;
                if(p1.first>0)
                    q1.push(p1);
                if(p2.first>0)
                    q1.push(p2);
            }
            else 
            {
                p1.first-=2;
                if(p1.first>0)
                    q1.push(p1);
            }
        }
        p1++;
        cout<<"\n";
        
    }
}