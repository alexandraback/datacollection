#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
    char c;
    int s;
    node(char a,int b)
    {
        c=a;
        s=b;
    }
};
int ab(int a)
{
    if(a<0)return -a;
    return a;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int o=0;o<tc;o++)
    {
        int total;
    char s[1005];
    scanf("%d",&total);
    vector<node> t[105];
    for(int i=0;i<total;i++)
    {
        scanf(" %s",s);
        int rep=0;
        for(int j=0;s[j];j++)
        {
            if(s[j+1]==NULL || s[j]!=s[j+1])
            {
                t[i].push_back(node(s[j],rep+1));
                rep=0;
            }
            else if(s[j+1] && s[j]==s[j+1])
            {
                rep++;
            }
        }
    }
    int no=0;
    for(int i=0;i<total-1;i++)
    {
        if(t[i].size()!=t[i+1].size())
            no=1;
        if(no)break;
        for(int j=0;j<t[i].size();j++)
        {
            if(t[i][j].c!=t[i+1][j].c)
                no=1;
            if(no)break;
        }if(no)break;
    }
    printf("Case #%d: ",o+1);
    if(no)
    {
        printf("Fegla Won\n");
    }
    else
    {

        int ans=0;
        for(int i=0;i<t[0].size();i++)
        {
            int m=10000000;
            for(int len=1;len<=100;len++)
            {
                int sum=0;
                for(int j=0;j<total;j++)
                {
                    sum+=ab(t[j][i].s-len);
                }
                m=min(m,sum);
            }
            ans+=m;
        }
        printf("%d\n",ans);
    }
    }


    return 0;
}
