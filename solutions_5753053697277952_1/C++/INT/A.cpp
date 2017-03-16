#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int a[30];
vector<pair<int,int> > ans;

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        int n;
        scanf("%d",&n);
        int sum=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        ans.clear();
        while (sum>0)
        {
            int tmp = -1;
            for (int i=0;i<n;i++)
                if (tmp==-1 || a[i]>a[tmp]) tmp=i;
            pair<int,int> cc;
            cc.first=tmp;
            a[tmp]--;
            sum--;
            if (sum == 0)
            {
                cc.second = -1;
            }
            else
            {
                for (int i=0;i<n;i++)
                    if (a[i]>0 && i!=tmp)
                    {
                        cc.second=i;
                        a[i]--;
                        sum--;
                        break;
                    }
            }
            ans.push_back(cc);
        }
        printf("Case #%d: ",t);
        for (int j=ans.size()-1;j>=0;j--)
        {
            if (ans[j].second == -1) printf("%c%c",'A'+ans[j].first,j==0?'\n':' ');
            else printf("%c%c%c",'A'+ans[j].first,'A'+ans[j].second,j==0?'\n':' ');
        }
    }
    return 0;
}
