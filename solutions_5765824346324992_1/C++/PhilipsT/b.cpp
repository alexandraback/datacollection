#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 1005;

typedef long long LL;

int A[MAXN],Ord[MAXN],M,N;

LL Count(LL c)
{
	LL cnt = 0;
	for(int i = 1;i <= M;i ++)
		cnt += c / A[i] + 1;
	return cnt;
}

bool cmp(int a,int b)
{
	if (A[a] < A[b]) return 1;
	if (A[a] == A[b] && a < b) return 1;
	return 0;
}

void Work(int TestCase)
{
	scanf("%d%d",&M, &N);
	for(int i = 1;i <= M;i ++)
	{
		scanf("%d", &A[i]);
		Ord[i] = i; 
	}
	LL l = 0,r = 1LL << 56,tmp = r;
	while (l <= r)
	{
		LL mid = (l + r) >> 1;
		if (Count(mid) >= N) tmp = mid,r = mid - 1; else l = mid + 1;
	}
	int t = 0,c = 0;
	if (N <= M) t = N; else
	{
		N -= Count(tmp - 1);
		for(int i = 1;i <= M;i ++)
		{
			if (tmp % A[i] == 0) N --;
			if (N <= 0) {t = i;break;}
		}
	}
	printf("Case #%d: %d\n",TestCase, t);
}

int main()
{
	freopen("data.in","r",stdin),freopen("data.out","w",stdout);
	int T;
	scanf("%d", &T);
	for(int i = 1;i <= T;i ++) Work(i);
	return 0;
}
