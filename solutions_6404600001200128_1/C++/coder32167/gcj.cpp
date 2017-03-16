#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <string.h>
#include <math.h>
#include <stdlib.h>  
#include <stack>   
using namespace std;  

const int MOD = 100007;

int N, B, K, Q;
int num[1005];

int run()
{
    scanf("%d", &N);

    for(int i = 0; i < N; ++i) {
        scanf("%d", num + i);
    }
    int res = 0;
    int max_res = 0;
    for(int i = 0; i < N - 1; ++i) {
        if(num[i] > num[i + 1]) {
            res += num[i] - num[i + 1];
            max_res = max(max_res, num[i] - num[i + 1]);
        }
    }
    cout << res << " ";

    res = 0;
    for(int i = 0; i < N - 1; ++i) {
        if(num[i] > max_res) {
            res += max_res;
        } else {
            res += num[i];
        }
    }

    cout << res << endl;



    return 0;
}


int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        run();
    }

    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

