#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define L(k) ((k)&0xffff)
#define H(k) ((k)>>16)

void pri(char a,char b,int n)
{
    while(n--)printf(" %c%c",a,b);
}
void pri(char a,int n)
{
    while(n--)printf(" %c",a);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;++tc)
    {
        int n;
        int p[32];
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d",p+i);
            p[i]=p[i]<<16|'A'+i;
        }
        std::sort(p,p+n,std::greater<int>());
        printf("Case #%d:",tc);
        pri(L(p[0]),H(p[0])-H(p[1]));
        for(int i=2;i<n;++i)pri(L(p[i]),H(p[i]));
        pri(L(p[0]),L(p[1]),H(p[1]));
        printf("\n");
    }
    return 0;
}
