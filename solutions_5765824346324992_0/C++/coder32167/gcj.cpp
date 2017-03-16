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
    int max_need = 0;
    scanf("%d%d", &B, &N);
    for(int i = 0; i < B; ++i) {
        scanf("%d", num + i);
        max_need = max(max_need, num[i]);
    }

    if(B >= N) {
        cout << N << endl;
        return 0;
    }
    N -= B;

    long long l_limit = 0;
    long long r_limit = (long long)max_need * N;
    long long mid;
    long long cutted = 0;
    for(; l_limit < r_limit; ) {
        //cout << "l_limit :" << l_limit << " r_limit " << r_limit << endl;
        mid = (l_limit + r_limit) / 2;
        cutted = 0;
        for(int j = 0; j < B; ++j) {
            cutted += mid / num[j];
        }
        //cout << " cutted " << cutted << endl;
        if(cutted >= N) {
            r_limit = mid;
        } else {
            l_limit = mid + 1;
        }
    }
    cutted = 0;
    for(int j = 0; j < B; ++j) {
        cutted += (l_limit - 1) / num[j];
    }

    //cout << " cutted " << cutted << endl;
    long long more_get = max_need;
    for(int j = 0; j < B; ++j) {
        more_get = min(more_get, l_limit % num[j]);
    }
    //cout << " more_get " << more_get << endl;
    l_limit -= more_get;
    //cout << " l_limit " << l_limit << endl;
    for(int j = 0; j < B; ++j) {
        if(l_limit % num[j] == 0) {
            cutted++;
            if(cutted == N) {
                cout << j + 1 << endl;
                return 0;
            }
        }
    }

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

