#include <cstdio>
#include <algorithm>
#include <vector>

int B, N;
int barbers[1010];
int waiting[1010];

int Solve()
{
	for (int i=0; i<B; ++i)
		waiting[i] = 0;

	std::vector<int> myBarbers;

	for (int i=0; i<N; ++i)
	{
		int here = -1;
		for (int j=0; j<B; ++j)
		{
			if (waiting[j] == 0)
			{
				here = j;
				break;
			}
		}

		if (here == -1)
		{
			int minWaiting = *std::min_element(waiting, waiting+B);
			bool isAllAvailable = true;
			for (int j=0; j<B; ++j)
			{
				waiting[j] -= minWaiting;
				if (here == -1 && waiting[j] == 0)
					here = j;

				if (waiting[j]>0)
					isAllAvailable = false;
			}

			if (isAllAvailable)
				break;
		}

		waiting[here] = barbers[here];
		myBarbers.push_back(here);
	}

	return myBarbers[(N-1)%myBarbers.size()] + 1;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc=1; tc<=t; ++tc)
	{
		scanf("%d %d", &B, &N);
		for (int i=0; i<B; ++i)
			scanf("%d", &barbers[i]);

		printf("Case #%d: %d\n", tc, Solve());
	}
	
	return 0;
}