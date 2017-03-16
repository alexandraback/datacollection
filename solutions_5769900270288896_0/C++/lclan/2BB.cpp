#include<iostream>
#include<string.h>
using namespace std;
int ma[20][20];
int t,n,m,num,c;
int ans;
int check()
{
    int ret =0;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m-1;j++)
        {
            if(ma[i][j]==1 & ma[i][j+1]==1)ret++;
        }
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<m;j++)
        {
            if(ma[i][j]==1 & ma[i+1][j]==1)ret++;
        }
    }
    return ret;
}
void dfs(int i,int j,int now)
{
    if(i==n && j ==0)
    {
        if(now == 0)
        {
           // cout<<now<<endl;
            int tmp = check();
//            for(int ii=0;ii<n;ii++)
//            {
//                for(int jj=0;jj<m;jj++)
//                {
//                    cout<< ma[ii][jj]<<' ';
//                }
//                cout<<endl;
//            }
            //cout<<tmp<<endl;
            if(tmp<ans)ans=tmp;
        }
        return;
    }
    int newi,newj;
    newi = i;
    if(j<m-1)
    {
        newj = j+1;
    }else
    {
        newi = i+1;
        newj = 0;
    }
    dfs(newi,newj,now);
    if(now != 0)
    {
        ma[i][j]=1;
        dfs(newi,newj,now-1);
        ma[i][j]=0;
    }
    return;
}
int main()
{
    int i,j,k;
    c=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>num;
        ans = n*m*2;
        memset(ma,0,sizeof(ma));
        dfs(0,0,num);
        cout<<"Case #"<<c<<": "<<ans<<endl;
        c++;

    }
}
