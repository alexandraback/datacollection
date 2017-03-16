#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
int n;
char buf[999];
typedef pair<int, char> pic;
pic a[200][200];
int al[200];
void input()
{
	int i, j, k, l;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",buf);
		al[i] = 0;
		j=buf[0];
		k=1;
		for(l=1;buf[l];l++)
		{
			if(j!=buf[l])
			{
				a[i][al[i]] = pic(k, j);
				j = buf[l];
				k = 1;
				al[i]++;
			}
			else
				k++;
		}
		a[i][al[i]] = pic(k, j);
		al[i]++;
	}
}
bool able()
{
	int i, j;
	for(i=0;i<n;i++)
	{
		if(al[i]!= al[0])
			break;
	}
	if(i<n)return false;
	for(j=0;j<al[0];j++)
	{
		for(i=0;i<n;i++)
			if(a[i][j].second != a[0][j].second)
				break;
		if(i<n)
			break;
	}
	if(j<al[0])
		return false;
	return true;
}
int d[200];
int p[200];
void process()
{
	int i, j, k;
	if(able())
	{
		for(i=0;i<al[0];i++)
		{
			for(j=0;j<n;j++)
			{
				p[j] = a[j][i].first;
			}
			sort(p,p+n);
			k = p[n/2];
			d[i] = 0;
			for(j=0;j<n;j++)
				d[i] += abs(p[j] - k);
		}
		int res = 0;
		for(i=0;i<al[0];i++)
			res += d[i];
		printf("%d",res);

	}
	else
		printf("Fegla Won");
}
int main()
{
	int t, tv;
	freopen("A-large (1).in","rt",stdin);
	freopen("A-large (1).out","wt",stdout);
	scanf("%d",&t);
	tv = 0;
	while(t--)
	{
		tv++;
		input();
		printf("Case #%d: ",tv);
		process();
		printf("\n");
	}
}