#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<valarray>
using namespace std;
int t;
int b;
int n;
long long int a[100002];
long long int cnt(long long int aa){
	long long int res = 0;
	for (int i = 0; i < b; i++){
		res += aa / a[i];
		if (res>(long long int)(n)){
			return res;
		}
	}
	return res;
}
int main(){
	scanf("%d", &t);
	int tt = 0;
	while (t--){
		tt++;
		scanf("%d%d", &b, &n);
		for (int i = 0; i < b; i++){
			scanf("%lld", &a[i]);
		}
		printf("Case #%d: ", tt);
		if (b >= n){
			printf("%d\n", n);
			continue;
		}
		long long int N = n;
		N -= (long long int)(b);
		unsigned long long int maxt = LLONG_MAX;
		unsigned long long int mint = 0LL;
		while (mint + 1LL < maxt){
			long long int mid = (mint + maxt) / 2LL;
			long long int c = cnt(mid);
			if (c >= N){
				maxt = mid;
			}
			else{
				mint = mid;
			}
		}
		if (mint != maxt){
			if (cnt(mint) == N){
				maxt = mint;
			}
			else{
				mint = maxt;
			}
		}
		long long int prev = cnt(mint - 1LL);
		prev = N - prev;
		for (int i = 0; i < b; i++){
			if (mint%a[i] == 0LL){
				prev--;
				if (prev){
					continue;
				}
				printf("%d\n", i + 1);
				break;
			}
		}
	}
	return 0;
}