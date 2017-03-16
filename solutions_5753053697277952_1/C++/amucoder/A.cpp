#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define pii pair<int,int>


int main()
{
int i,j,k,t,T,n;
vector<pii> a;

scanf("%d",&T);

for(t=1;t<=T;t++)
	{
	scanf("%d",&n);
	a.clear();
	for(i=0;i<n;i++)
		{
		scanf("%d",&k);
		a.push_back(pii(k,i));
		}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());	

	printf("Case #%d:",t);
	while(a[0].first>0)
		{
		if(a[0].first>a[1].first+1)
			{
			printf(" %c%c",a[0].second+'A',a[0].second+'A');
			a[0].first-=2;
			}
		else	if(n>2 && a[0].first == 1 && a[1].first ==1 && a[2].first>0)
			{
			printf(" %c",a[0].second+'A');
			a[0].first--;
			}
		else
			{
			printf(" %c%c",a[0].second+'A',a[1].second+'A');
			a[0].first--;
			a[1].first--;
			}

		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());	

		}		
	printf("\n");


	}

return 0;
}
