#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	int N;
	int M[1000];
	
	
	for (int i = 1; i <= T ; i ++){
	
		scanf("%d", &N);
		
		for (int j = 0; j < N; j++){
			scanf("%d", &M[j]);
		}
		
		
		long long int sum = M[0];			
		for (int j = 1; j < N ; j++){
			if (M[j] > M[j-1])
				sum = sum + (M[j]-M[j-1]);
		}		
		sum = sum - M[N-1];

		int max_difference = 0;
		for (int j = 1; j < N; j++){
			if (M[j-1] - M[j] > max_difference)
				max_difference = M[j-1]-M[j];
		}
		
		
		long long int sum2 = M[0];	
		for (int j = 1; j < N ; j++){
			int left = max(M[j-1] - max_difference, 0);
			sum2 = sum2 + M[j] - left;
		}
		sum2 = sum2 - M[N-1];

		printf("Case #%d: %lld %lld\n", i, sum, sum2);
	}
	
}
