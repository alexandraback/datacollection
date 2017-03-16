#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 111;
int n;
char A[maxn], B[maxn], C[maxn], D[maxn];
void fun(char* x, char* y){
    memset(y, '\0', sizeof(y));
    int la = strlen(x);//, lb = strlen(y);
    y[0] = x[0];
    int idx = 1;
    for(int i = 1; i < la; i++){
        //if(x[i] == x[i-1] && i == la-1) y[idx++] = x[i];
        if(x[i] != x[i-1]) y[idx++] = x[i];
    }
}
int CC[maxn], BB[maxn];
int cal(char* x, int* AA){
    memset(AA, 0, sizeof(AA));
    int i = 0, idx = 0;
    //AA[0] = 1;
    for( ; i<strlen(x); i++){
        if(x[i] == C[idx]){
            AA[idx]++;
        }
        else {
            idx++;
            AA[idx] = 1;
        }
    }
    return idx+1;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("A-small-attempt2.in", "r", stdin);
    //freopen("A-small-attempt2.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
        scanf("%d", &n);
        memset(A, '\0', sizeof(A));
        memset(B, '\0', sizeof(B));
        memset(C, '\0', sizeof(C));
        memset(D, '\0', sizeof(D));
        scanf("%s%s", A, B);
        //int la = strlen(A), lb = strlen(B);
        fun(A, C);
        fun(B, D);
        if(strcmp(C,D)!=0) {
            printf("Case #%d: Fegla Won\n",cas);
            continue;
        }
        //
        int xxx = cal(A, CC);
        cal(B, BB);
        int ans = 0;
        for(int i = 0; i < xxx; i++) ans+= abs(CC[i]-BB[i]);
        //cout << endl;
        printf("Case #%d: %d\n",cas, ans);
    }
    return 0;
}
