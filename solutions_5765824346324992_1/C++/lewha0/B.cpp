#include<stdio.h>

int T, N;
long long A[1000];
long long M;
int IDX;

long long Go(long long curr_time)
{
	int l1;
	long long ret = 0;

	for(l1 = 0; l1 < N; l1++)
	{
		ret += curr_time / A[l1];
		if(curr_time % A[l1]) ret++;
		else
		{
			if(l1 < IDX) ret++;
		}
	}

	return ret;
}

int main(void)
{
	int l0, l1, l2;

	scanf("%d", &T);
	for(l0 = 1; l0 <= T; l0++)
	{
		scanf("%d %lld", &N, &M);
		for(l1 = 0; l1 < N; l1++) scanf("%lld", &A[l1]);

		for(l1 = 0; l1 < N; l1++)
		{
			long long left = 1, right = M+1;
			IDX = l1;

			while(left < right)
			{
				long long mid = (left + right) / 2;

				long long done = Go((mid - 1) * A[l1]);

				if(done == M-1) break;
				else if(done > M-1) right = mid-1;
				else left = mid+1;
			}

			{
				long long mid = (left + right) / 2;
				long long done = Go((mid - 1) * A[l1]);
				if(done == M-1) break;
			}
		}

		printf("Case #%d: %d\n", l0, l1+1);
	}
	return 0;
}
