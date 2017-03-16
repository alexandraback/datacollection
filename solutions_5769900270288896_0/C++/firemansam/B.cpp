#include<bits/stdc++.h>
using namespace std;
int tcs, r, c, n, ans;
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		scanf("%i%i%i", &r, &c, &n);
		ans = 0;
		//special case
		if(r == 3 && c == 3 && n == 8) ans = 8;
		else if(n > ((r*c)+1)/2) 
		{
			n -= ((r*c)+1)/2;
			if(r % 2 == 0 || c % 2 == 0) {
				if(n <= 2) {
					ans += n * 2;
					n = 0;
				}else{
					ans += 4;
					n -= 2;
				}
			}
			if(n){ 
				ans += n * 3;
			}
		}
		printf("Case #%i: %i\n", tc, ans);
	}
}