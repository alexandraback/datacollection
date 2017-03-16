#include <bits/stdc++.h>

using namespace std;

struct ty {
    int val, cs;
};

bool cmp(ty x, ty y) {
    return x.val > y.val;
}

int main() {
    //freopen("1.i", "r", stdin);
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.ou", "w", stdout);

    int ts;
    cin >> ts;

    for (int t = 1; t <= ts; t++) {
      int n;
      cin >> n;
      ty a[n];
      int s = 0;
      for (int i = 0; i < n; i++) {
        cin >> a[i].val;
        a[i].cs = i;
        s += a[i].val;
      }

      int m = 0;
      string res = "";
      while (s > 0) {
        sort(a, a + n, cmp);

        if (a[0].val >= a[1].val + 2) {
            res = res + " " + char(a[0].cs + 65) + char(a[0].cs + 65);
            a[0].val -= 2;
            s -= 2;
        }
        else if (a[0].val == 1 && a[2].val == 1) {
            res = res + " " + char(a[0].cs + 65);
            a[0].val -= 1;
            s -= 1;
        } else {
            res = res + " " + char(a[0].cs + 65) + char(a[1].cs + 65);
            a[0].val--;
            a[1].val--;
            s -= 2;
        }
        
        int ma = 0;
        for (int i = 0; i < n; i++)
            max(ma, a[i].val);
        if (ma*2 > s) {
            cout << "FALSSSSSSSSSSSSSSS";
            break;
        }
      }
      cout << "Case #" << t << ":"; 
      cout << res << endl;      
    }
}
