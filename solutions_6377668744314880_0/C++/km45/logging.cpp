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
	int X[3000];
	int Y[3000];
	
	for (int i = 1; i <= T ; i ++){
	
		scanf("%d", &N);
		
		for (int j = 0; j < N; j++){
			scanf("%d", &X[j]);
			scanf("%d", &Y[j]);
		}

		printf("Case #%d:\n", i);
		
		if (N == 1) printf("%d\n", 0);
		else {
		int log[N];
		int sign;	
		int result;
		int res;  
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				if (k == j) continue;
				int left = 0;
				int right = 0;
				for (int m = 0; m < N; m++){
					double pos = ((X[k]-X[j])/100.0)*((Y[m]-Y[j])/100.0) - ((Y[k]-Y[j])/100.0)*((X[m]-X[j])/100.0);
					if (pos < 0) left++;
					if (pos > 0) right++;
				}
				result = min(left, right);
				if ((k == 0) || ((j==0)&&(k==1))) log[j] = result;	
				else log[j] = min(log[j], result);
			}
			printf("%d\n", log[j]);
		}
		}
	
	}
	
}
