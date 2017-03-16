#include <iostream>

using namespace std;

int p[2000];
int main()
{
	int T;
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		int N;
		cin >> N;
		for(int i=0; i<N; i++) cin >> p[i];

		int down = 0;
		int minRate = 0;
		for(int i=1; i<N; i++)
		{
			if (p[i] < p[i-1]) down += p[i-1] - p[i];
			if (minRate < p[i-1] - p[i])
				minRate = p[i-1] - p[i];
		}
		int cum = 0;
		for(int i=0;i<N-1;i++)
		{
			cum += (minRate < p[i]) ? minRate : p[i];
		}
		
		printf("Case #%d: %d %d\n", t, down, cum); 
	}
}
