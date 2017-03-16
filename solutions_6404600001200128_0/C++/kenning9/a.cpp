#include<cstdio>
#include<iostream>
using namespace std;
int n, TC, p[100000];
int mthchoice(){
	int ans = 0;
	for(int i = 1; i < n; ++i){
		ans += max(0, p[i-1] - p[i]);
	}
	return ans;
}
int mthconstant(){
	int ans = 0, dec = 0;
	for(int i = 1; i < n; ++i) dec = max(dec, p[i-1] - p[i]);
	for(int i = 1; i < n; ++i){
		if(p[i-1] < dec) ans += p[i-1];
		else ans += dec;
	}
	return ans;
}
int main(){
	scanf("%d", &TC);
	for(int tc = 1; tc <= TC; ++tc){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf("%d", &p[i]);
		printf("Case #%d: %d %d\n", tc, mthchoice(), mthconstant());
	}
}