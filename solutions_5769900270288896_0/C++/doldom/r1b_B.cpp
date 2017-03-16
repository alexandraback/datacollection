#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 987654321;
const int dx[4] ={-1, 0, 1, 0};
const int dy[4] ={0, 1, 0, -1};

int r, c, n;
int best;

int board[17][17];

bool validpos(int y, int x) {
	return y >= 0 && y < c && x >= 0 && x < r;
}

void backtrack(int pos, int left) {
	if (left == 0) {
		int count = 0;
		for (int y=0; y<c; ++y)
			for (int x=0; x<r; ++x)
				if (board[y][x])
					for (int d=0; d<4; ++d)
						if (validpos(y+dy[d], x+dx[d]) && board[y+dy[d]][x+dx[d]])
							++count;
		count /= 2;
		if (best > count) {
			best = count;
			/*for (int y=0; y<c; ++y) {
				for (int x=0; x<r; ++x)
					printf("%d ", board[y][x]);
				puts("");
			}*/
		}
		return;
	}
	for (int s=pos+1; s<r*c-left+1; ++s) {
		int y = s/r, x = s%r;
		board[y][x] = 1;
		backtrack(s, left-1);
		board[y][x] = 0;
	}
}

int solve() {
	if (n*2-1 <= r*c)
		return 0;
	best = INF;
	backtrack(-1, n);
	return best;
}


int main() {
	freopen("r1b\\B-small-attempt0.in", "r", stdin);
	freopen("r1b\\B-small.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		scanf("%d%d%d", &r, &c, &n);
		printf("Case #%d: ", N);
		printf("%d\n", solve());
	}
}