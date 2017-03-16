#include <bits/stdc++.h>

using namespace std;

int a[30];

int main(){
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t; cin >> t;
    int T = 0;
    while(t --){
        T ++;
        int n; cin >> n;
        cout << "Case #" << T << ": ";
        int sum = 0;
        for(int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
        while(sum){
            int x = 0;
            int b[30];
            int mx = -1, id = -1;
            for(int i = 0; i < n; ++i){
                if(a[i] > 0){
                    b[x] = i;
                    x ++;
                }
                if(a[i] > mx){
                    mx = a[i];
                    id = i;
                }
            }
            if(x == 2 && a[b[0]] == a[b[1]]){
                cout  << char('A' + b[0]) << char('A' + b[1]) << " ";
                a[b[0]] --; a[b[1]] --; sum -= 2;
                continue;
            }
            a[id] --; sum --;
            cout << char((char)'A' + id) << " ";
        }
        cout << "\n";
    }
    return 0;
}
