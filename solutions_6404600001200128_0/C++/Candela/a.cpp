#include <algorithm>
#include <bitset>
#include <cmath> 
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define FT first
#define SD second
#define VI vector<int> 
#define MII map<int,int>
#define SI set<int>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long LL;
typedef long double LD;
const int INF = 0x7FFFFFFF;
const LL LINF = 0x7FFFFFFFFFFFFFFFll;

using namespace std;

int a[1111];

int main(){

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int casenum, hh1, hh2, maxn, n;
	scanf("%d", &casenum);
	for (int z = 1; z <= casenum; z++){
		scanf("%d", &n);
		hh1 = 0; hh2 = 0; maxn = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		for (int i = 1; i < n; i++){
			if (a[i] < a[i - 1]){
				hh1 += a[i - 1] - a[i];
				maxn = max(maxn, a[i - 1] - a[i]); 
			}
		}
		for (int i = 0; i < n - 1; i++){
			hh2 += min(maxn, a[i]);
		}
		printf("Case #%d: %d %d\n", z, hh1, hh2);
	}

 	fclose(stdin);
 	fclose(stdout);
	
}