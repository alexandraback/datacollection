#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using std::sort;

struct Node{
    char s[1024];
    int n[1024];
    int len;
}data[120];

void compress(char* str, Node& node){
    int n = 0;
    memset(node.n, 0, sizeof(node.n));
    for(int i = 0; str[i]; ++i){
        if(i == 0 || str[i] != str[i-1]){
            node.s[n] = str[i];
            node.n[n] = 1;
            ++n;
        }else
            ++node.n[n-1];
    }
    node.s[n] = 0;
    node.len = n;
    //printf("%s %d\n", str, n);
}


char str[1024];

void solve(){
    int N, T;
    scanf("%d%d",&N,&T);
    bool ok = true;
    for(int i = 0; i<N; ++i){
        scanf("%s", str);
        compress(str, data[i]);
    }
    for(int i = 1; i<N; ++i){
        if(strcmp(data[0].s,data[i].s)!=0)
            ok = false;
    }
    if(ok){
        int ans = 0;
        int len = data[0].len;
        for(int i = 0; i < len; ++i){
            int tmp[120];
            for(int j = 0; j < N; ++j){
                tmp[j] = data[j].n[i];
            }
            sort(tmp, tmp+N);
            int s = tmp[N/2];
            for(int j = 0; j < N; ++j)
                ans += abs(tmp[j] - s);
        }
        printf("%d\n", ans);
    }else
        printf("Fegla Won\n");
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        printf("Case #%d: ", t);
        solve();
    }
}
