#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=505;
char str[MAXN][MAXN],st[MAXN];
int n,len[MAXN],p[MAXN];
bool pend()
{
    memset(p,0,sizeof(p));
    int cnt=0,ans=0;
    for(int i=0 ; i<len[0]; ++i)
        if(i==0||str[0][i]!=str[0][i-1])
            st[cnt++]=str[0][i];
    for(int pos=0; pos<cnt; ++pos)
    {
        vector<int> vec;
        for(int i=0; i<n; ++i)
        {
            if(str[i][p[i]]!=st[pos])
                return false;
            int pre=p[i];
            while(str[i][p[i]]==st[pos])
                ++p[i];
            vec.push_back(p[i]-pre);
        }
        sort(vec.begin(),vec.end());
        int tt=vec[vec.size()/2];
        for(int i=0; i<vec.size(); ++i)
            ans+=abs(vec[i]-tt);
    }
    for(int i=0 ; i<n; ++i)
        if(p[i]<len[i])
            return false;
    printf("%d\n",ans);
    return true;
}
int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas)
    {

        scanf("%d",&n);
        for(int i=0; i<n; ++i)
        {
            scanf("%s",str[i]);
            len[i]=strlen(str[i]);
        }
        printf("Case #%d: ",cas);
        if(!pend())
            puts("Fegla Won");
    }
}
