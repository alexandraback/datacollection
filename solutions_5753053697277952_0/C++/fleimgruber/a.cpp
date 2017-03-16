#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define pb push_back
#define sz(a) ((int)(a).size())
#define mp make_pair
#define fi first
#define se second

typedef pair<int,int> pint;
typedef long long ll;
typedef vector<int> vi;


#define MAX_N 30

int n,cnt[MAX_N];

int main()
{
	int tc;
	scanf("%d",&tc);
	for (int asdf=1; asdf<=tc; asdf++)
	{
		printf("Case #%d: ",asdf);
		scanf("%d",&n);
		int cake=0;
		for (int i=1; i<=n; i++)
		{
			scanf("%d",cnt+i);
			cake+=cnt[i];
		}
		while (cake)
		{
			//could be done via a heap.. but it doesn't matter here
			int hi=max_element(cnt+1,cnt+1+n)-cnt;
			cnt[hi]--;
			cake--;
			printf("%c",hi+'A'-1);
			hi=max_element(cnt+1,cnt+1+n)-cnt;
			if (2*cnt[hi]>cake)
			{
				cnt[hi]--;
				cake--;
				printf("%c",hi+'A'-1);
			}
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
