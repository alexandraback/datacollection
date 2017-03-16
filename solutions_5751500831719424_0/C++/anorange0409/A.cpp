#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MN = 105;
vector<int> b[MN], c[MN];
string a[MN];
int N;
void process(int k){
    b[k].clear(); c[k].clear();
    string s = string(a[k]);
    char now = '!'; int cnt = 1;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == now){
            cnt ++;
        } else {
            if (now != '!'){b[k].push_back(now); c[k].push_back(cnt);}
            cnt = 1; now = s[i];
        }
    }
    if (now != '!'){b[k].push_back(now); c[k].push_back(cnt);}
}

int abss(int x){
    if (x > 0) return x;
    else return -x;
}

int ok(){
    for (int i = 0; i < N; i++){
        if (b[i].size() != b[0].size())
            return -1;

        for (int j = 0; j < b[0].size(); j++){
            if (b[i][j] != b[0][j]) return -1;
        }
    }
    int ans = 0;
    for (int j = 0; j < b[0].size(); j++){
        vector<int> tmp;
        for (int i = 0; i < N; i++)
            tmp.push_back(c[i][j]);
        sort(tmp.begin(), tmp.end());
        int n = tmp.size() / 2 + 1;
        int mid = tmp[n - 1];
        for (int i = 0; i < tmp.size(); i++)
            ans += abss(mid - tmp[i]);
    }
    return ans;

}
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++){
        cin >> N;
        for (int i = 0; i < N; i++){
            cin >> a[i];
            process(i);
        }
        int ans = ok();
        if (ans < 0)
            printf("Case #%d: Fegla Won\n", o);
        else
            printf("Case #%d: %d\n", o, ans);
    }
}
