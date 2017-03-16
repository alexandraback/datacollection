#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include <string>

#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define println(X) printf("%d\n",(X))
#define PB push_back
#define MP make_pair
using namespace std;
int input[2000];
int main(){
	freopen("mushrooms.in", "r", stdin);
	freopen("mushrooms.out", "w", stdout);
	DRI(T);
	
	for (int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		DRI(N);
		for (int i = 0; i < N; i++){
			cin >> input[i];
		}
		int ans1 = 0;
		int rate = 0;
		for (int i = 0; i < N - 1; i++){
			if (input[i + 1] < input[i]){
				ans1 += input[i] - input[i + 1];
				rate = max(rate, input[i] - input[i + 1]);
			}
		}
		int ans2 = 0;
		for (int i = 0; i < N-1; i++){
			ans2 += min(rate, input[i]);
		}
		cout << ans1 << " " << ans2 << "\n";
	}
	return 0;
}