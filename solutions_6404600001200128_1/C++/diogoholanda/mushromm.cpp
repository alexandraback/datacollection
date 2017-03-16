#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int T, u, N, resp1, resp2, maximo;
int v[1010];

int main(){
	scanf(" %d", &T);
	u=0;
	while(u<T){
		u++;
		scanf(" %d", &N);
		for(int i=0; i<N; i++){
			scanf(" %d", &v[i]);
		}
		resp1 = 0;
		resp2 = 0;
		maximo = 0;
		for(int i=1; i<N; i++){
			if(v[i] < v[i-1]) {
				resp1 += v[i-1]-v[i];
				if(v[i-1]-v[i] > maximo){
					maximo = v[i-1]-v[i];
				}
			}
		}
		
		for(int i=0; i<N-1; i++){
			resp2 += min(maximo, v[i]);
		}
		printf("Case #%d: %d %d\n", u, resp1, resp2);
	}
	return 0;
}
