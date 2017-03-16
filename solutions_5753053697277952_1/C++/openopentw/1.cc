#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;	scanf("%d", &T);
	for(int t = 0; t < T; ++t) {
		printf("Case #%d: ", t + 1);
		
		int N;	scanf("%d", &N);
		// vector<int> P(32);
		int P[32];
		int sum = 0;
		for(int i = 0; i < N; ++i) {
			scanf("%d", &P[i]);
			sum += P[i];
		}
		
		if(sum % 2) {		// notice only one person
			// printf("%d ", *max_element(P.begin(),P.end()));
			printf("%c ", max_element(P, P + N) - P + 'A');
			--(*max_element(P, P + N));
		}
		
		int s = sum / 2;
		for(int i = 0; i < s; ++i) {
			int two = 2;
			while(two--) {
				printf("%c", max_element(P, P + N) - P + 'A');
				--(*max_element(P, P + N));
			}
			putchar(' ');
			
			// puts("");
			// puts("====debug====");
			// for(int j = 0; j < N; ++j)
				// printf("%d ", P[i]);
			// puts("");
			// puts("====debug====");
			
		}
		
		puts("");
	}
	return 0;
}
