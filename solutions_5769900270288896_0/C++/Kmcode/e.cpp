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
//#include<bits/stdc++.h>
using namespace std;
int t;
/*int __builtin_popcount(int a){
	int r = 0;
	while (a){
		r += a & 1;
		a >>= 1;
	}
	return r;
}*/
int x[] = { 0, 0, 1, -1 };
int y[] = { 1, -1, 0, 0 };
int room[20][20];
int a, b;
int n;
int solve(int aa){
	if (__builtin_popcount(aa) != n){
		return INT_MAX;
	}
	for (int i = 0; i < a; i++){
		for (int j = 0; j < b; j++){
			room[i][j] = aa & 1;
			aa >>= 1;
		}
	}
	int countt = 0;
	for (int i = 0; i < a; i++){
		for (int j = 0; j < b; j++){
			for (int k = 0; k < 4; k++){
				int ii = i + x[k];
				int jj = j + y[k];
				if (ii >= 0 && jj >= 0){
					if (room[i][j] && room[ii][jj]){
						countt++;
					}
				}
			}
		}
	}
	countt /= 2;
	return countt;
}
int main(){
	scanf("%d", &t);
	int ca = 0;
	while (t--){
		memset(room, 0, sizeof(room));
		ca++;
		cout << "Case #" << ca << ": ";
		scanf("%d%d%d", &a, &b, &n);
		int siz = a*b;
		int ans = INT_MAX;
		for (int i = 0; i < (1 << siz); i++){
			ans = min(ans, solve(i));
		}
		printf("%d\n", ans);
	}
	return 0;
}