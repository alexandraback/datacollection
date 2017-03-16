#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<utility>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int n, T, kk, ans;
int a[105], l[105];
string s[105];

void solve(){
    memset(l, 0, sizeof(l)); // the left pointers
    bool flag = false;
    while (! flag){
        char curr = s[0][l[0]];
        for (int i = 0; i < n; ++i){
            int k = l[i];
            if (s[i][k] != curr){ // unmatched char, abort
                ans = -1;
                return;
            }
            k ++;
            while (k < s[i].length() && s[i][k] == s[i][k-1]) k++; // move 
            a[i] = k - l[i]; l[i] = k;

            if (k >= s[i].length()) flag = true; // some string ended
        }

        // check validality
        if (flag){
            for (int i = 0; i < n; ++i)
                if (l[i] < s[i].length()){
                    ans = -1;
                    return;
                }
        }

        sort(a, a + n);
        int mid = (a[(n) / 2]);
        for (int i = 0; i < n; ++i)
            ans += abs(a[i] - mid);
    }

}


int main(){

    cin >> T;

    while (T--){
        kk++; ans = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        solve();
        printf("Case #%d: ", kk);
        if (ans == -1) printf("Fegla Won\n");
        else printf("%d\n", ans);
    }

    return 0;
}
