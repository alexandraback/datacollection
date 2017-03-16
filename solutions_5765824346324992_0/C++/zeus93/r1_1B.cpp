#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define LL long long
#define M 100005

LL val[M];

int B;
LL n;
int bin(LL tl, LL tr){
	while(tl <= tr){
	//	printf("%lld %lld\n", tl, tr);
		LL num1 = 0, num2 = 0;
		LL tmid = (tl + tr) >> 1;
		for(int i = 0; i < B; i++){
			num1 += (tmid / val[i]);
			if(tmid % val[i] != 0){
				num1 += 1;
			}
		}
		for(int i = 0; i < B; i++){
			num2 += ((tmid + 1) / val[i]);
			if((tmid + 1) % val[i] != 0){
				num2 += 1;
			}
		}
		if(num1 < n && num2 >= n){
			for(int i = 0; i < B; i++){
				if((tmid % val[i]) == 0){
					num1++;
					if(num1 == n){
						return i;
					}
				}
			}
		}
		else if(num1 < n){
			tl = tmid + 1;
		}
		else{
			tr = tmid - 1;
		}
	//	printf("%lld %lld\n", num1, num2);
	}
	return -1;
}
int main(){
	int t;
	scanf("%d", &t);
	for(int id = 1; id <= t; id++){
		scanf("%d%lld", &B, &n);
		LL r = 1000000;
		for(int i = 0; i < B; i++){
			scanf("%lld", &val[i]);
			if(val[i] < r){
				r = val[i];
			}
		}
		printf("Case #%d: ", id);
		if(n <= B){
			printf("%lld\n", n);
			continue;
		}
		printf("%d\n", bin(0, n * r) + 1);
	}
	return 0;
}
