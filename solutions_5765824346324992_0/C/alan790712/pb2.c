#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define swap(x,y){long long int t=x;x=y;y=t;}
long long int B, N;
long long int M[50];
long long int h[1234][2];
long long int hNum;

void push(long long int who, long long int time)
{
    //prlong long intf("push %d %d\n", who, time);
    long long int now, pre;
    ++hNum;
    h[hNum][0] = who;
    h[hNum][1] = time;
    now = hNum;
    while(now>1)
    {
        pre = now/2;
        if(h[now][1]< h[pre][1] ||(h[now][1]==h[pre][1]&&h[now][0]< h[pre][0]))
        {
            swap(h[now][1],h[pre][1]);
            swap(h[now][0],h[pre][0]);
            now = pre;
        }
        else
        {
            break;
        }
    }
}
long long int pop(long long int *who, long long int *time)
{
    long long int now, next;
    *who = h[1][0];
    *time = h[1][1];
    h[1][0] = h[hNum][0];
    h[1][1] = h[hNum][1];
    --hNum;
    now = 1;
    while(now*2 <= hNum)
    {
        next = now*2;
        if(next<hNum &&(h[next+1][1] < h[next][1] ||(h[next+1][1]==h[next][1] && h[next+1][0] < h[next][0]) )  )
        {
            next = next+1;
        }
        if(h[next][1] < h[now][1] || (h[next][1]==h[now][1] && h[next][0] < h[now][0]))
        {
            swap(h[next][1],h[now][1]);
            swap(h[next][0],h[now][0]);
            now = next;
        }
        else
        {
            break;
        }
    }
    return *who;
}

int main()
{
    long long int T, t;
    long long int i;
    long long int ans;
    long long int time;
    long long int OAO, OAQ;
    scanf("%lld ",&T);
    for(t=1;t<=T;++t)
    {
        scanf("%lld %lld", &B, &N);
        hNum = 0;
        for(i=OAO=1;i<=B;++i)
        {
            scanf("%lld", &M[i]);
            OAO*= M[i];
            push(i, 0);
        }
        for(i=1, OAQ=0;i<=B;++i)
        {
            OAQ += OAO/M[i];
        }
        N%=OAQ;
        N += OAQ;
        for(i=ans=1;i<=N;++i)
        {
            ans = pop(&ans, &time);
//            printf("%d %d %d\n",ans, time, M[ans]);
            push(ans, time + M[ans]);
        }

        printf("Case #%lld: %lld\n", t, ans);
    }

    return 0;
}

