#include <stdio.h>
#include <vector>
#include <queue>
#define pb push_back
#define WHITE 0
#define BLACK 1
#define INF 0x3f3f3f3f
using namespace std;

vector <int> vizinho[10005];
int res;
int r, c, n;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int is_ok(int i, int j, int flag) {
    if (flag == WHITE) {
        return ((i + j) % 2) == 1;
    }
    return ((i + j) % 2) == 0;
}

void add_vizinho(int x, int y) {
    int nx, ny;

    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
            vizinho[nx][ny]++;
        }
    }
    return;
}

int solve(int color) {
    int count = 0;
    int next;
    int aux = 0;
    priority_queue <int> pq;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (is_ok(i, j, color)) {
                add_vizinho(i, j);
                count++;
            }
        }
    }

    if (count >= n) {
        return 0;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!is_ok(i, j, color)) {
                pq.push(-vizinho[i][j]);
            }
        }
    }

    while(count < n) {
        next = -pq.top();
        pq.pop();
        count++;
        aux += next;
    }
    return aux;
}

int main(void) {
    int t;

    scanf(" %d", &t);

    for (int caso = 1; caso <= t; caso++) {
        scanf(" %d %d %d", &r, &c, &n);

        for (int i = 0; i < r; i++) {
            vizinho[i].clear();
            for (int j = 0; j < c; j++) {
                vizinho[i].pb(0);
            }
        }
        res = INF;
        res = min(res, solve(WHITE));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                vizinho[i][j] = 0;
            }
        }
        res = min(res, solve(BLACK));

        printf("Case #%d: %d\n", caso, res);
    }
    return 0;
}
