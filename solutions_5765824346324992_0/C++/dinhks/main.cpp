#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;
#define ll long long
ll a[200000];
ll m[200000];
ll n,b;
int isCanCutIn(ll time)
{
    ll result=0;
    int i,j;
    for(i=0;i<b;++i)
    {
        result+=(time+m[i]-1)/m[i];
    }
    if(result>=n)
        return 1;
    return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t,i,j,tt;
    cin>>t;
    for(tt=1;tt<=t;++tt)
    {
        cin>>b>>n;
        for(i=0;i<b;++i)
            cin>>m[i];

        ll be = 0;
        ll en = 100000;
        en *=2000000000;
        ll mi = en;
        while(be<=en)
        {
            ll me=(be+en)/2;
            if(isCanCutIn(me))
            {
                mi=me;
                en=me-1;
            }
            else
                be=me+1;
        }
        //cout<<mi<<endl;
        ll numWait=0;
        ll numFree=0;
        for(i=0;i<b;++i)
        {
            numWait+=(mi+m[i]-2)/m[i];
        }

        numWait=n-numWait;
       // cout<<numWait<<endl;
        for(i=0;i<b;++i)
        {
            if((mi-1)%m[i]==0)
                numWait--;
            if(numWait==0)
            {
                cout<<"Case #"<<tt<<": "<<i+1<<endl;
                break;
            }
        }

    }
    return 0;
}
