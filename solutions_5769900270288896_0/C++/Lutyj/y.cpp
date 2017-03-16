#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXR = 4, MAXC = 64;

int R, C, N;
int F[MAXR][MAXC];

int rec(int i, int left)
{
    if (left == 0) return 0;

    int r = i / C, c = i % C;
    F[r][c] = 1;

    int cur = 0;
    if (r > 0 && F[r - 1][c]) ++cur;
    if (c > 0 && F[r][c - 1]) ++cur;

    int answer = cur + rec(i + 1, left - 1);

    F[r][c] = 0;
    if (R * C - i > left)
        answer = min(answer, rec(i + 1, left));

    return answer;
}

int main()
{
    int T; scanf("%d", &T);

    for (int t = 0; t < T; ++t) {
        scanf("%d%d%d", &R, &C, &N);
        if (R > C) swap(R, C);

        printf("Case #%d: %d\n", t + 1, rec(0, N));
    }

    return 0;
}
