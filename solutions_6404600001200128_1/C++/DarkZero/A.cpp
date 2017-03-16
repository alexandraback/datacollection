#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int t;
int n;
int num[2000];

int main()
{
	freopen("A.in","r",stdin);
	freopen("Aout.txt", "w", stdout);
	
	cin>>t;
	for(int files=1; files<=t; files++)
	{
		cin>>n;
		int i;
		for(i=1;i<=n;i++)
		{
			cin>>num[i];
		}
		
		int ans1=0;
		for(i=2;i<=n;i++)
		{
			ans1 += max(0, num[i-1]-num[i]);
		}
		
		int ans2=0;
		int rate=0;
		for(i=2;i<=n;i++)
			rate = max(rate, num[i-1]-num[i]);
		
		for(i=1; i<=n-1;i++)
		{
			if(num[i] - rate >=0)
				ans2 += rate;
			else
				ans2 += num[i];
		}
		printf("Case #%d: %d %d\n", files, ans1, ans2);
	}
	//system("pause");
	return 0;
}








