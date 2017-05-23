//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

int ar[1000009];
string aa;

int  main()
{
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);

    int i,j,k,N,T,S,ans2,temp,cas=0,ans1,now;
    cin>>T;
    while(T--)
    {
        cas++;

        cin>>N;

        for(i=1;i<=N;i++) cin>>ar[i];

        ans1=0;

        for(i=2;i<=N;i++)
        {
            if(ar[i]<ar[i-1]) ans1+=ar[i-1]-ar[i];
        }

        temp=0;
        for(i=2;i<=N;i++) if(ar[i]<ar[i-1]) temp=max(temp,ar[i-1]-ar[i]);

        ans2=0;
        now=ar[1];

        for(i=2;i<=N;i++)
        {
            if(now<temp) ans2+=now;
            else ans2+=temp;
            now=ar[i];
        }

        printf("Case #%d: %d %d\n",cas,ans1,ans2);

    }

}
