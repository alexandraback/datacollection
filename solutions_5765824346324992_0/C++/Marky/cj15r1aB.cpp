#include<cstdio>
long long gcd(long long a, long long b){
	return b == 0 ? a : gcd(b, a%b);
}
#define LCM(a, b) ((a)*(b)/gcd((a),(b)))
int main(){
	int t;
	scanf("%i",&t);
	for(int i=1; i <= t; i++){
		int b, n, m[1000];
		scanf("%i%i",&b,&n);
		for(int j=0; j<b; j++)
			scanf("%i", m+j);
		long long lcm = m[0], speed=0;
		for(int j=1; j<b; j++)
			lcm = LCM(lcm, m[j]);
		for(int j=0; j<b; j++)
			speed += lcm/m[j];
		n %= speed;
		if(n==0) n = (int)speed;
		long long time[1000]={0};
		int mindex=0;
		while(n--){
			mindex=0;
			for(int j=1; j<b; j++)
				if(time[j] < time[mindex])
					mindex = j;
			time[mindex] += m[mindex];
		}
		printf("Case #%i: %i\n", i, 1+mindex);
	}
}