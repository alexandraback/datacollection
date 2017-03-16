#include <iostream>
#include <cassert>
using namespace std;

int R, C, N, minunhappy;

int nextperm(int v)
{
    int t = v | (v - 1);
    int w = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
    return w;
}

bool isone(int x, int idx)
{
    if (idx < 0 || idx >= R * C) return false;
    return ((x & (1 << idx)) != 0);
}

int unhappy(int x)
{
    int total = 0;
    for (int i = 0; i < R*C; i++) {
        if (!isone(x, i)) continue;
        if (isone(x, i + C)) total++;
        if (isone(x, i - C)) total++;
        if (i % C != 0 && isone(x, i - 1)) total++;
        if (i % C != C-1 && isone(x, i + 1)) total++;
    }
    assert(total % 2 == 0);
    return total/2;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        minunhappy = 999999;
        cin >> R >> C >> N;
        if (N == 0)
            minunhappy = 0;
        else { 
            int v = (1 << N) - 1, lim = (1 << (R*C));
            while (v < lim) {
                int total = unhappy(v);
                if (total < minunhappy) minunhappy = total;
                v = nextperm(v);
            }
        }
        cout << "Case #" << t << ": " << minunhappy << endl;
    }
    return 0;
}
