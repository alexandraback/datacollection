#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<fstream>
using namespace std;
set<int> s;
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("a_s.out","w",stdout);
    int t,n,k,x;
    int cnt,casecnt=1;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        s.clear();
        scanf("%d",&n);
        for(int i=1;i<=4;i++)
            for(int j=1;j<=4;j++)
            {
                scanf("%d",&k);
                if(i==n) s.insert(k);
            }
        scanf("%d",&n);
        for(int i=1;i<=4;i++)
            for(int j=1;j<=4;j++)
            {
                scanf("%d",&k);
                if(i==n&&s.find(k)!=s.end()){
                    cnt++;
                    x = k;
                }
            }
        printf("Case #%d: ",casecnt++);
        if(cnt==0)printf("Volunteer cheated!\n");
        else if(cnt!=1)printf("Bad magician!\n");
        else printf("%d\n",x);
    }


    return 0;
}


