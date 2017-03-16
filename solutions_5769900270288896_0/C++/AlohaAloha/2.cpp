#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_map>


const int MAX = 1000000000;
const int SIZE = 18;
const int RANGE = 65560;
int dp[SIZE][RANGE][SIZE];
int num[RANGE];
int rows, cols;


int inner_collision(int num)
{
    int count = 0;
    for(int i=0; i<cols-1; i++)
    {
        int curr = (num >> i) & 1;
        int next = (num >> (i+1)) & 1;
        if(curr & next)
        {
            count ++;
        }
    }
    return count;
}


int outer_collision(int num1, int num2)
{
    int count = 0;
    for(int i=0; i<cols; i++)
    {
        int curr1 = (num1 >> i) & 1;
        int curr2 = (num2 >> i) & 1;
        if(curr1 && curr2)
        {
            count ++;
        }
    }
    return count;
}


int count(int num)
{
    int count = 0;
    for(int i=0; i<cols; i++)
    {
        int curr = (num >> i) & 1;
        if(curr)
        {
            count ++;
        }
    }
    return count;
}


int main()
{
    //freopen("/Users/guanxiong/Documents/documents/google_code_jam/round-1-B/B-small-attempt1.in","r",stdin);
    //freopen("/Users/guanxiong/Documents/documents/google_code_jam/round-1-B/B-small-attempt1.out","w",stdout);
    int cases;
    int nums;
    scanf("%d", &cases);
    
    for(int case_num = 1; case_num <= cases; case_num ++)
    {
        scanf("%d%d%d", &rows, &cols, &nums);
        int range = (1 << cols);
        
        for(int i=0; i<range; i++)
        {
            num[i] = count(i);
        }
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<RANGE; j++)
            {
                for(int k=0; k<SIZE; k++)
                {
                    dp[i][j][k] = MAX;
                }
            }
        }
        for(int i=0; i<range; i++)
        {
            dp[0][i][num[i]] = inner_collision(i);
        }
        for(int curr_row = 1; curr_row < rows; curr_row ++)
        {
            for(int curr_num = 0; curr_num < range; curr_num ++)
            {
                for(int prev_tenant = 0; prev_tenant + num[curr_num] <= nums; prev_tenant ++)
                {
                    for(int prev_num = 0; prev_num < range; prev_num ++)
                    {
                        if(dp[curr_row-1][prev_num][prev_tenant] < MAX)
                        {
                            int collisions = outer_collision(prev_num, curr_num);
                            dp[curr_row][curr_num][prev_tenant+num[curr_num]] = std::min(dp[curr_row][curr_num][prev_tenant+num[curr_num]], dp[curr_row-1][prev_num][prev_tenant] + collisions + inner_collision(curr_num));
                        }
                    }
                }
            }
        }

        int min_value = MAX;
        for(int i=0; i<range; i++)
        {
            min_value = std::min(min_value, dp[rows-1][i][nums]);
        }
        printf("Case #%d: %d\n", case_num, min_value);
    }
    return 0;
}

