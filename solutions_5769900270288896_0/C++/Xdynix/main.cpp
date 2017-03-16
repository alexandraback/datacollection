/*                    _oo0oo_
                     o8888888o
                     88" . "88
                     (| -_- |)
                     0\  =  /0
                   ___/`---'\___
                 .' \\|     |// '.
                / \\|||  :  |||// \
               / _||||| -:- |||||_ \
              |   | \\\  _  /// |   |
              | \_|  ''\___/''  |_/ |
              \  .-\__  '_'  __/-.  /
            ___'. .'  /--.--\  `. .'___
         ."" '<  `.___\_<|>_/___.'  >' "".
        | | :  `- \`.;`\ _ /`;.`/ -`  : | |
        \  \ `_.   \_ __\ /__ _/   ._` /  /
    =====`-.____`.___ \_____/ ___.`____.-`=====
                      `=---='


    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

             ·ð×æ±£ÓÓ         ÓÀÎÞBUG
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<utility>
#include<string>
#include<ctime>
#include<numeric>
#include<functional>
using namespace std;

#define _FIO_

#define eps 1e-8
const double PI = acos(-1.0);
#define LL long long
#define ULL unsigned long long
#define MP make_pair
#define wait system( "pause" );
#define sqr(x) ((x)*(x))

int r, c, n;
bool g[16][16];

int main() {
#ifdef _FIO_
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _FIO_
	int t;
	scanf("%d", &t);
	for (int ca = 1; ca <= t; ++ca) {
		scanf("%d%d%d", &r, &c, &n);
		int ans = 0x7ffffff;
		for (int stat = 0; stat < 1 << (r * c); ++stat) {
			int cnt = 0, temp = 0;
			for (int i = 0; i < r; ++i)
				for (int j = 0; j < c; ++j) {
					g[i][j] = (stat >> (i * c + j)) & 1;
					if (g[i][j])
						++cnt;
				}
			if (cnt == n) {
				for (int i = 0; i < r; ++i)
					for (int j = 0; j < c; ++j) {
						if (i < r - 1)
							if (g[i][j] && g[i + 1][j])
								++temp;
						if (j < c - 1)
							if (g[i][j] && g[i][j + 1])
								++temp;
					}
				ans = min(ans, temp);
			}
		}
		printf("Case #%d: %d\n", ca, ans);
	}
#ifdef _FIO_
	fclose(stdin);
	fclose(stdout);
#endif // _FIO_
	return 0;
}
