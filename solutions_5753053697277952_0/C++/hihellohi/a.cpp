#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int u = 0; u < t; u++) {
		printf("Case #%d: ",u+1);	
		int n;
		scanf("%d", &n);
		int num[30];
		for(int i = 0; i < n; i++){
			scanf("%d",num+i);
		}
		int m = n;
		while(m > 2) {
			int highest = 0, a = 0;
			for(int j = 0; j < n; j++){
				if(num[j] > highest) {
					highest = num[j];
					a = j;
				}
			}
			num[a]--;
			printf("%c ", 'A'+a);
			if(!num[a]){
				m--;
			}
		}
		int left = 0, a = 0, b = 0;
		for(int j = 0; j < n; j++){
			if(num[j]){
				left = num[j];
				if(a){
					b = j;
				}else{
					a = j;
				}
			}
		}
		for(int j = 0; j < left; j++){
			printf("%c%c ",'A' + a,'A' + b);
		}
		printf("\n");
	}
}

