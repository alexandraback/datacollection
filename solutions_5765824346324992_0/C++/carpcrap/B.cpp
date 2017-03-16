#include <iostream>

using namespace std;

long long m[2000];
int ava[2000];
int main()
{
	int T;
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		int maxRate = 0;
		int B;
		long long N;
		cin >> B >> N;
		for(int i =1; i<=B; i++)
		{
			cin >> m[i];
			if(m[i] > maxRate) maxRate = m[i];
		}
		
		int pos = 1;
		long long minn = 0;
		long long maxx = maxRate * N;
		long long mid = (minn + maxx)/2;
		// calc number
		long long cnt =0;
		int free = 0;
//printf("%d max: %lld, minn: %lld, cnt: %lld, free: %d, N: %lld\n", t, maxx, minn, cnt, free,N);
		while(cnt>=N || cnt+free < N)
		{
			cnt = 0;
			pos = -1;
			free = 0;
			for(int i=1; i<=B; i++)
			{
				cnt += mid / m[i];
				if(mid%m[i] == 0)
				{
					free++;
					ava[free] = i;
				}else{
					cnt++;
				}
			}
			if(cnt >= N) maxx=mid;
			else minn = mid;
			mid = (minn + maxx)/2;
//printf("%d max: %lld, minn: %lld, cnt: %lld, free: %d\n", t, maxx, minn, cnt, free);
		}

		pos = ava[N-cnt];
		printf("Case #%d: %d\n", t, pos); 
	}
}
