#include <iostream>
#include <cstdio>
#include<vector>
#include <cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 111
#define INF 99999999
vector<int>vecb;
vector<int>veca;
vector<int>vec[110];
char str[110][110];
int dp[110][110];
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T,t,i,j,n,k;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        veca.clear();
        vecb.clear();
        for(i=0; i<=100; i++)vec[i].clear();
        scanf("%d",&n);
        for(i=1; i<=n; i++)scanf("%s",str[i]);
        int len=strlen(str[1]);
        int l=1;
        veca.push_back(str[1][0]);
        int as=0;
        for(i=1; i<len; i++)
        {
            if(str[1][i]!=str[1][i-1])
            {
                veca.push_back(l);
                vec[as].push_back(l);
                as++;
                veca.push_back(str[1][i]);
                l=1;
            }
            else l++;
        }
        veca.push_back(l);
        vec[as].push_back(l);
        printf("Case #%d: ",t);
        for(i=2; i<=n; i++)
        {
            vecb.clear();
            vecb.push_back(str[i][0]);
            int len=strlen(str[i]);
            l=1;
            for(j=1; j<len; j++)
            {
                if(str[i][j]!=str[i][j-1])
                {
                    vecb.push_back(l);
                    vecb.push_back(str[i][j]);
                    l=1;
                }
                else l++;
            }
            vecb.push_back(l);
            int lena=veca.size();
            int lenb=vecb.size();
            if(lena!=lenb)break;
            for(j=0;j<lena;j+=2)
            {
                if(veca[j]!=vecb[j])break;
                vec[j/2].push_back(vecb[j+1]);
            }
            if(j<lena)break;
        }
        if(i<=n)
        {
            cout<<"Fegla Won"<<endl;
            continue;
        }
        int minn=0;
        for(i=0;i<=as;i++)
        {
            int ps=0,ks=9999999;
            for(j=0;j<vec[i].size();j++)
            {
                ps=0;
                for(k=0;k<vec[i].size();k++)
                {
                    ps+=abs(vec[i][k]-vec[i][j]);
                }
                ks=min(ks,ps);
            }
            minn+=ks;
        }
        cout<<minn<<endl;
    }
    return 0;
}
