#include <bits/stdc++.h>
#define fr(i, a, b) for(int i = (a), __ = (b); i < __; i++)
#define inf 0x3f3f3f3f
#define st first
#define pb push_back
#define nd second
#define eps 1e-9

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, b, arr[1010], qtd;
ll m[1010];

int main(){
	int t, caso = 1;
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &b, &n);
		fr(i, 0, b) scanf("%lld", &m[i]);
		int ans;
		
		ll ini = 0, fim = 10000000000000000LL;
		while(ini <= fim){
			ll mid = (ini+fim)/2;
			ll cont = 0;
			qtd = 0;
			
			fr(i, 0, b){
				if(mid % m[i] == 0){
					cont += mid/m[i];
					arr[qtd++] = i;
				}else cont += mid/m[i] + 1;
			}
			
			if(cont+qtd < n){
				ini = mid+1;
			}else if(cont >= n){
				fim = mid-1;
			}else{
				ans = arr[n-cont-1];
				break;
			}
		}
		
		printf("Case #%d: %d\n", caso++, ans+1);
	}

	return 0;
}

