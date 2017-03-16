# include <iostream>
# include <algorithm>
# include <cstdio>
# include <cstring>
# include <vector>

using namespace std;

int B, M, a[1200];

bool check(long long time) {
    long long cnt = 0; 
    for(int i = 0; i < B; ++i) {
        cnt += (time + a[i] - 1) / a[i];
    }
    return (cnt < M);
}

int getans(long long time) {
    vector<pair<int,int> > tt;
    int wait, ord = M;
    for(int i = 0; i < B; ++i) {
        wait = a[i] - time % a[i];
        if(wait == a[i]) wait = 0;
        ord -= (time + wait) / a[i];
        tt.push_back(make_pair(wait,i+1));
    }
    sort(tt.begin(),tt.end());
    return tt[ord-1].second;
}

int main() {
    freopen("B.in","r",stdin);
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        scanf("%d%d", &B, &M);
        for(int i = 0; i < B; ++i) scanf("%d", &a[i]);
        long long L = 0, R = 100000000000000000LL + 1, M;
        while(R - L > 1) check(M=(L+R)/2) ? L=M:R=M;
        printf("Case #%d: %d\n", cas, getans(L));
    }
}

