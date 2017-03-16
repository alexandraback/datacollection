#include <bits/stdc++.h>
using namespace std;

const int N = 110;
struct point
{
    vector<char> v1;
    vector<int> v2;
}a[N];

void read(int id) {
    char s[N];
    scanf("%s",s);
    int n = strlen(s);
    int i = 0;
    while(i < n) {
        int j = i;
        while(j < n && s[i] == s[j]) j ++;
        a[id].v1.push_back(s[i]);
        a[id].v2.push_back(j - i);
        i = j;
    }
}

void solve()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++) {
        a[i].v1.clear();
        a[i].v2.clear();
        read(i);
    }
    for(int i = 2; i <= n; i ++) {
        if(a[i].v1.size() != a[1].v1.size()) {
            puts("Fegla Won");
            return;
        }
        for(int j = 0; j < a[i].v1.size(); j ++)
            if(!(a[i].v1[j] == a[1].v1[j])) {
                puts("Fegla Won");
                return;
            }
    }
    int ans = 0;
    for(int j = 0; j < a[1].v1.size(); j ++) {
        int maxn = 0x7fffffff;
        for(int i = 1; i <= 100; i ++) {
            int sum = 0;
            for(int k = 1; k <= n; k ++) {
                sum += abs(a[k].v2[j] - i);
            }
            maxn = min(maxn,sum);
        }
        ans += maxn;
    }
    cout << ans << endl;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas = 1; cas <= t; cas ++) {
        printf("Case #%d: ",cas);
        solve();
    }
    return 0;
}
