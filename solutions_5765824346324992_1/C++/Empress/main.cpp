#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[1005];
LL sum[1005];

bool can(LL t, int b, int n)
{
	LL num1=0, num2=0;
	for(int i=1; i<=b; i++)
	{
		num1+=t/a[i];
		if(t%a[i])
            num2++;
	}
	if(num1+num2>=n)
        return true;
	return false;
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w", stdout);
	int t, ca=1;
	scanf("%d", &t);
	while(t--)
	{
	    int b, n;
		scanf("%d%d", &b, &n);
		for(int i=1; i<=b; i++)
			scanf("%d", &a[i]);
        printf("Case #%d: ", ca++);
		if(n<=b)
        {
			printf("%d\n", n);
			continue;
        }
		int ans=-1;
        LL l=0, r=LLONG_MAX;
        while(l+1<r)
        {
            LL mid=(l+r)>>1;
            if(can(mid, b, n))
                r=mid;
            else
                l=mid;
        }
        LL t=r;
        if(can(l, b, n))
            t=l;
        memset(sum, 0, sizeof(sum));
        LL ans1=0, ans2=0;
        for(int i=1; i<=b; i++)
        {
            if((t-1)%a[i])
                ans2++;
            ans1+=(t-1)/a[i];
            sum[i]=(t-1)%a[i];
        }
        LL d=n-(ans1+ans2);
        for(int i=1; i<=b; i++)
            if(!sum[i])
            {
                d--;
                if(!d)
                {
                    ans=i;
                    break;
                }
            }
		printf("%d\n", ans);
	}
    return 0;
}
