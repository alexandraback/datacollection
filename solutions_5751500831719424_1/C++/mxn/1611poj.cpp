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
char A[maxn][maxn], B[maxn], C[maxn], D[maxn];
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
int CC[maxn][maxn], BB[maxn];
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
int go(int x[][111], int idx){
    int tem[maxn], ans = 0;
    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < idx; j++){
            cout << x[i][j];
        }
        cout << endl;
    }*/
    memset(tem, 0, sizeof(tem));
    for(int i = 0; i < idx; i++){
        for(int j = 0; j < n; j++){
            tem[j] = x[j][i];
        }
        sort(tem, tem+n);
        int mid = n/2;
        for(int j = 0; j < n; j++){
            ans+=abs(tem[mid]-tem[j]);
        }
    }
    return ans;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
        scanf("%d", &n);
        memset(A, '\0', sizeof(A));
        memset(B, '\0', sizeof(B));
        memset(C, '\0', sizeof(C));
        memset(D, '\0', sizeof(D));
        for(int i = 0; i < n ;i++) scanf("%s", A[i]);
        //int la = strlen(A), lb = strlen(B);
        fun(A[0], C);
        int flag = 0;
        for(int i = 1; i < n ;i ++) {
            fun(A[i], D);
            if(strcmp(C,D)!=0) {
                printf("Case #%d: Fegla Won\n",cas);
                flag  = 1; break;
            }
        }
        if(flag == 1) continue;
        //
        int xxx = cal(A[0], CC[0]);
        for(int i = 1; i < n; i++) {
            cal(A[i], CC[i]);
        }

        printf("Case #%d: %d\n",cas, go(CC, xxx));
    }
    return 0;
}
