#include <bits/stdc++.h>
using namespace std;
#define clc(x) memset(x, 0, sizeof(x))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
typedef long long ll;
const ll mxn = 30;
int T;
int n, x;
int a[mxn];
int Sum() {
    int sum = 0;
    F1(i, n) sum += a[i];
    return sum;
}
int Big() {
    int mx = 0, mx1 = 0;
    int k = 0;
    F1(i, n) {
        if (mx < a[i]) {mx = a[i]; k = i;}
        if (mx1 < a[i] && k!= i) {mx1 = a[i]; x = i;}
    }
    return k;
}


int main() {
    freopen("/Users/akanork/Desktop/1.in", "r", stdin);
    freopen("/Users/akanork/Desktop/1.out", "w", stdout);
    scanf("%d", &T);
    int kase = 1;
    while (T--) {
        vector<int> ans;
        clc(a);
        scanf("%d", &n);
        F1(i, n) scanf("%d", &a[i]);
        while (Sum()) {
            int s = Big();
          // printf("x = %d\n", x);
         if (a[s]-1 > (Sum()-1)/2) {
                ans.pb(s+100);
                ans.pb(s+100);
                a[s]--;
                a[s]--;
            }
            else if (x && a[x] > (Sum()-1)/2) {
                ans.pb(s+100);
                ans.pb(x+100);
                a[s]--;
                a[x]--;
            }
            else {
                a[s]--;
                ans.pb(s);
            }

       
        }

        printf("Case #%d: ", kase++);
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] > 100) {
                char c1 = ans[i] - 100 - 1 + 'A';
                char c2 = ans[i+1] - 100 - 1 + 'A';
                i++;
                printf("%c%c ", c1, c2);
            }
            else{
                char c = ans[i] - 1 + 'A';
                printf("%c ", c);
            }
            
        } 
        printf("\n");

    }

    return 0;
}