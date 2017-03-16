#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;


int n;
int a[26];
int main() {
    freopen("in","r",stdin);
    freopen("out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    { 
        int sum = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        printf("Case #%d:", cas + 1);
        while(true)
        {
            printf(" ");
            int maxx = 0, k = -1;
            for(int i = 0; i < n; i++) if(a[i] > maxx) maxx = a[i], k = i;
            if(maxx > 0) printf("%c", k + 'A'), a[k]--, sum--;
            else break;

            if(sum != 2)
            {
                maxx = 0, k = -1;
                for(int i = 0; i < n; i++) if(a[i] > maxx) maxx = a[i], k = i;
                if(maxx > 0) printf("%c", k + 'A'), a[k]--, sum--;
            }
        }
        puts("");
    }

    return 0;
}
