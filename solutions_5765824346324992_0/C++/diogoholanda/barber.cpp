#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int T, u, B, resp;
long long int N;
long long int v[1010];

long long int f(long long int a){
	if(a<0) return 0;
	long long int ret = 0;
	for(int i=0; i<B; i++){
		ret += a/v[i] + 1LL;
	}
	return ret;
}

bool p(long long int a){
	return f(a) >= N;
}

long long int bb(long long int lo, long long int hi){
  long long int mid;
  while (lo<hi){
    mid=lo+(hi-lo)/2LL;
    if (p(mid)) hi=mid;
    else lo=mid+1LL;
  }
  return lo;
}

int main(){
	scanf(" %d", &T);
	u=0;
	while(u<T){
		u++;
		scanf(" %d %lld", &B, &N);
		for(int i=0; i<B; i++){
			scanf(" %lld", &v[i]);
		}

		long long int t = bb(0LL, 4000000000000000LL);
		long long int before = f(t-1LL);
		for(int i=0; i<B; i++){
			if(t%v[i] == 0){
				before++;
				if(before == N){
					resp = i+1;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", u, resp);
	}
	return 0;
}
