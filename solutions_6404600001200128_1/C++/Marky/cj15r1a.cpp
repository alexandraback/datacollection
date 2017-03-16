#include<cstdio>
int main(){
	int t;
	scanf("%i",&t);
	for(int i=1; i <= t; i++){
		int n, m[10000];
		scanf("%i",&n);
		for(int j=0; j<n; j++)
			scanf("%i", m+j);
		int a=0, speed=0;
		for(int j=1; j<n; j++){
			int delta = m[j] - m[j-1];
			if(delta < 0){
				a += -delta;
				if(-delta > speed)
					speed = -delta;
			}
		}
		int b=0;
		for(int j=0; j < n-1; j++)
			if(m[j] > speed)
				b += speed;
			else b += m[j];
		printf("Case #%i: %i %i\n", i, a, b);
	}
}