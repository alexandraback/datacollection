#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N = 1005;
int n , maxm , T;
int m[N];

void Init()
{
	scanf("%d",&n);
	maxm = 0;
	fo(i,1,n) scanf("%d",&m[i]) , maxm = max(maxm , m[i]);
}

void Work()
{
	int ans(0);
	fo(i,1,n-1)
	if (m[i] > m[i+1]) ans += m[i] - m[i+1];
	printf("%d ",ans);
	
	fo(j,0,maxm)
	{
		bool ok = 1;
		fo(i,1,n-1)
		if (j < m[i] - m[i+1])
		{
			ok = 0;
			break;
		}
		if (!ok) continue;
		ans = 0;
		fo(i,1,n-1) ans += min(m[i] , j);
		break;
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("a.in","r",stdin); freopen("a.out","w",stdout);
	
	scanf("%d",&T);
	fo(tc,1,T)
	{
		printf("Case #%d: ",tc);
		Init();
		Work();
	}
	
	return 0;
}