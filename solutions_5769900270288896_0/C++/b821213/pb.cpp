#include <stdio.h>
#include <algorithm>

int getans(int k, int zero, int two, int three){
	int ans = 0;
	if( k > 0 ){
		if( k <= zero ) 
			ans += k * 0;
		else
			ans += zero * 0;
	}
	k -= zero;
	if( k > 0 ){
		if( k <= two )	
			ans += k * 2;
		else
			ans += two * 2;
	}
	k -= two;
	
	if( k > 0 ){
		if( k <= three )
			ans += k * 3;
		else
			ans += three * 3;
	}
	k -= three;
	
	if( k > 0 )
		ans += k * 4;
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		int n, m, k;
		scanf("%d %d %d",&n,&m,&k);
		int zero, two, three, ans;
		//case 0: n = 1 or m = 1
		if ( n == 1 || m == 1 ){
			if( n != 1 )
				std::swap(n,m);
			int zero = m % 2 ? m / 2 + 1 : m / 2;
			int one = m % 2 ? 0 : 1;
			if( k <= zero ) ans = 0;
			k -= zero;
			if( k > 0 && k <= one ) ans = k * 1;
			else if( k > 0 ){
				ans = one * 1;
				k -= one;
				if( k > 0 )
					ans += k * 2;
			}
		}
		//case 1: even, even
		else if( n % 2 == 0 && m % 2 == 0 ){
			zero = n/2 * m;
			two = 2;
			three = n + m - 4;
			ans = getans(k,zero,two,three);
		}
		//case 2: odd, odd
		else if( n % 2 == 1 && m % 2 == 1 ){
			zero = (n/2+1) * (m/2+1) + (n/2) * (m/2);
			two = 0;
			three = (n/2)*2 + (m/2)*2;
			ans = getans(k,zero,two,three);
			zero = n * m / 2;
			two = 4;
			three = (n/2+1)*2 + (m/2+1)*2 - 8;
			ans = std::min(ans, getans(k,zero,two,three));
		}
		//case 3: odd, even
		else {
			if( n % 2 == 0 ) std::swap(n,m);
			//n is odd, m is even
			zero = n * m / 2;
			two = 2;
			three = m + n - 4;
			ans = getans(k,zero,two,three);
		}
		//printf("%d %d %d\n", zero, two, three);
		printf("Case #%d: %d\n", t, ans);
	}	
	return 0;
}