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
    //freopen("/Users/guanxiong/Documents/documents/google_code_jam/A-small-attempt1.in","r",stdin);
    //freopen("/Users/guanxiong/Documents/documents/google_code_jam/A-small-attempt1.out","w",stdout);
    int cases;
    int nums;
    scanf("%d", &cases);
    for(int case_num = 1; case_num <= cases; case_num ++)
    {
        scanf("%d", &nums);
        for(int i=0; i<nums; i++)
        {
            scanf("%d", &arr[i]);
        }
        int sum1 = 0;
        for(int i=1; i<nums; i++)
        {
            if(arr[i-1] > arr[i])
            {
                sum1 += arr[i-1] - arr[i];
            }
        }
        int max_diff = 0;
        for(int i=1; i<nums; i++)
        {
            max_diff = std::max(max_diff, arr[i-1] - arr[i]);
        }
        int sum2 = 0;
        int curr = 0;
        for(int i=0; i<nums-1; i++)
        {
            curr = arr[i];
            sum2 += std::min(max_diff, curr);
        }
        printf("Case #%d: %d %d\n", case_num, sum1, sum2);
    }
    return 0;
}


