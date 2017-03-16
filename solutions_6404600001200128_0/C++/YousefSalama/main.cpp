//In the name of Allah

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

int T, N, m[1005], C;
int main(){
    freopen("A.txt", "r", stdin);
    freopen("Aout.txt", "w", stdout);
    
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
            scanf("%d", &m[i]);
        
        int a1 = 0, a2 = 0;
        for(int i = 1; i < N; i++){
            if(m[i] >= m[i - 1])continue;
            a1 += m[i - 1] - m[i];
        }
        
        int L = 0, R = 100000;
        while(L < R){
            int mid = (L + R) / 2;
            
            bool ok = true;
            for(int i = 1; i < N; i++){
                if(m[i] >= m[i - 1])continue;
                if(mid < (m[i - 1] - m[i]))ok = false;
            }
            
            if(ok)R = mid;
            else L = mid + 1;
        }
        
        for(int i = 1; i < N; i++){
            a2 += min(L, m[i - 1]);
        }
        printf("Case #%d: %d %d\n", ++C, a1, a2);
    }
    return 0;
}