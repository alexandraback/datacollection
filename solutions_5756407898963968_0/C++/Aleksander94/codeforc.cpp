#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>
#include <math.h>
#define int64 long long
#define ld long double
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repd(i,a,b) for (int i = a; i >= b; i--)
#define mp make_pair

using namespace std;

const int N = 300000;
const int inf = 1000000000;


int a1[10][10], a2[10][10], a[17];

int main()
{
/*#ifdef _DEBUG
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
//#ifndef _DEBUG
	freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
//#endif
	int q;
	scanf("%d", &q);
	rep(ii,1,q)
	{
		int c1, c2;
		scanf("%d", &c1);
		rep(i,1,4)
			rep(j,1,4) scanf("%d", &a1[i][j]);
		scanf("%d", &c2);
		rep(i,1,4)
			rep(j,1,4) scanf("%d", &a2[i][j]);
		rep(i,1,16) a[i] = 0;
		rep(i,1,4) a[a1[c1][i]]++;
		rep(i,1,4) a[a2[c2][i]]++;
		int k = 0;
		int ans = 0;
		rep(i,1,16)
			if (a[i] == 2) 
			{
				k++;
				ans = i;
			}
		printf("Case #%d: ", ii);
		if (k == 1) printf("%d", ans);
		else if (k > 1) printf("Bad magician!");
		else printf("Volunteer cheated!");
		if (ii != q) printf("\n");
	}
	return 0;
}