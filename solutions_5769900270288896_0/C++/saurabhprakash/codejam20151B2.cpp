#include<iostream>
#include<climits>
#include<cstdio>

using namespace std;

int set_bit_count(int x)
{
    int c=0;
    while(x)
        c+=x&1,x>>=1;
    return c;
}
int main()
{
    freopen("C:\\Users\\Saurabh Prakash\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\Saurabh Prakash\\Desktop\\out.txt","w",stdout);
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int r,c,n,i,j,k,small=INT_MAX;
        cin>>r>>c>>n;
        int lim=1<<(r*c);
        bool mark[r][c];
        for(k=0;k<lim;k++)
        {
            int temp=k,C=0;
            if(set_bit_count(temp)!=n)
                continue;
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    mark[i][j]=temp&1;
                    temp>>=1;
                }
            }
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    if(j+1<c && mark[i][j] && mark[i][j+1])
                        C++;
                    if(i+1<r && mark[i][j] && mark[i+1][j])
                        C++;
                }
            }
            if(C<small)
                small=C;
        }
        cout<<"Case #"<<cas++<<": "<<small<<endl;
    }

    return 0;
}
