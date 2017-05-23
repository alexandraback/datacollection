#include<stdio.h>
typedef long long ll;

ll p[50];

ll evacuate(ll n)
{
    ll i, j, max, ans;
    max = 0;
    for(i=0; i<n; i++)
    {
        if(p[i]>max)
        {
            max=p[i];
            ans=i;
        }
    }
    return ans;
}

ll check(ll n)
{
    ll i, s, maj;
    s = 0;
    for(i=0; i<n; i++)
    {
        s+=p[i];
    }
    maj=(s)/2;
    for(i=0; i<n; i++)
    {
        if(p[i]>maj)
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    ll t, k, n, i, j, s, f, c;
    char ans1, ans2;
    freopen("A-large.in", "r", stdin);
    freopen("A-large-output.txt", "w", stdout);

    scanf("%lld", &t);
    //printf("%lld\n", t);
    for(k=1; k<=t; k++)
    {
        scanf("%lld", &n);
        //printf("%lld\n", n);
        s=0;
        for(i=0; i<n; i++)
        {
            scanf("%lld", &p[i]);
            s+=p[i];
        }
        printf("Case #%lld: ", k);
        while(s)
        {
            c=0;
            ans1=evacuate(n);
            p[ans1]--;
            c++;
            s--;
            ans2=evacuate(n);
            c++;
            p[ans2]--;
            s--;
            f=check(n);
            if(f==0)
            {
                c--;
                p[ans2]++;
                s++;
            }
            printf("%c", ans1+65);
            if(c==2)
            {
                printf("%c", ans2+65);
            }
            printf(" ");
        }
        printf("\n");
    }
}
