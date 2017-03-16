#include <bits/stdtr1c++.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define dbg(x) cout << #x << " = " << x << endl
#define valid(i, j) ((i) >= 0 && (i) < n && (j) >= 0 && (j) < m)

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

typedef pair<int, int> Pair;
typedef pair<int, Pair> dPair;

set <dPair> S;
int t, n, m, r;
char str[10010][10010], val[10010][10010];

int main(){
    read();
    write();
    int T = 0, i, j, k, l, c, d, res;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d %d", &n, &m, &r);
        int black = 0, white = 0;
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++){
                if ((i ^ j) & 1) white++;
                else black++;
            }
        }

        if (r <= max(black, white)) res = 0;
        else{
            int f = (n * m);
            int lim = (1 << f);
            res = 1000010;

            for (int bitmask = 0; bitmask < lim; bitmask++){
                if (__builtin_popcount(bitmask) == r){
                    for (i = 0; i < n; i++){
                        for (j = 0; j < m; j++){
                            str[i][j] = '.';
                        }
                    }

                    int x = 0;
                    for (int i = 0; i < f; i++){
                        if (bitmask & (1 << i)){
                            c = i / m;
                            d = i % m;
                            str[c][d] = 'T';
                        }
                    }

                for (i = 0; i < n; i++){
                    for (j = 0; j < m; j++){
                            if (str[i][j] == 'T'){
                                c = 0;
                                for (d = 0; d < 4; d++){
                                    k = i + dx[d];
                                    l = j + dy[d];
                                    if (valid(k, l) && str[k][l] == 'T'){
                                        c++;
                                    }
                                }
                                x += c;
                                str[i][j] = '.';
                            }
                        }
                    }

                    if (x < res) res = x;
                }
            }
        }

        printf("Case #%d: %d\n", ++T, res);
    }
    return 0;
}
