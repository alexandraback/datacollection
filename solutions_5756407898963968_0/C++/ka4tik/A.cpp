/*
 *Kartik Singal @ ka4tik
 */
#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n)
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    
    int test;s(test);
    int kase=0;
    while(test--)
    {
        kase++;
        vector<int> v1(4);
        vector<int> v2(4);
        int t;cin>>t;
        int temp;
        for(int i=1;i<=4;i++)
        {
            if(t==i)
            {
                for(int j=0;j<4;j++)
                    s(v1[j]);
            }
            else
            {
                for(int j=0;j<4;j++)
                    s(temp);
            }
        }
        cin>>t;
        for(int i=1;i<=4;i++)
        {
            if(t==i)
            {
                for(int j=0;j<4;j++)
                    s(v2[j]);
            }
            else
            {
                for(int j=0;j<4;j++)
                    s(temp);
            }
        }
        int ans=0;
        int c=0;
        for(int i=1;i<=16;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++)
                {
                    if(v1[j]==v2[k]&&v1[j]==i)
                    {
                        ans=i;
                        c++;
                    }
                }
            }
        }
        if(c==1)
        {
            printf("Case #%d: %d\n",kase,ans);
        }
        else if(c==0)
        {
            printf("Case #%d: Volunteer cheated!\n",kase);
        }
        else
        {
            printf("Case #%d: Bad magician!\n",kase);
        }
    }

    return 0;
}

