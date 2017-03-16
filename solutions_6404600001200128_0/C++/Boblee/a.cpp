#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1000+20;
int m[maxn];
int n;

int main() {

    int T;
    cin>>T;
    int cas = 1;
    while(T--) {
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>m[i];
        }

        int ans1 = 0;
        int ans2 = 0;
        int rate = 0;

        for(int i=1; i<n; i++) {
            if(m[i+1] < m[i]) { 
                ans1 += m[i] - m[i+1];
                rate = max(rate,m[i]-m[i+1]);
            }
        }
        
        for(int i=1; i<n; i++) {
            ans2 += min(rate,m[i]);
        }
        
        printf("Case #%d: %d %d\n",cas++,ans1,ans2);
            
    }
    return 0;
}


