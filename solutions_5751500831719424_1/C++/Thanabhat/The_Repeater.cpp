/*
AUTHOR: THANABHAT KOOMSUBHA
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

#define pci pair<char,int>

using namespace std;

int N;
char str[128][128];
int len[128];
vector<pci > v[128];
int mn[128],mx[128];

int solve(int cc)
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",str[i]);
        len[i]=strlen(str[i]);
        v[i].clear();
        mn[i]=999;
        mx[i]=0;
    }

    bool canwin = true;

    for(int i=0;i<N&&canwin;i++)
    {
        for(int j=0;j<len[i]&&canwin;j++)
        {
            int cnt=1;
            char tmpch=str[i][j];
            while(j<len[i]-1&&str[i][j+1]==tmpch)
            {
                j++;
                cnt++;
            }
            v[i].push_back(pci(str[i][j],cnt));
            int p = v[i].size()-1;
            if(v[i][p].first!=v[0][p].first)
            {
                canwin=false;
            }
            mn[p]=min(mn[p],v[i][p].second);
            mx[p]=max(mx[p],v[i][p].second);
        }
        if(v[i].size()!=v[0].size())
        {
            canwin=false;
        }
    }

    printf("Case #%d: ",cc);
    if(!canwin)
    {
        printf("Fegla Won\n");
        return 1;
    }

//    for(int i=0;i<N;i++)
//    {
//        for(int j=0;j<v[i].size();j++)
//        {
//            printf("%c %d, ",v[i][j].first,v[i][j].second);
//        }
//        printf("\n");
//    }

    int sol=0;
    for(int j=0;j<v[0].size();j++)
    {
        int nnn = 1000000;
        for(int k=mn[j];k<=mx[j];k++)
        {
            int tmp=0;
            for(int i=0;i<N;i++)
            {
                tmp+=abs(v[i][j].second-k);
            }
            nnn=min(nnn,tmp);
        }
        sol+=nnn;
    }
    printf("%d\n",sol);

    return 0;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
        solve(i+1);

	return 0;
}
