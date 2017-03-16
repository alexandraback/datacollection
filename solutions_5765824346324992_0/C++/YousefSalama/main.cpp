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

int T, C, B, N, M[1005];
int main(){
    freopen("B.txt", "r", stdin);
    freopen("Bout.txt", "w", stdout);
    
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &B, &N);
        for(int i = 0; i < B; i++)
            scanf("%d", &M[i]);
        
        long long L = 0, R = 1LL << 57;
        while(L < R){
            long long mid = (L + R) / 2;
            
            long long cN = 0;
            for(int i = 0; i < B; i++)
                cN += mid / M[i] + 1;
            
            if(cN < N)L = mid + 1;
            else R = mid;
        }
        
        long long rN = 0, cN = 0;
        for(int i = 0; i < B; i++){
            cN += L / M[i] + 1;
            if(L > 0)rN += (L - 1) / M[i] + 1;
        }
        cN = min(cN, (long long)N);
        rN = min(rN, (long long)N);
            
        long long d = cN - rN;
        int ind;
        for(int i = 0; i < B; i++){
            if((L % M[i]) == 0){
                if(d > 1)d--;
                else{
                    ind = i;
                    break;
                } 
            }
        }
        printf("Case #%d: %d\n", ++C, ind + 1);
    }
    return 0;
}