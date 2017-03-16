#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 29;

int A[MAXN],Ord[MAXN],N;

int cmp(int a,int b) {return A[a] > A[b];}

int main()
{
	freopen("data.in","r",stdin),freopen("data.out","w",stdout);
	int T;
	scanf("%d", &T);
	for(int i = 1;i <= T;i ++)
	{
		printf("Case #%d:", i);
		scanf("%d", &N);
		int sum = 0;
		for(int i = 1;i <= N;i ++) Ord[i] = i;
		for(int i = 1;i <= N;i ++) scanf("%d", &A[i]),sum += A[i];
		sort(Ord + 1,Ord + N + 1,cmp);
		while (A[Ord[1]])
		{
			if (N >= 2 && A[Ord[1]] == A[Ord[2]] && sum == A[Ord[1]] + A[Ord[2]]) 
			{
				printf(" %c%c", Ord[1] + 'A' - 1,Ord[2] + 'A' - 1);
				A[Ord[1]] --,A[Ord[2]] --;
				sum -= 2;
			} else
			{
				printf(" %c", Ord[1] + 'A' - 1);
				A[Ord[1]] --;
				sum --;
			}
			sort(Ord + 1,Ord + N + 1,cmp);
		}
		printf("\n");
	}
	return 0;
}
