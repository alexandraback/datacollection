#include <bits/stdc++.h>
using namespace std;

typedef long long        ll;
typedef long double      ld;
typedef double           dbl;

#define mp               make_pair
#define pb               push_back
#define sz(x)            (int)(x).size()
#define X                first
#define Y                second
#define all(x)           x.begin(),x.end()
#define y1               y11

#ifdef ROMCHELA
    #define dout(x)        {cout<<#x<<" = ";cout<<(x)<<'\n';}
    #define darr(a, s, n)  {cout<<#a<<" = ";for(int _=s;_<=n;_++)cout<<a[_]<<' ';cout<<'\n';}
    #define dspace()       {for(int _=0;_<10;_++)cout<<'-';cout<<'\n';}
#else
    #define dout(x)        (void)42
    #define darr(a, s, n)  (void)42
    #define dspace()       (void)42
#endif

const int maxn = 100 * 2000 + 10;


int a[5][5], b[5][5];

int main() {
#ifdef ROMCHELA
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int n;
    scanf("%d", &n);
    for (int p = 0; p < n; p++) {
        int currow1, currow2;
        scanf("%d", &currow1);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        scanf("%d", &currow2);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &b[i][j]);
            }
        }

        int cnt1[20], cnt2[20];
        for (int i = 0; i < 20; i++) {
            cnt1[i] = 0;
            cnt2[i] = 0;
        }

        for (int i = 0; i < 4; i++) {
            cnt1[a[currow1 - 1][i]]++;
            cnt2[b[currow2 - 1][i]]++;
        }
        
        
        printf("Case #%d: ", p + 1);
        int ans = -1;
        bool flag = true;
        for (int i = 1; i < 20; i++) {
            if (cnt1[i] && cnt2[i]) {
                if (ans == -1) {
                    ans = i;
                } else {
                    flag = false;
                    printf("Bad magician!\n");
                    break;
                }
            }
        }

        if (!flag) continue;
        if (ans == -1) printf("Volunteer cheated!\n");
        else printf("%d\n", ans);
    }

    
    return 0;
}
