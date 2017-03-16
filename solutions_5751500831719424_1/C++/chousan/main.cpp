#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 110;

int n;
char str[N];
string a[N];
vector<int> cnt[N];

bool check(){
    for(int i = 1; i < n; ++i)
        if(a[i] != a[i - 1]) return true;
    return false;
}
int get(int idx){
    vector<int> vec;
    for(int i = 0; i < n; ++i) vec.push_back(cnt[i][idx]);
    sort(vec.begin(), vec.end());
    int ret = 0;
    for(int i = 0; i < n; ++i) ret += abs(vec[i] - vec[n / 2]);
    return ret;
}
int main(){
    freopen("in.txt", "r", stdin);
    //freopen("out", "w", stdout);
    int _, cas = 1;
    for(scanf("%d", &_); _--; ){
        printf("Case #%d: ", cas++);
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%s", str);
            a[i] = "";
            cnt[i].clear();
            for(int j = 0; str[j]; ++j){
                int k = j;
                while(str[k + 1] && str[k + 1] == str[j]) k++;
                cnt[i].push_back(k - j + 1);
                a[i] += str[j];
                j = k;
            }
        }
        if(check()) puts("Fegla Won");
        else{
            int ans = 0;
            for(int i = 0; i < a[0].length(); ++i){
                ans += get(i);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
