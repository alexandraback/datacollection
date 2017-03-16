#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 10005

int val[N];

int main(){
	int t, n;
	scanf("%d", &t);
	for(int id = 1; id <= t; id++){
		scanf("%d", &n);
		int n1 = 0, n2 = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &val[i]);
		}
		int max = 0;
		for(int i = 1; i < n; i++){
			if(val[i] < val[i - 1]){
				n1 += (val[i - 1] - val[i]);
				max = max < val[i - 1] - val[i] ? val[i - 1] - val[i] : max;
			}
		}
		for(int i = 0; i < n - 1; i++){
			if(val[i] < max){
				n2 += val[i];
			}
			else{
				n2 += max;
			}
		}
		printf("Case #%d: %d %d\n", id, n1, n2);
	}
	return 0;
}
