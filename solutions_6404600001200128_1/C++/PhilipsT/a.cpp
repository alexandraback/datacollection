#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 1005;
typedef long long LL;
int A[MAXN],N;

void Work(int TestCase)
{
	scanf("%d", &N);
	for(int i = 1;i <= N;i ++) scanf("%d", &A[i]);
	LL Aleast = 0,Bleast = 1 << 30;
	for(int i = 1;i <= N;i ++)
		if (A[i] < A[i - 1]) Aleast += A[i - 1] - A[i];
	for(int rate = 0;rate <= 10000;rate ++)
	{
		bool ok = 1;LL cur = 0;
		LL least = 0;
		for(int i = 1;i <= N;i ++)
		{
			if (A[i] < least) {ok = 0;break;}
			if (i == N) break;
			cur += min(A[i],rate);
			least = A[i] - min(A[i],rate);
		}
		if (ok) Bleast = min(Bleast,cur);
	}
	printf("Case #%d: %I64d %I64d\n",TestCase, Aleast, Bleast);
}

int main()
{
	//freopen("data.in","r",stdin),freopen("data.out","w",stdout);
	int T;
	scanf("%d", &T);
	for(int i = 1;i <= T;i ++) Work(i);
	return 0;
}
