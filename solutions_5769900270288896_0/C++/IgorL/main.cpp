#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

#define pb push_back
#define mp make_pair
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) n; i++)

const int INF = 1e9;

using namespace std;

int d[10000000];
bool b[100][100];

int main()
{
    freopen("a.in", "rt", stdin);
    freopen("a.out", "wt", stdout);

    int t, n, w, h;

    scanf("%d", &t);

    forn(t1, t) {
        cin >> w >> h >> n;

        int res = INF;
        forn(mask, (1 << (w * h))) {
            int cnt = 0;
            forn(i, w + 1)
                forn(j, h + 1)
                    b[i][j] = 0;
                    
            forn(i, w) {
                forn(j, h) {
                    b[i][j] = mask & (1 << (i * h + j));
                    cnt += b[i][j];
                }
            }
            if (cnt != n) {
                continue;
            }


            int res1 = 0;
            forn(i, w) {
                forn(j, h) {
                    if (b[i][j] && b[i + 1][j])
                        res1++;
                    if (b[i][j] && b[i][j + 1])
                        res1++;
                }
            }

            if (res1 < res)
                res = res1;
        }

    	cout << "Case #" << t1 + 1 << ": " << res << endl;
    }


    return 0;
}