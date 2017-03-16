#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char s[110][110];
int indexx[110];
int abs(int x)
{
    if(x<0)return -x;
    return x;
}
vector<int> num;
int main()
{
     freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,no=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,sol=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            indexx[i]=0;
        }
        bool zavrseno=false;
        bool finish=false;
        int comp=0;
        while(!zavrseno)
        {
            char controla=s[0][indexx[0]];
            for(int i=0;i<n;i++)
            {
                int len=strlen(s[i]);
                int tmp=indexx[i],cnt=0;
                char check=s[i][tmp];
                while(tmp<len&&check==s[i][tmp])
                {
                    if(controla!=s[i][tmp])finish=true;
                    tmp++;
                    cnt++;
                }
                if(tmp==len)
                {
                    zavrseno=true;
                    comp++;
                }
                indexx[i]=tmp;
                num.push_back(cnt);
            }
            sort(num.begin(),num.end());
            int median=(n+1)/2-1;

            for(int i=0;i<n;i++)
            {

                sol+=abs(num[median]-num[i]);
            }
            num.clear();
            if(finish)break;
        }
        if(!finish&&comp==n)printf("Case #%d: %d\n",no++,sol);
        else printf("Case #%d: Fegla Won\n",no++);
    }
    return 0;
}
