#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int solve(int r, int c, int n, int color)
{
    vector<int> answer;
    int to_remove = r * c - n;
    for (int i = 1; i + 1 < r && to_remove > 0; ++ i) {
        for (int j = 1; j + 1 < c && to_remove > 0; ++ j) {
            if ((i + j) % 2 == color) {
                answer.push_back(4);
            }
        }
    }

    for (int i = 0; i < r && to_remove > 0; ++ i) {
        for (int j = 0; j < c && to_remove > 0; ++ j) {
            int cnt = ((i == 0) || (i == r - 1)) + ((j == 0) || (j == c - 1));
            if (cnt == 1) {
                // edge
                if ((i + j) % 2 == color) {
                    if (i == 0 && r == 1) {
                        answer.push_back(2);
                    } else if (j == 0 && c == 1) {
                        answer.push_back(2);
                    } else {
                        answer.push_back(3);
                    }
                }
            }
        }
    }

    //printf("%d, %d\n", color, answer.size());

    for (int i = 0; i < r && to_remove > 0; ++ i) {
        for (int j = 0; j < c && to_remove > 0; ++ j) {
            int cnt = ((i == 0) || (i == r - 1)) + ((j == 0) || (j == c - 1));
            if (cnt == 2) {
                // corner
                if ((i + j) % 2 == color) {
                    if (i == 0 && j == 0 && r == 1 && c == 1) {
                        answer.push_back(0);
                    } else if (i == 0 && r == 1) {
                        answer.push_back(1);
                    } else if (j == 0 && c == 1) {
                        answer.push_back(1);
                    } else {
                        answer.push_back(2);
                    }
                }
            }
        }
    }
    sort(answer.rbegin(), answer.rend());
    int sum = 0;
    for (int i = 0; i < answer.size() && i < to_remove; ++ i) {
        sum += answer[i];
    }

    int total = r * (c - 1) + c * (r - 1);
    //cerr << total << " " << sum << " " << to_remove << endl;
    return total - sum;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int tests, test = 1;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        int r, c, n;
        scanf("%d%d%d", &r, &c, &n);
        printf("Case #%d: %d\n", test, min(solve(r, c, n, 0), solve(r, c, n, 1)));
    }
    return 0;
}
