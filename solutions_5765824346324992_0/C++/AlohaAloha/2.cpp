#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <deque>
#include <queue>
#include <string>
#include <vector>


const int SIZE = 1002;
int arr[SIZE];


int main()
{
    //freopen("/Users/guanxiong/Documents/documents/google_code_jam/B-small-attempt2.in","r",stdin);
    //freopen("/Users/guanxiong/Documents/documents/google_code_jam/B-small-attempt2.out","w",stdout);
    int cases;
    int nums, level;
    scanf("%d", &cases);
    for(int case_num = 1; case_num <= cases; case_num ++)
    {
        scanf("%d%d", &nums, &level);
        for(int i=1; i<=nums; i++)
        {
            scanf("%d", &arr[i]);
        }
        int t = 1;
        while(true)
        {
            bool max_common = true;
            for(int i=1; i<=nums; i++)
            {
                if(t % arr[i] != 0)
                {
                    max_common = false;
                }
            }
            if(max_common)
            {
                break;
            }
            else
            {
                t++;
            }
        }
        int number_per_round = 0;
        for(int i=1; i<=nums; i++)
        {
            number_per_round += t / arr[i];
        }
        level %= number_per_round;
        if(level == 0)
        {
            level = number_per_round;
        }
        if(level <= nums)
        {
            printf("Case #%d: %d\n", case_num, level);
            continue;
        }
        level -= nums;
        t = 1;
        bool flag = false;
        while(true)
        {
            for(int i=1; i<=nums; i++)
            {
                if(t % arr[i] == 0)
                {
                    level --;
                    if(level == 0)
                    {
                        printf("Case #%d: %d\n", case_num, i);
                        flag = true;
                        break;
                    }
                }
            }
            t++;
            if(flag)
            {
                break;
            }
        }
    }
    return 0;
}


