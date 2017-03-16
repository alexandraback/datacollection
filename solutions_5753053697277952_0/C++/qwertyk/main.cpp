//#define LARGE
#define SMALL

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int L = 'Z'-'A'+1;

int t, T, N, P[L], i, m1, m2, S, C[L];

int main()
{
#if defined(LARGE)
    freopen("../A-large.in", "r", stdin);
    freopen("../A-large.out", "w", stdout);
#elif defined(SMALL)
    freopen("../A-small-attempt0.in", "r", stdin);
    freopen("../A-small.out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
#endif

    cin >> T;

    for(t = 0; t < T; ++t)
    {
        cin >> N;
        S = 0;
        for (i = 0; i < N; ++i)
        {
            cin >> P[i];
            S += P[i];
        }
        cout << "Case #" << t+1 << ": ";

        for ( ; S != 0; )
        {
            if (P[0] < P[1]) { m1 = 1; m2 = 0; }
            else { m1 = 0; m2 = 1; }
            for (i = 2; i < N; ++i)
            {
                if (P[i] > P[m1])
                {
                    m2 = m1;
                    m1 = i;
                }
                else if (P[i] > P[m2])
                {
                    m2 = i;
                }
            }
            for (i = 0; i < N; ++i)
            {
                if (i == m1) { if (2 * (P[i] - 1) > S - 2) break; }
                else if (i == m2) { if (2 * (P[i] - 1) > S - 2) break; }
                else if (2 * P[i] > S - 2) break;
            }
            if (i == N)
            {
                cout << char('A' + m1) << char('A' + m2) << " ";
                --P[m1];
                --P[m2];
                S -= 2;
                continue;
            }
            for (i = 0; i < N; ++i)
            {
                if (i == m1) { if (2 * (P[i] - 2) > S - 2) break; }
                else if (2 * P[i] > S - 2) break;
            }
            if (i == N)
            {
                cout << char('A' + m1) << char('A' + m1) << " ";
                --P[m1];
                --P[m1];
                S -= 2;
                continue;
            }
            if (S == 3)
            {
                cout << char('A' + m1) << " ";
                --P[m1];
                --S;
            }
        }

        cout << "\n";
    }

    return 0;
}
