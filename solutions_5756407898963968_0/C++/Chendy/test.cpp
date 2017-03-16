#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<cstring>
#include<climits>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<stack>
#include<deque>
#include<list>
#include<vector>
#define LL long long
using namespace std;
int n,m,cnt,snt,s,t,ss,tt,times;
LL oo=1000000007;
int ans;
int a[10][10],b[10][10];
void work(int lab)
{
	printf("Case #%d: ",lab);
	scanf("%d",&n);
	for (int i=1;i<=4;i++)
	for (int j=1;j<=4;j++) scanf("%d",&a[i][j]);
	scanf("%d",&m);
	for (int i=1;i<=4;i++)
	for (int j=1;j<=4;j++) scanf("%d",&b[i][j]);
	ans=0;
	for (int i=1;i<=4;i++)
	{
		for (int j=1;j<=4;j++)
		if (a[n][i]==b[m][j]) 
		{
			ans++;
			cnt=a[n][i];
		}
	}
	if (ans==1) printf("%d\n",cnt);
	else if (ans==0) printf("Volunteer cheated!\n");
	else printf("Bad magician!\n");
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&times);
	for (int i=1;i<=times;i++)
	work(i);
    return 0;
}

