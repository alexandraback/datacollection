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

int a[11111];
int n, m;

LL check1(LL x){
	LL ans = 0;
	for (int i = 1; i <= n; i++){
		ans += x / a[i] + 1;
		if (x % a[i] == 0) ans --;
	}
	return ans;
}

LL check2(LL x){
	LL ans = 0;
	for (int i = 1; i <= n; i++){
		ans += x / a[i] + 1;
	}
	return ans;
}

int main(){

	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	int casenum, hh, cur;
	LL l, r, mid;
	LL u1, d1;
	scanf("%d", &casenum);
	for (int z = 1; z <= casenum; z++){
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		l = 0; r = 1000000000000001;
		while (l < r){
			//cout << l <<  "   " << r << endl;
			mid = (l + r) / 2;
			d1 = check1(mid);
			u1 = check2(mid);

			//cout << " " << d1 <<  "   " << u1 << endl;
			if (u1 < m) l = mid + 1;
			else if (d1 >= m) r = mid;
			else break;
		}
		cur = d1;
		//cout << mid << endl;
		for (int i = 1; i <= n; i++){
			if (mid % a[i] == 0) cur++;
			if (cur == m){
				hh = i;
				break;
			}
		}
		printf("Case #%d: %d\n", z, hh);
	}

 	return 0;
	
 	fclose(stdin);
 	fclose(stdout);

}