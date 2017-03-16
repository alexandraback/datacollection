/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>
#include <queue>

int main_case(void)
{
    int rows, cols, tenants;
    std::priority_queue<std::pair<int, std::pair<int, int>>> que;
    scanf("%d %d %d", &rows, &cols, &tenants);
    int result = (rows - 1) * cols + (cols - 1) * rows;
    bool freed[rows][cols];
    int cost[rows][cols];
    for(int r = 0; r < rows; ++ r)
        for(int c = 0; c < cols; ++ c)
        {
            freed[r][c] = false;
            cost[r][c] = !!r + (r < rows - 1) + !!c + (c < cols - 1);
            que.push(std::make_pair(cost[r][c], std::make_pair(r, c)));
        }

    while(tenants < rows * cols && !que.empty())
    {
        auto act = que.top();
        que.pop();

        if(freed[act.second.first][act.second.second])
            continue;

        if(cost[act.second.first][act.second.second] != act.first)
            continue;

        freed[act.second.first][act.second.second] = true;
        if(act.second.first)
        {
            cost[act.second.first - 1][act.second.second] -= 1;
            que.push(std::make_pair(cost[act.second.first - 1][act.second.second], std::make_pair(act.second.first - 1, act.second.second)));
        }

        if(act.second.first + 1 < rows)
        {
            cost[act.second.first + 1][act.second.second] -= 1;
            que.push(std::make_pair(cost[act.second.first + 1][act.second.second], std::make_pair(act.second.first + 1, act.second.second)));
        }

        if(act.second.second)
        {
            cost[act.second.first][act.second.second - 1] -= 1;
            que.push(std::make_pair(cost[act.second.first][act.second.second - 1], std::make_pair(act.second.first, act.second.second - 1)));
        }

        if(act.second.second < cols - 1)
        {
            cost[act.second.first][act.second.second + 1] -= 1;
            que.push(std::make_pair(cost[act.second.first][act.second.second + 1], std::make_pair(act.second.first, act.second.second + 1)));
        }

        result -= act.first;
        ++ tenants;
    }

    return result;
}

int main(void)
{
    int tests = 0;
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
        printf("Case #%d: %d\n", t + 1, main_case());

    return 0;
}
