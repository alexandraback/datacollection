#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <stack>
#include <string>

using namespace std;


int T, N, n;
int cas;

// P為平面上散佈的點。設定為10點。
// CH為凸包上的頂點。設定為逆時針方向排列。可以視作一個stack。
struct Point {long long x, y;} P[20], CH[21], p[20];
 
// 向量OA叉積向量OB。大於零表示從OA到OB為逆時針旋轉。
double cross(Point& o, Point& a, Point& b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
 
// 小於。依座標大小排序，先排 x 再排 y。
bool compare(Point& a, Point& b)
{
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
 
bool  Andrew_monotone_chain(int x, int y)
{
    // 將所有點依照座標大小排序
    sort(P, P+n, compare);
 
    int m = 0;  // m 為凸包頂點數目
 
    // 包下半部
    for (int i=0; i<n; ++i)
    {
        while (m >= 2 && cross(CH[m-2], CH[m-1], P[i]) < 0) m--;
        CH[m++] = P[i];
    }
 
    // 包上半部，不用再包入方才包過的終點，但會再包一次起點
    for (int i=n-2, t=m+1; i>=0; --i)
    {
        while (m >= t && cross(CH[m-2], CH[m-1], P[i]) < 0) m--;
        CH[m++] = P[i];
    }
 
    m--;    // 最後一個點是重複出現兩次的起點，故要減一。
    for (int i = 0; i < m; i++)
    	if (CH[i].x == x && CH[i].y == y)
    		return true;
    //for (int i = 0; i <= m; i++)
    return false;
}


int main()
{
	scanf(" %d",&T);

	for (cas = 1; cas <= T; cas++) {
		scanf(" %d",&N);
		for (int i = 0; i < N; i++ ) {
			scanf(" %lld %lld", &p[i].x, &p[i].y);
		}

		printf("Case #%d:\n", cas);
		for (int i = 0; i < N; i++) {
			int res = N;
			for (int S = 0; S < (1<<N); S++) {
				int tmp = 0;
				n = 0;
				for (int j = 0; j < N; j++) {
					if ((S&(1<<j)) > 0) {
						P[n++] = p[j];
					} else {
						if (j == i)continue;
						tmp++;
					}
				}

				if (n <= 3 || Andrew_monotone_chain(p[i].x, p[i].y))
					res = min(res, tmp);
			}
			if (N <= 3)
				printf("0\n");
			else
				printf("%d\n", res);
		}
	}

	return 0;
}