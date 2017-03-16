#include <iostream>

using namespace std;

long long x[4000];
long long y[4000];
int main()
{
	int T;
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		printf("Case #%d:\n", t); 
		int N;
		cin >> N;
		for(int i=0; i<N; i++)
			cin >> x[i] >> y[i];
		int minn = N;
		int pos, neg;
		long long product;
		for(int i=0; i<N; i++)
		{
			minn = (N>2)?N-2:0;
			for(int j=0; j<N; j++)
			{
				if(j==i) continue;
				pos = neg = 0;
				for(int k=0; k<N; k++)
				{
					product = ((x[j] - x[i]) * (y[k] - y[i]) - (y[j] - y[i]) * (x[k] - x[i]));
					if(product > 0) pos++;
					if(product < 0) neg++;
				}
				if(minn > pos) minn = pos;
				if(minn > neg) minn = neg;
			}
			printf("%d\n", minn);
		}
	}
}
