#include <iostream>
#include <cstdio>
using namespace std;

int r,c,n;
bool t[10005][10005];
int lj = -1;

int szomszed(int x, int y) {
    int ans = 0;
    if (t[x-1][y]) ans++;
    if (t[x+1][y]) ans++;
    if (t[x][y+1]) ans++;
    if (t[x][y-1]) ans++;
    return ans;
}

void tablaki() {
	for (int i = 1; i<=r; i++) {
		for (int j = 1; j<=c; j++) {
			if (t[i][j]) printf("x"); else printf(".");
		}
		printf("\n");
	}
		printf("\n");
		printf("\n");
}

int bt(int x, int y, int db, int v) {
	//printf("%d %d %d %d\n", x, y, db, v);
	if (db > n) return 0;
	if (v > lj) return 0;
	if (x > r) {
		if (db != n) return 0;
		if (v < lj) {
			lj = v;
			//tablaki();
		}
		return 0;
	}
	int x0 = x; int y0 = y;
	if (y0 < c) y0++; else { x0++; y0 = 1; }
	
	t[x][y] = false; bt(x0, y0, db, v);
	
	t[x][y] = true; bt(x0, y0, db+1, v+szomszed(x, y)); t[x][y] = false;
	return 0;
}




int solve(int x, int y, int z) {
	if (z == 0) return 0;
    r = x; c = y; n = z; lj = x*y*4+100;
    for (int i = 0; i<=r+1; i++) for (int j = 0; j<=c+1; j++) {
        t[i][j] = false;
    }
    bt(1, 1, 0, 0);
    return lj;
}


int main()
{
	//cout << solve(4, 1, 2) << endl; return 0;


	int hany; scanf("%d", &hany);
	for (int i = 1; i<=hany; i++) {
		int x,y,z; scanf("%d%d%d", &x, &y, &z);
		printf("Case #%d: %d\n", i, solve(x, y, z));
	}
    return 0;
}


