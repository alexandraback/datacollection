#include<bits/stdc++.h>
#define mx 20
#define pb push_back
using namespace std;
bool taken[mx][mx];
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};
int main()
{
freopen("B-small-attempt3.in","r",stdin);

freopen("out1.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {

        int r,c,n;
        scanf("%d %d %d",&r,&c,&n);


        memset(taken,0,sizeof taken);
        int d=1;
        taken[0][0]=1;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!taken[i][j]){

                int ii=i-1;
                int jj=j-1;
                int w=0;
                if(ii>=0 &&taken[ii][j]==1)w=1;
                if(jj>=0 &&taken[i][jj]==1)w=1;
                if(w==0)
                {
                    taken[i][j]=1;
                    d++;
                }
                }

            }
        }
        int ans=0;
        if(d>=n)ans=0;
        else
        {
            vector<int>x;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    if(!taken[i][j]){
                        int cc=0;
                        for(int k=0;k<4;k++)
                        {
                            int p=xx[k]+i;
                            int q=yy[k]+j;
                            if(p>=0 && p<r && q>=0 && q<c && taken[p][q]==1)cc++;
                        }
                        x.pb(cc);

                    }

                }
            }
            //////
            sort(x.begin(),x.end());
            int pp=n-d;
            for(int i=0;i<pp;i++)ans+=x[i];



        }


        //printf("Case #%d: %d\n",cas,ans);
        //////////
        int ans1=-1;
        memset(taken,0,sizeof taken);
        d=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!taken[i][j] && !(i==0 && j==0)){

                int ii=i-1;
                int jj=j-1;
                int w=0;
                if(ii>=0 &&taken[ii][j]==1)w=1;
                if(jj>=0 &&taken[i][jj]==1)w=1;
                if(w==0)
                {
                    taken[i][j]=1;
                    d++;
                }
                }

            }
        }
         ans1=0;
        if(d>=n)ans1=0;
        else
        {
            vector<int>x;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    if(!taken[i][j]){
                        int cc=0;
                        for(int k=0;k<4;k++)
                        {
                            int p=xx[k]+i;
                            int q=yy[k]+j;
                            if(p>=0 && p<r && q>=0 && q<c && taken[p][q]==1)cc++;
                        }
                        x.pb(cc);

                    }

                }
            }
            //////
            sort(x.begin(),x.end());
            int pp=n-d;
            for(int i=0;i<pp;i++)ans1+=x[i];



        }

        ans=min(ans,ans1);
        ///////
        printf("Case #%d: %d\n",cas,ans);
    }


}
