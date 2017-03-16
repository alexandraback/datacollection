#include<bits/stdc++.h>

using namespace std;

void solve() {
    int a = 0, b = 0;

    int n;
    scanf("%d", &n);

    vector<int> data;
    for(int i =0 ; i < n ; i++) {
        int v;
        scanf("%d", &v);
        data.push_back(v);
    }

    int last = data[0];

    int oh = 0;
    for(int i =1 ; i < n; i++) {
        if(data[i] < last) {
            a+= last - data[i];
            oh = max(oh, last-data[i]);
        }
        last = data[i];
    }
    for(int i =0 ; i < n-1; i++) {
        b+= min(data[i], oh);
    }
    if(data[n-1] > data[n-2] && data[n-1] - data[n-2] != oh) {
        //  b+= data[n-1] - data[n-2];
    }

    printf("%d %d\n", a, b);
}



int main() {
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++) {
        printf("Case #%d: ",i);
        solve();
    }
}
