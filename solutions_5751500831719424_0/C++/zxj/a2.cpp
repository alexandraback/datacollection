#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
int f[1005][30];
char s[1005],t[1005];
int main()
{
    int i,j,T;
//    freopen("A-small-attempt1.in","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    int n;
    int cas=0;
    while(T--)
    {
        scanf("%d",&n);
        int o=0;
        scanf("%s",s);
        int len1 = strlen(s);

        scanf("%s",t);
        int len2 = strlen(t);

        j=0;
        int sum=0;
        for(i=0;i<len1;)
        {
            int index=s[i]-'a';
            int num=0;
            int w=0;
            while(i<len1&&s[i]-'a'==index)
            {
                num++;i++;w=1;
            }
            //if(w)i--;
            int index2=t[j]-'a';
            //cout<<index2<<" * "<<index<<endl;
            if(index2!=index){o=1;break;}
            int num2=0;
            while(j<len2&&t[j]-'a'==index2)
            {
                num2++;j++;
            }
            //cout<<num<<" "<<num2<<endl;
            if(num>num2)sum+=num-num2;
            else sum+=num2-num;
        }
        if(j<len2)o=1;
        if(o)
            printf("Case #%d: Fegla Won\n",++cas);
        else
            printf("Case #%d: %d\n",++cas,sum);
    }
    return 0;
}
