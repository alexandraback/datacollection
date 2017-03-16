#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <map>
#include <string>
using namespace std;


char str[120][120];
int num[120];
char c[120];
int idx[120];
int minAbs(int a[], int n){
    sort(a, a+n);
    int x = a[n/2];
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += abs(a[i] - x);
    return sum;
}

void ReadAndSolve(){
    int T, N;
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++){
        scanf("%d", &N);
        scanf("%s", str[0]);
        char cur = str[0][0];
        int id = 0;
        c[id++] = cur;
        int j = 1;
        while(str[0][j]){
            if(str[0][j] != cur){
                cur = str[0][j];
                c[id++] = cur;
            }
            j++;
        }

        idx[0] = 0;
        for(int i=1; i<N; i++){
            scanf("%s", str[i]);
            idx[i] = 0;
        }
        bool flag = true;
        int ans = 0;
        for(int i=0; i<id && flag; i++){
            for(int j=0; j<N && flag; j++){
                int x = 0;
                while(str[j][idx[j]] == c[i]){
                    x++;
                    idx[j]++;
                }
                if(x == 0) {
                    flag = false;
                    break;
                }
                num[j] = x;
            }
            ans += minAbs(num, N);
        }
        for(int i=0; i<N; i++)
            if(str[i][idx[i]]) flag = false;
        printf("Case #%d: ", ca);
        if(!flag) printf("Fegla Won\n");
        else printf("%d\n", ans);
    }
}


void UseStdIO(){
    ReadAndSolve();
}

void UseFileIO(){
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    ReadAndSolve();
}

int main()
{
    //UseStdIO();
    UseFileIO();
    return 0;
}
