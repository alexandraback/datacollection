#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

typedef pair<int, int> ii;

int main(void)
{
	int t, B, N;
	scanf("%d", &t);

	for(int rep =1;rep <= t;rep++)
	{
		scanf("%d%d", &B, &N);
		int M[B];
		for(int i = 0;i < B;i++) scanf("%d", &M[i]);

		if(B >= N)
			printf("Case %d: %d\n", rep, N);

		else
		{
			set<ii> barbers;
			for(int i = 0;i < B;i++)
			{
				barbers.insert(ii(M[i], i+1));
			}
			ii top;
			for(int i = B;i < N-1;i++)
			{
				top = *barbers.begin();
				barbers.erase(barbers.begin());
				barbers.insert(ii((top.first+M[top.second-1]), top.second));
			}

			top = *barbers.begin();
			printf("Case #%d: %d\n", rep, top.second);
		}
	}
}