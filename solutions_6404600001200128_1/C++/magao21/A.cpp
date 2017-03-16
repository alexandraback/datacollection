#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
int caseNumber, b[1111],n,ans1,ans2,Max;
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("Aoutput.txt","w",stdout);
	scanf("%d",&caseNumber);
	for (int T=1;T<=caseNumber;T++)
	{
		scanf("%d",&n);
		Max=0, ans1=0, ans2=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			if (i && b[i] < b[i-1])
			{
				ans1+=b[i-1]-b[i];
				if (b[i-1]-b[i]>Max) Max=b[i-1]-b[i];
			}
		}
		for (int i=0;i<n-1;i++)
			ans2+=(b[i]>Max?Max:b[i]);
		printf("Case #%d: %d %d\n",T,ans1,ans2);
	}
//	system("pause");
	return 0;
}
