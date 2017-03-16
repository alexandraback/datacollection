#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
char buf[1000000];
string a[110];
vector <pair <char,int> > b[110];
void get(int id)
{
    b[id].clear();
    for (int i=0;i<a[id].size();i++)
        if (i==0 || a[id][i]!=a[id][i-1])
            b[id].push_back(make_pair(a[id][i],1));
        else
            b[id].back().second++;
}
int calc(int n)
{
    for (int i=1;i<=n;i++)
        get(i);
    for (int i=1;i<=n;i++)
    {
        if (b[i].size()!=b[1].size())
            return(-1);
        for (int j=0;j<b[i].size();j++)
            if (b[i][j].first!=b[1][j].first)
                return(-1);
    }
    int ans=0;
    for (int i=0;i<b[1].size();i++)
    {
        vector <int> tmp;
        for (int j=1;j<=n;j++)
            tmp.push_back(b[j][i].second);
        sort(tmp.begin(),tmp.end());
        int mid=tmp[n/2];
        for (int j=0;j<tmp.size();j++)
            ans+=abs(tmp[j]-mid);
    }
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            a[i]=buf;
        }
        int ans=calc(n);
        static int id=0;
        printf("Case #%d: ",++id);
        if (ans==-1)
            printf("Fegla Won\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

