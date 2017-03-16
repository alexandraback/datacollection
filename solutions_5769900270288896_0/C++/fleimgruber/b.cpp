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


#define MAX_R 20

int r,c,n,a[MAX_R][MAX_R];

int main()
{
	int tc;
	scanf("%d",&tc);
	for (int cse=1; cse<=tc; cse++)
	{
		scanf("%d %d %d",&r,&c,&n);
		int ans=1234567;
		for (int i=(1<<(r*c))-1; i>=0; i--)
		{
			if (__builtin_popcount(i)!=n)
				continue;
			for (int j=0; j<r; j++)
				for (int k=0; k<c; k++)
					if (i&(1<<(j*c+k)))
						a[j][k]=true;
					else
						a[j][k]=false;
			int cur=0;
			for (int j=0; j<r; j++)
				for (int k=0; k<c; k++)
				{
					if (j-1>=0&&a[j][k]&&a[j-1][k])
						cur++;
					if (k-1>=0&&a[j][k]&&a[j][k-1])
						cur++;
				}
			ans=min(ans,cur);
		}
		printf("Case #%d: %d\n",cse,ans);
	}
	return 0;
}
