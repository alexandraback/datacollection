#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> Coor;
typedef pair<int, Coor> Pair;
vector<int> field[10000];
vector<int> used[10000];
int T;

int main() {
    scanf("%d", &T);
    for (int Case=1; Case<=T; Case++) {
        int r, c, n;
        int all;
        int nremove;
        int ans = 0, ans2 = 0;
        priority_queue<Pair> q, q2;

        scanf("%d %d %d", &r, &c, &n);
        for (int i=0; i<r; i++) {
            field[i].clear();
            used[i].clear();

            for (int j=0; j<c; j++) {
                int cond1 = (i == 0) + (i == r-1);
                int cond2 = (j == 0) + (j == c-1);

                field[i].push_back(4 - cond1 - cond2);
                used[i].push_back(0);
                q.push(Pair(field[i][j], Coor(i, j)));
            }
        }

        nremove = r*c - n;
        all = (r-1) * c + r * (c-1);
        while (nremove > 0) {
            Pair p;
            int num;
            int y ;
            int x;

            if (nremove == r*c-n && c >= 2) p = Pair(field[r-1][c-2], Coor(r-1, c-2));
            else p = q.top(); q.pop(); 
            num = p.first;
            y  = p.second.first;
            x = p.second.second;
                    
            if (used[y][x] || field[y][x] != num) continue;
            ans += num;
            used[y][x] = 1;

            if (y-1 >= 0 && !used[y-1][x]) {
                --field[y-1][x];
                q.push(Pair(field[y-1][x], Coor(y-1, x)));
            }

            if (x-1 >= 0 && !used[y][x-1]) {
                --field[y][x-1];
                q.push(Pair(field[y][x-1], Coor(y, x-1)));
            }

            if (y+1 < r && !used[y+1][x]) {
                --field[y+1][x];
                q.push(Pair(field[y+1][x], Coor(y+1, x)));
            }

            if (x+1 < c && !used[y][x+1]) {
                --field[y][x+1];
                q.push(Pair(field[y][x+1], Coor(y, x+1)));
            }

            --nremove;
        }

        for (int i=0; i<r; i++) {
            field[i].clear();
            used[i].clear();

            for (int j=0; j<c; j++) {
                int cond1 = (i == 0) + (i == r-1);
                int cond2 = (j == 0) + (j == c-1);

                field[i].push_back(4 - cond1 - cond2);
                used[i].push_back(0);
                q2.push(Pair(field[i][j], Coor(i, j)));
            }
        }

        nremove = r*c - n;
        all = (r-1) * c + r * (c-1);
        while (nremove > 0) {
            Pair p;
            int num;
            int y ;
            int x;

            p = q2.top(); q2.pop(); 
            num = p.first;
            y  = p.second.first;
            x = p.second.second;
                    
            if (used[y][x] || field[y][x] != num) continue;
            ans2 += num;
            used[y][x] = 1;

            if (y-1 >= 0 && !used[y-1][x]) {
                --field[y-1][x];
                q2.push(Pair(field[y-1][x], Coor(y-1, x)));
            }

            if (x-1 >= 0 && !used[y][x-1]) {
                --field[y][x-1];
                q2.push(Pair(field[y][x-1], Coor(y, x-1)));
            }

            if (y+1 < r && !used[y+1][x]) {
                --field[y+1][x];
                q2.push(Pair(field[y+1][x], Coor(y+1, x)));
            }

            if (x+1 < c && !used[y][x+1]) {
                --field[y][x+1];
                q2.push(Pair(field[y][x+1], Coor(y, x+1)));
            }

            --nremove;
        }

        printf("Case #%d: %d\n", Case, all-max(ans, ans2));
    }
}
