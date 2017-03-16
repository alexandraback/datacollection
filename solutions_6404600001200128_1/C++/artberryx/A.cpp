//*
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[5000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, TT;
	scanf("%d", &TT);
	for(T=0;T<TT;T++)
	{
		int i, j, k;
		int n;
		int dab1=0, dab2=0, max=0;
		scanf("%d", &n);
		for(i=0;i<n;i++) scanf("%d", &a[i]);
		for(i=0;i<n-1;i++)
		{
			if(a[i] > a[i+1])
			{
				 dab1+=a[i]-a[i+1];
				 if(max < a[i]-a[i+1])
				 {
					 max=a[i]-a[i+1];
				 }
			}
		}
		for(i=0;i<n-1;i++)
		{
			if(a[i] < max) dab2+=a[i];
			else dab2+=max;
		}
		printf("Case #%d: %d %d\n", T+1, dab1, dab2);
	}
	return 0;
}

//*/