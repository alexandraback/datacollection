#include <cstdio>
#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

void solve(int n)
{
    priority_queue<pair<int, char>> p;

    int count = 0;
    for (int i = 0; i < n; i++) {
        int p_i;
        scanf("%d", &p_i);
        p.push(make_pair(p_i, i + 'A'));
        count += p_i;
    }

    while (count > 0) {
        int p_i;
        char c;

        tie(p_i, c) = p.top();
        p.pop();
        printf("%c", c);
        if (p_i) p.push(make_pair(p_i - 1, c));
        count--;

        if (!(p.top().first == 1 && count == 2)) {
            tie(p_i, c) = p.top();
            p.pop();
            printf("%c", c);
            if (p_i) p.push(make_pair(p_i - 1, c));
            count--;
        }

        printf(" ");
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);

        printf("Case #%d: ", i);
        solve(n);
        puts("");
    }

    return 0;
}
