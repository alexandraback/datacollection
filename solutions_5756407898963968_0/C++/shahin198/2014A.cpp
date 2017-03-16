#include<bits/stdc++.h>
using namespace std;
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main(){
    //FILEIO("B-small-practice");
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int m[5][5],nm[5][5];
    int t,i,j,r,nr,k,cnt,v;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>r;
        for(k=0;k<4;k++)
        for(j=0;j<4;j++)
        cin>>m[k][j];
        cin>>nr;
        for(k=0;k<4;k++)
        for(j=0;j<4;j++)
        cin>>nm[k][j];
        cnt=0;
        for(k=0;k<4;k++)
        for(j=0;j<4;j++)
        if(m[r-1][k]==nm[nr-1][j])
        {cnt++;
        v=m[r-1][k];
        }
        cout<<"Case #"<<i<<": ";
        if(cnt==1)
        {
            cout<<v<<endl;
        }
        else if(cnt>1)
        cout<<"Bad magician!"<<endl;
        else
        cout<<"Volunteer cheated!"<<endl;
    }
    return 0;
}


