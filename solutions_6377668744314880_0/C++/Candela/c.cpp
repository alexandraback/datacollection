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

class coor{
public:
	int x, y;
};

coor a[11111];
int n, m, tmp, tmp1, tmp2;
double yy, kk, bb;

int main(){

	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	int casenum, hh;
	scanf("%d", &casenum);
	for (int z = 1; z <= casenum; z++){
		printf("Case #%d:\n", z);
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		for (int i = 0; i < n; i++){
			hh = INF;
			for (int j = 0; j < n; j++){
				tmp1 = 0; tmp2 = 0;
				if (a[i].x == a[j].x){
					for (int k = 0; k < n; k++){
						if (a[k].x < a[i].x) tmp1++;
						if (a[k].x > a[i].x) tmp2++;
					}
				}
				else if (a[i].y == a[j].y){
					for (int k = 0; k < n; k++){
						if (a[k].y < a[i].y) tmp1++;
						if (a[k].y > a[i].y) tmp2++;
					}
				}
				else{
					kk = 1.0 * (a[i].y - a[j].y) / (a[i].x - a[j].x);
					bb = a[i].y - a[i].x * kk;
					for (int k = 0; k < n; k++){
						yy = a[k].x * kk + bb;
						if (abs(yy - a[k].y) < 0.0000001) continue;
						if (a[k].y < yy) tmp1++;
						if (a[k].y > yy) tmp2++;
					}
				}
				tmp = min(tmp1, tmp2);
				hh = min(hh, tmp);
			}
			printf("%d\n", hh);
		}
	}

 	return 0;
	
 	fclose(stdin);
 	fclose(stdout);

}