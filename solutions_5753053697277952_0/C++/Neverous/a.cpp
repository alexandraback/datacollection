/* 2016
 * Maciej Szeptuch
 * II UWr
 */

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

int parties;
int size;
int tests;
std::pair<int, char> party[32];

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        printf("Case #%d: ", t + 1);
        scanf("%d", &parties);
        for(int p = 0; p < parties; ++ p)
        {
            scanf("%d", &size);
            party[p] = std::make_pair(size, 'A' + p);
        }

        std::sort(party, party + parties);
        std::vector<std::string> result;
        for(int p1 = parties - 1, p2 = parties - 2; p1 >= 0 || p2 >= 0;)
        {
            std::string step = "";
            if(p1 >= 0)
            {
                step += party[p1].second;
                -- party[p1].first;
            }

            if(p2 >= 0)
            {
                step += party[p2].second;
                -- party[p2].first;
            }

            result.push_back(step);

            while(p1 >= 0 && !party[p1].first)
                -- p1;

            p2 = std::min(p1 - 1, p2);
            while(p2 >= 0 && !party[p2].first)
                -- p2;
        }

        for(int r = result.size() - 1; r >= 0; -- r)
            printf("%s ", result[r].c_str());

        puts("");
    }

    return 0;
}
