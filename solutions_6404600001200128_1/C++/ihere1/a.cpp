#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;
int TT;
int n;
const int N = 1010;
int a[N];
int main() {
	scanf("%d", &TT);
	for(int rr = 1; rr<=TT; ++rr){
		scanf("%d", &n);
		for(int i=0; i<n; ++i){
			scanf("%d", a+i);
		}
		int maxx = 0, ans1 = 0, ans2 = 0;
		for(int i=1; i<n; ++i){
			if(a[i] < a[i-1]){
				maxx = max(maxx, a[i-1]-a[i]);
				ans1 += a[i-1] - a[i];
			}
		}
		for(int i=1; i<n; ++i){
			if(a[i-1] < maxx) ans2 += a[i-1];
			else ans2 += maxx;
		}
		printf("Case #%d: %d %d\n", rr, ans1, ans2);
	}
	return 0;
}

