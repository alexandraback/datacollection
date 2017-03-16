#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;
int c[2][4][4];
int cnt[17];
vector<int>ans;
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,ca=0;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        ans.clear();
        scanf("%d",&a);
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                scanf("%d",&c[0][i][j]);
        scanf("%d",&b);
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                scanf("%d",&c[1][i][j]);
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<4;++i)
            cnt[c[0][a-1][i]]++;
        for(int i=0;i<4;++i)
            cnt[c[1][b-1][i]]++;
        for(int i=1;i<17;++i)
            if(cnt[i]==2)
                ans.push_back(i);
        printf("Case #%d: ",++ca);
        if(ans.size()==1)
            printf("%d\n",ans[0]);
        else if(ans.size()==0)
            printf("Volunteer cheated!\n");
        else printf("Bad magician!\n");
    }
}
