#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd ( ll a, ll b ){
  ll c;
  while ( a != 0 ) {
     c = a;
     a = b % a; 
     b = c;
  }
  return b;
}
ll lcm (ll a, ll b){
	return (a*b)/gcd(a,b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll t, test; scanf("%lld",&test);
	for (ll t = 0; t < test; t++){
		ll b,n,res=-1; scanf("%lld %lld", &b, &n);
		ll a[b+1],i,l;
		for (i = 0; i < b; i++) scanf("%lld", &a[i]);
		l = a[0];
		for (i = 1; i < b; i++) l = lcm(l, a[i]);
		
		if (n <= b) res = n;
		else{
			ll nc = 0;
			ll temp[b+1],j;
			for (i=0; i<b; i++) temp[i] = 0;
			for (i = 1; i <= l; i++){
				for (j = 0; j < b; j++){
					if (temp[j] == 0){
						nc++;
						temp[j] = a[j];
					}
					temp[j]--;
				}
			}
			n %= nc;
			if (n == 0) n = nc;
			ll cnt = 0;
			ll found = 0;
			for (i=0; i<b; i++) temp[i] = 0;
			for (i = 1; i <= l && !found; i++){
				for (j = 0; j < b && !found; j++){
					if (temp[j] == 0){
						cnt++;
						if (cnt == n){ res = j+1; found=1; break;}
						temp[j] = a[j];
					}
					temp[j]--;
				}
			}
		}
		if (res == -1) printf("asjkdhkjsahdkjsadhkjsah");
		printf("Case #%lld: %lld\n",t+1,res);
	}
	return 0;
}
