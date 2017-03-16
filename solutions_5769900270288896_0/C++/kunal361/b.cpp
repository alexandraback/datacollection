#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,cs;
int ans;
int arr[16];
void fxn(int pos,int cnt)
{
    if(cnt==0)
    {
        int ar[n][m],cn=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ar[i][j]=arr[cn++];
        int cur=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(ar[i][j]==1&&j+1<m&&ar[i][j+1]==1)
                    cur++;
                if(ar[i][j]==1&&i+1<n&&ar[i+1][j]==1)
                    cur++;
            }
        ans=min(ans,cur);
        /*if(cs==3&&cur==1)
        {
            for(int i=0;i<n*m;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }*/
        return;
    }
    if(pos==n*m)
        return;
    arr[pos]=1;
    fxn(pos+1,cnt-1);
    arr[pos]=0;
    fxn(pos+1,cnt);
}
int main()
{
    //freopen("ip.txt","r",stdin);
    //freopen("op.txt","w",stdout);
    int t;
    cin>>t;
    cs=1;
    while(t--)
    {
       // cs++;
        cout<<"Case #"<<cs++<<": ";
        cin>>n>>m>>k;
        if(n==1&&m==1)
            cout<<0<<endl;
        else if(k<=((n*m)+1)/2)
            cout<<0<<endl;
        else
        {
            for(int i=0;i<n*m;i++)
                arr[i]=0;
            ans=1000000007;
            fxn(0,k);
            cout<<ans<<endl;
        }
    }
}
