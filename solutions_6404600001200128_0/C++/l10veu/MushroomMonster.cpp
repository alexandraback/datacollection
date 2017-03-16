#include <cstdio>
#include <algorithm>

int N;
int mushrooms[1010];

int First()
{
	int count= 0;
	for (int i=0; i+1<N; ++i)
	{
		if (mushrooms[i+1]<mushrooms[i])
			count += mushrooms[i] - mushrooms[i+1];
	}
	
	return count;
}

int Second()
{
	int maxCount = 0;
	for (int i=0; i+1<N; ++i)
	{
		if (mushrooms[i+1]<mushrooms[i] && mushrooms[i] - mushrooms[i+1] > maxCount)
			maxCount = mushrooms[i] - mushrooms[i+1];
	}

	int count = 0;
	for (int i=0; i<N-1; ++i)
	{
		count += std::min(maxCount, mushrooms[i]);
	}
	
	return count;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc=1; tc<=t; ++tc)
	{
		scanf("%d", &N);
		for (int i=0; i<N; ++i)
			scanf("%d", &mushrooms[i]);

		printf("Case #%d: %d %d\n", tc, First(), Second());
	}
	
	return 0;
}