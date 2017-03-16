#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>

#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <utility>
#include <numeric>

using namespace std;

#ifdef LUNAWYLL
#define dbg(x) cout << #x << " = " << (x) << endl;
#define dbg2(a, b) cout << #a << " = " << (a) << "; " <<\
	#b << " = " << (b) << endl;
#else
#define dbg(x) (void(0));
#define dbg(x) (void(0));
#endif

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;


void task();

int main(){
#ifdef LUNAWYLL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	task();

#ifdef LUNAWYLL
	cout << "\n==================\n";
	cout << fixed << setprecision(3) << (double)clock() / CLOCKS_PER_SEC << "ms" << endl;
#endif
	return 0;
}
const int INF = (int)1e9;

bool a[20][20];

int check(int a){
	int res = 0;
	for (int i = 0; i < 16; ++i)
		res += (a & (1 << i)) != 0;
	return res;
}
int r, c, n;
void set_b(int num){
	for (int i = 0; i < r; ++i)
	for (int j = 0; j < c; ++j){
		int tmp = num & (1 << i*c + j);
		if ((num & (1 << i*c + j)) != 0){
			a[i][j] = 1;
		}
	}
}

void task(){
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k){
		
		scanf("%d %d %d", &r, &c, &n);
		int ans = 100500;
		for (int mask = 0; mask < (1 << r*c); ++mask){
			int b = check(mask);
			if (check(mask) != n){
				continue;
			}
			set_b(mask);
			int tans = 0;
			for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j){
				if (a[i][j] == 1){
					if (i + 1 < r && a[i + 1][j] == 1)
						++tans;
					if (j + 1 < c && a[i][j + 1] == 1)
						++tans;
				}
			}
			fill(a[0], a[0] + 20*20, 0);
			ans = min(ans, tans);
		}
		printf("Case #%d: %d\n", k, ans);
	}
	
}