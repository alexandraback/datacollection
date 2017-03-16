//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

int ar[100009];
vector<int>vec[100009];

int main()
{
    freopen("out.txt","rt",stdin);
    freopen("out1.txt","wt",stdout);
    int i,j,k,l,n,cas,test,flag,temp,now,ans=0,siz;

    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        scanf("%d",&n);
        for(i=0;i<=100000;i++) vec[i].clear();

        for(i=1;i<=n;i++)
        {
            scanf("%d",&ar[i]);
            vec[ar[i]].push_back(i);
        }



        printf("Case #%d:",cas);

        for(i=10000;i>=1;i--)
        {
            siz=vec[i].size();
            if(siz)
            {
                //cout<<i<<" ";
                if(siz%2)
                {
                    printf(" %c",vec[i][0]+'A'-1);
                    for(j=1;j<siz;j+=2)
                    {
                        printf(" %c%c",vec[i][j]+'A'-1,vec[i][j+1]+'A'-1);
                    }

                    for(j=0;j<siz;j++) vec[i-1].push_back(vec[i][j]);
                }
                else
                {
                    for(j=0;j<siz;j+=2)
                    {
                        printf(" %c%c",vec[i][j]+'A'-1,vec[i][j+1]+'A'-1);
                    }
                    for(j=0;j<siz;j++) vec[i-1].push_back(vec[i][j]);
                }
            }
        }

        printf("\n");

    }



}
