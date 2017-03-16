/*
* @Author: Comzyh
* @Date:   2016-05-08 17:07:08
* @Last Modified by:   Comzyh
* @Last Modified time: 2016-05-08 17:23:11
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int T;
int N;
int num[27];
int main()
{
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++)
    {
        stack<pair<int, int> >ans;
        scanf("%d", &N);
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= N; i++)
            scanf("%d", &num[i]);
        while (1)
        {
            pair<int, int> max_two = make_pair(0, 0);
            for (int i = 1; i <= N; i++)
                if (num[i] > num[max_two.second])
                {
                    max_two.second = i;
                    if (num[max_two.second] > num[max_two.first])
                        swap(max_two.first, max_two.second);
                }
            // printf("%4d %4d\n", max_two.first, max_two.second);
            if (!max_two.first)
                break;
            if (max_two.second)
                num[max_two.second] --;
            num[max_two.first] --;
            ans.push(max_two);
        }
        printf("Case #%d:", TT);
        // printf("%d\n", ans.size());
        while (!ans.empty())
        {
            printf(" ");
            pair<int, int> c = ans.top();
            ans.pop();
            printf("%c", c.first - 1 + 'A');
            if (c.second)
                printf("%c", c.second - 1 + 'A');
        }
        printf("\n");
    }
    return 0;
}