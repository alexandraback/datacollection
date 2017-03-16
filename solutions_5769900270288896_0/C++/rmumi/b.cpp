#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

using namespace std;

#define FILE
typedef long long lint;

int xd[]{1,0,-1,0};
int yd[]{0,1,0,-1};
char broj(pair<int,int> to,vector<vector<bool> > &ve)
{
    int c=0;
    for(int i=0;i<4;i++)
        if(to.xx+xd[i]<ve.size() && to.xx+xd[i]>=0
        &&to.yy+yd[i]<ve[0].size() && to.yy+yd[i]>=0
        &&ve[to.xx+xd[i]][to.yy+yd[i]]==1
        &&ve[to.xx][to.yy]==1)
            c++;
    return c;
}

pair<int,int> maxi(vector<vector<bool> > &ve)
{
    pair<int,int> to(0,0);
        for(int i=0;i<ve.size();i++)
            for(int j=0;j<ve[0].size();j++)
                if(ve[i][j] && broj(mp(i,j),ve)>broj(to,ve))to=mp(i,j);
    return to;
}

int main()
{
#ifdef FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int tt;
    scanf("%d",&tt);
    for(int CASE=1;CASE<=tt;CASE++)
    {
        int r,c,n;
        scanf("%d %d %d",&r,&c,&n);
        vector<vector<bool> > ve(r,vector<bool>(c,1));
        int minir=45465464;
        for(int i=0;i<(1<<(r*c));i++)
        {
            int l=0;
            for(int j=0;j<r*c;j++)
                if(i&(1<<j))l++;
            if(l!=n)continue;
            for(int j=0;j<r*c;j++)
                ve[j/c][j%c]=!!(i&(1<<j));
            int rez=0;
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    rez+=broj(mp(i,j),ve);
            minir=min(rez,minir);
        }
        printf("Case #%d: %d\n",CASE,minir/2);
        /*vector<vector<bool> > ve(r,vector<bool>(c,1));
        for(int ita=0;ita<r*c-n;ita++)//tried gready
        {
            pair<int,int> m=maxi(ve);
            ve[m.xx][m.yy]=0;
        }
        int rez=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                rez+=broj(mp(i,j),ve);
        printf("Case #%d: %d\n",CASE,rez/2);*/
    }
    return 0;
}

