#include <bits/stdc++.h>
#define inf 2000000000
#define ll long long
#define Max

using namespace std;

vector <int> v[2];
int n,r,c;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

bool valid(int x,int y){

    if(x>=0  && x<r && y>=0 &&y<c) return 1;

    return 0;
}

int main()
{
    int i,j,k,T,cas,ret=0,nb;

    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small2.txt","w",stdout);

    //freopen("inb.txt","r",stdin);

    scanf("%d",&T);

    for(cas=1;cas<=T;cas++)
    {
        scanf("%d %d %d",&r,&c,&n);

        v[0].clear();
        v[1].clear();

        for(i=0;i<r;i++){

            for(j=0;j<c;j++){

                nb=0;

                for(k=0;k<4;k++){
                    int ni,nj;

                    ni=i+dx[k];
                    nj=j+dy[k];
                    nb+=valid(ni,nj);
                }

                v[(i+j)%2].push_back(nb);

            }
        }

        sort(v[0].begin(),v[0].end());
        sort(v[1].begin(),v[1].end());

        for(i=1;i<v[0].size();i++) v[0][i]+=v[0][i-1];
        for(i=1;i<v[1].size();i++) v[1][i]+=v[1][i-1];

        if(n<=v[0].size()) ret=0;

        else ret = v[1][n-v[0].size()-1];

        if(n<=v[1].size()) ret=0;

        else ret = min(ret,v[0][n-v[1].size()-1]);



        printf("Case #%d: %d\n",cas,ret);
    }

    return 0;
}

