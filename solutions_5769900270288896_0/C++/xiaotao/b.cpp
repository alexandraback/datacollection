#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int T, r, c, n, d, k;
	scanf("%d", &T);
	for (int tt=1; tt<=T; ++tt)
	{
		scanf("%d%d%d", &r, &c, &n);
		if (c<r) swap(r, c);
		if (r==1)
		{
			int ans=0;
			int cnt=(c+1)/2;
			if (n>cnt)
			{
				if (c%2==0) ++ans, ++cnt;
				if (n>cnt) ans+=2*(n-cnt);
			}
			printf("Case #%d: %d\n", tt, ans);
			continue;
		}
		int ans1=0;
		int ans2=0;
		int cnt1=((c+1)/2)*((r+1)/2)+(c/2)*(r/2);
		int cnt2=r*c-cnt1;
		if (n>cnt1)
		{
			k=0;
			if ((c+1)%2==1) ++k;
			if ((r+1)%2==1) ++k;
			if ((r+c)%2==1) ++k;
			d=min(k, n-cnt1);
			ans1+=d*2;
			cnt1+=d;
			if (n>cnt1)
			{
				k=(c-1)/2+(r-1)/2;
				if ((r+c)&1) k+=(c-2)/2+(r-2)/2;
				else k<<=1;
				d=min(k, n-cnt1);
				ans1+=d*3;
				cnt1+=d;
			}
			if (n>cnt1) ans1+=(n-cnt1)*4;
		}
		if (n>cnt2)
		{
			k=1;
			if ((c+1)%2==0) ++k;
			if ((r+1)%2==0) ++k;
			if ((r+c)%2==0) ++k;
			d=min(k, n-cnt2);
			ans2+=d*2;
			cnt2+=d;
			if (n>cnt2)
			{
				k=(c-2)/2+(r-2)/2;
				if ((r+c)&1) k+=(c-1)/2+(r-1)/2;
				else k<<=1;
				d=min(k, n-cnt2);
				ans2+=d*3;
				cnt2+=d;
			}
			if (n>cnt2) ans2+=(n-cnt2)*4;
		}
		//printf("%d %d\n", ans1, ans2);
		printf("Case #%d: %d\n", tt, min(ans1, ans2));
	}
	return 0;
}

