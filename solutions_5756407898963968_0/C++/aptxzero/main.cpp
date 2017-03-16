#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

void solve(char* ans)
{
    int a,b,ret=0;
    int before[4][4];
    int after[4][4];
    cin>>a;
    a-=1;
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
            cin>>before[i][j];
    cin>>b;
    b-=1;
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
            cin>>after[i][j];
    for(int i=0;i<4;++i)
    {
        int c=before[a][i];
        for(int j=0;j<4;++j)
        {
            if(c==after[b][j])
            {
                if(ret)
                {
                    strcpy(ans,"Bad magician!");
                    return;
                }
                ret=after[b][j];
            }
        }
    }
    if(ret)
    {
        itoa(ret,ans,10);
        return;
    }
    strcpy(ans,"Volunteer cheated!");
}

int main()
{
#ifdef LOCALMACHINE
    freopen("C:\\Users\\zero\\Desktop\\A-small-attempt0.in","r",stdin);
    freopen("C:\\Users\\zero\\Desktop\\A-small-attempt0.out","w",stdout);
#endif
    int T;
    char ans[20];
    cin>>T;
    for(int i=1;i<=T;++i)
    {
        solve(ans);
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}
