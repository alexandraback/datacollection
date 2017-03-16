#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}


int main()
{
	int T;
	scanf("%d", &T);
	int N;
	int M[1000];
	int B;
	
	for (int i = 1; i <= T ; i ++){
	
		scanf("%d", &B);
		scanf("%d", &N);
		
		for (int j = 0; j < B; j++){
			scanf("%d", &M[j]);
		}
		

		int g;
		int l;
		if (B == 1) g = M[0];
		else {
			g = gcd(M[0], M[1]);
			l = M[0]*M[1] / g;
			for (int j = 2; j < B; j++){
				g = gcd(l, M[j]);
				l = l * M[j] / g; 	
			}	
		}
		int period = 0;
		for (int j = 0; j < B; j++){
			period = period + l / M[j];
		}

		while (N > period)
			N = N - period;
					
		int min_index = 0; 
		if (N <= B) min_index = N;
		else{
			int current[5];
			for (int j = 0; j < B; j++){
					current[j] = M[j];
			}
			N = N - B;
			while (N > 0){
				
				min_index = 0;
				int min = current[0];
				for (int j = 0; j < B ; j++){
					if (current[j] < min) {
						min = current[j];
						min_index = j;
					}
				}
		
				for (int j = 0 ; j < B ; j++)
					current[j] = current[j] - min;
			
				current[min_index] = M[min_index];
		
				N--;
			}
			min_index = min_index + 1;
		}
		
	
		printf("Case #%d: %d\n", i, min_index);
	}
	
}
