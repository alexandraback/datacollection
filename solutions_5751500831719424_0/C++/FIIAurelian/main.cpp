#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,len[110],ok,t,SOL,cnt,N,Contor[110][110],nr,c,sol;
char S[110][110],A[110][110],*p;
int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&N);
        ok = 1;
        for(int i=1;i<=N;i++)
        {
            scanf(" %s",S[i]);
            A[i][0]=S[i][0];
            nr = 1;
            c = 1;
            cnt = 1;
            for(p=S[i]+1;*p;p++)
                if(*p != *(p-1))
                {
                    Contor[i][nr++] = c;
                    c = 1;
                    A[i][cnt++] = *p;
                }
                else c++;
             A[i][cnt]='\0';
             Contor[i][nr] = c;
             len[i] = cnt;
        }
        for(int i=2;i<=N;i++)
            if(len[i]!=len[1])ok=0;
        if(!ok)
        {
            printf("Case #%d: Fegla Won\n",t);
            continue;
        }
        for(int pos=0;pos<len[1];pos++)
            for(int i=2;i<=N;i++)
                if(A[i][pos]!=A[1][pos])
                {
                    ok=0;
                    break;
                }
        if(!ok)
        {
            printf("Case #%d: Fegla Won\n",t);
            continue;
        }
        SOL=0;
        for(int vec = 1;vec<=len[1];vec++)
        {
            sol = 1000000;
            for(int pivot = 1;pivot<=100;pivot++)
            {
                cnt = 0;
                for(int i= 1;i<=N;i++)
                    cnt += abs(Contor[i][vec]-pivot);
                sol = min(cnt,sol);
            }
            SOL+=sol;
        }
        printf("Case #%d: %d\n",t,SOL);
    }
    return 0;
}



