#include<iostream>
#include<cstdio>
#include<cmath>

const int N=17;
using namespace std;

int num, t, n, i, a[N], x, j, k, ans;

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    cin>>t;
    while(t--)
    {
        k=0;
        num++;
        cin>>n;
        for(i=1; i<=16; i++)
            a[i]=0;
        for(i=1; i<5; i++)
            for(j=1; j<5; j++)
            {
                cin>>x;
                if(i==n)a[x]++;
            }
        cin>>n;
        for(i=1; i<5; i++)
            for(j=1; j<5; j++)
            {
                cin>>x;
                if(i==n)a[x]++;
            }
        for(i=1; i<=16; i++)
            if(a[i]==2)
            {
                k++;
                ans=i;
            }
        cout<<"Case #"<<num<<":"<<" ";
        if(k==1)cout<<ans<<endl; else
        if(k==0)cout<<"Volunteer cheated!"<<endl; else cout<<"Bad magician!"<<endl;
    }
}
