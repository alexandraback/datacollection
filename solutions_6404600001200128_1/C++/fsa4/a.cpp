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

int n, arr[1010];

int main(){
	int t, caso = 1;
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		int maior = 0;
		fr(i, 0, n){
			scanf("%d", &arr[i]);
			maior = max(maior, arr[i]);
		}
		
		int ans1 = 0, ans2 = inf;
		fr(i, 1, n){
			if(arr[i-1] > arr[i]) ans1 += arr[i-1]-arr[i];
		}
		
		fr(x, 0, maior+1){
			int temp = 0, ok = 1;
			fr(i, 1, n){
				int at = arr[i-1];
				at -= x;
				if(at < 0) at = 0;
				if(at > arr[i]){
					ok = 0;
					break;
				}
				
				temp += arr[i-1] - at; 
			}
			
			if(ok) ans2 = min(ans2, temp);
		}
		
		printf("Case #%d: %d %d\n", caso++, ans1, ans2);
	}

	return 0;
}

