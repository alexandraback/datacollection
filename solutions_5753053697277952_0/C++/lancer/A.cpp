#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int ara[200];

void input(void)
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&ara[i]);
}

bool finish(void)
{
    for(int i=0;i<n;++i)
        if(ara[i]>1)
            return false;
    return true;
}

void solve(void)
{
    if(n==2) {
        while(ara[0]>ara[1]) {
            printf(" A");
            ara[0]--;
        }
        while(ara[1]>ara[0]) {
            printf(" B");
            ara[1]--;
        }
        while(ara[0]) {
            printf(" AB");
            ara[0]--;
        }
        puts("");
        return;
    }
    while(!finish()) {
        int ind = max_element(ara,ara+n) - ara;
        ara[ind]--;
        printf(" %c",'A'+ind);
    }
    if(n&1) {
        for(int i=0;i<n-2;++i)
            printf(" %c",'A'+i);
        printf(" %c%c",'A'+n-2,'A'+n-1);
    } else {
        for(int i=0;2*i<n;++i)
            printf(" %c%c",'A'+i,'A'+n-1-i);
    }
    puts("");
}

int main(void)
{
    int T; scanf("%d",&T);
    for(int i=1;i<=T;++i) {
        printf("Case #%d:",i);
        input();
        solve();
    }
    return 0;
}
