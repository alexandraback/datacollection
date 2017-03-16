#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

int t;
int n;
int pos;
int num[1010];
int idletime[1010];

int gcd(int x, int y)
{
	if(x<y)
		swap(x,y);
	if(y==0)
		return x;
	if(x%y==0)
		return y;
	return gcd(y, x%y);
}

int lcm(int x, int y)
{
	int p = gcd(x,y);
	return x/p*y;
}

void init()
{
	memset(idletime, 0, sizeof(idletime));
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("Bout.txt", "w", stdout);
	cin>>t;
	for(int files=1; files<=t; files++)
	{
		init();
		cin>>n>>pos;
		int i;
		for(i=1;i<=n;i++)
			cin>>num[i];
	
		int g = 1;
		for(i=1;i<=n;i++)
			g = lcm(g, num[i]);
		
		int rotation = 0;
		for(i=1;i<=n;i++)
			rotation += g/num[i];
		
		pos=pos%rotation;
		if(pos == 0)
			pos+=rotation;
		
		for(i=1;i<=pos;i++)
		{
			int mintime = 1<<30;
			int now = -1;
			for(int j=1;j<=n;j++)
			{
				if(idletime[j] < mintime)
				{
					now = j;
					mintime = idletime[j];
				}
			}
			idletime[now] += num[now];
			if(i==pos)
			{
				printf("Case #%d: %d\n", files, now);
			}
		}
	}
	//system("pause");
	return 0;
}



