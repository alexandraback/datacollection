#include <bits/stdc++.h>
using namespace std;

#define fo(x,y,z) for(int x=y;x<z;x++)
int tc;

int main(){
	scanf("%d", &tc);
	fo(x,1,tc+1){
		printf("Case #%d:", x);
		int n;
		scanf("%d", &n);
		pair<int,char> a[30];
		fo(i,0,n){
			int b;
			scanf("%d", &b);
			a[i] = {b,i+'A'};
		}
		sort(a,a+n);
		while(a[n-1].first > a[n-2].first){
			printf(" %c", a[n-1].second);
			a[n-1].first--;
		}
		fo(i,0,n-2){
			fo(j,0,a[i].first) printf(" %c", a[i].second);
		}
		fo(i,0,a[n-2].first){
			printf(" %c%c", a[n-2].second,a[n-1].second);
		}
		printf("\n");
	}
	return 0;
}
