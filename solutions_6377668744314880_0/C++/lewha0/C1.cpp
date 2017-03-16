#include<stdio.h>

long long A[20], B[20];
int D[20];
int N, T;
int BC[100000];

int CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
	long long det = x1*y2+x2*y3+x3*y1 - (y1*x2+y2*x3+y3*x1);
	if(det < 0) return -1;
	if(det > 0) return 1;
	return 0;
}

int main(void)
{
	int l0, l1, l2, l3, flag;

	BC[0] = 0;
	BC[1] = 1;
	for(l0 = 2; l0 < 100000; l0++)
	{
		if(l0 & 1) BC[l0] = BC[l0>>1] + 1;
		else BC[l0] = BC[l0>>1];
	}

	scanf("%d", &T);
	for(l0 = 1; l0 <= T; l0++)
	{
		scanf("%d", &N);
		for(l1 = 0; l1 < N; l1++) scanf("%lld %lld", &A[l1], &B[l1]);
		for(l1 = 0; l1 < N; l1++) D[l1] = N+1;

		if(N <= 3)
		{
			for(l1 = 0; l1 < N; l1++) D[l1] = 0;
		}

		for(flag = 1; flag < (1 << N); flag++)
		{
			int curr_del = N - BC[flag];
			for(l1 = 0; l1 < N; l1++)
			{
				if((flag & (1 << l1)) == 0) continue;
				if(D[l1] <= curr_del) continue;
				for(l2 = 0; l2 < N; l2++)
				{
					if(l1 == l2) continue;
					if((flag & (1 << l2)) == 0) continue;

					int side = 0;

					for(l3 = 0; l3 < N; l3++)
					{
						if(l1 == l3 || l2 == l3) continue;
						if((flag & (1 << l3)) == 0) continue;
						int curr_det = CCW(A[l1], B[l1], A[l2], B[l2], A[l3], B[l3]);
						if(curr_det == 0) continue;
						if(side == 0)
						{
							side = curr_det;
						}
						else if(side != curr_det) break;
					}

					if(l3 == N) break;
				}
				if(l2 < N) D[l1] = curr_del;
			}
		}

		printf("Case #%d:\n", l0);
		for(l1 = 0; l1 < N; l1++) printf("%d\n", D[l1]);
	}

	return 0;
}
