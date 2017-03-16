#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long LL;

const int N = 1005;
int n , B , T;
int m[N];

void Init()
{
	scanf("%d%d",&B,&n);
	fo(i,1,B) scanf("%d",&m[i]);
}

void Work()
{
	LL L = 0 , R = LL(1e14) , ret;
	while (L <= R)
	{
		LL M = (L+R)>>1;
		LL sum(B);
		fo(i,1,B) sum += M / m[i];
		if (sum >= n) ret = M , R = M-1;else L = M+1;
	}
	
	if (!ret) printf("%d\n",n);else
	{
		LL sum(B);
		fo(i,1,B) sum += (ret-1)/m[i];
		fo(i,1,B)
		if (ret % m[i] == 0)
		{
			sum ++;
			if (sum == n)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
}

int main()
{
	freopen("b.in","r",stdin); freopen("b.out","w",stdout);
	
	scanf("%d",&T);
	fo(tc,1,T)
	{
		printf("Case #%d: ",tc);
		Init();
		Work();
	}
	
	return 0;
}