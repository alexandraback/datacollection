#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
const int INF = 2147483647;
char s[110][110];
string ns[110];
int cnt[110][110];
char* rem(int pos, char *s, int *c){
    char pre = s[0];
    int cnt = 1;
    char ret[110];
    int retLen = 0;
    for(int i = 1 ; s[i];i++){
        char ch = s[i];
        if(ch == pre) cnt++;
        else{
            ret[retLen] = pre;
            c[retLen] = cnt;
            retLen++;

            pre = ch;
            cnt = 1;
        }
    }
    ret[retLen] = pre;
    c[retLen] = cnt;
    ret[++retLen] = 0;
    ns[pos] = string(ret);
}
int abs(int x){
    if(x > 0)return x;
    return -x;
}
int trans(int x,int y){
    int ret = 0;
    for(int i = 0 ; i<ns[x].size();i++){
        ret += abs(cnt[x][i] - y);
    }
    return ret;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int _ = 1; _<=T; _++)
    {
        printf("Case #%d: ",_);
        int n;
        scanf("%d",&n);
        for(int i = 0 ;i<n;i++){
            scanf("%s",s[i]);
            rem(i,s[i],cnt[i]);
        }

        bool fail = false;
        for(int i = 0 ;i <n && fail == false;i++)
        for(int j= i+1;j<n;j++)
        if(ns[i]!=ns[j]){
            fail =true;
            puts("Fegla Won");

            break;
        }
        if(fail){
            continue;
        }
        int ans = 0;
        for(int i = 0 ; i < ns[0].size() ; i++){
            int tans = INF;
            for(int r = 1; r<=100;r++){
                int ttans = 0;
                for(int j = 0; j < n;j++)
                    ttans += abs(cnt[j][i] - r);
                if(ttans < tans){
                    tans = ttans;
                }
            }
            ans += tans;
        }

        printf("%d\n",ans);
    }
    return 0;
}

