#include<cstdio>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;++i)
int a[5][5],b[5][5],ans1,ans2;
bool u1[20],u2[20];
int main()
{
    int Q;
    scanf("%d",&Q);
    fo(T,1,Q)
    {
        memset(u1,0,sizeof u1);
        memset(u2,0,sizeof u2);
        scanf("%d",&ans1);
        fo(i,1,4)
            fo(j,1,4)scanf("%d",a[i]+j);
        scanf("%d",&ans2);
        fo(i,1,4)
            fo(j,1,4)scanf("%d",b[i]+j);
        fo(i,1,4)u1[a[ans1][i]]=1,u2[b[ans2][i]]=1;
        int cnt=0,answer;
        fo(i,1,16)
            if(u1[i]&&u2[i])
                answer=i,++cnt;
        printf("Case #%d: ",T);
        if(cnt==0)puts("Volunteer cheated!");
        else if(cnt>1)puts("Bad magician!");
        else printf("%d\n",answer);
    }
    return 0;
}
