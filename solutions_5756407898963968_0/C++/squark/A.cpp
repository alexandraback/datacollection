#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

bool va[17];
vector<int> ans;

int main()
{
    #ifdef __FIO
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int i0 = 1;
    int T;
    scanf("%d", &T);
    for(i0 = 1; i0 <= T; i0++){
        int i, j, k;
        memset(va, true, sizeof va);
        for(i = 0; i < 2; i++){
            int x;
            scanf("%d", &x);
            for(j = 0; j < 4; j++)
                for(k = 0; k < 4; k++){
                    int y;
                    scanf("%d", &y);
                    if(j != x-1)
                        va[y] = false;
                }
        }
        
        ans.clear();
        
        for(i = 1; i <= 16; i++)
            if(va[i])
                ans.pb(i);
        
        printf("Case #%d: ", i0);
        if(ans.size() == 0){
            puts("Volunteer cheated!");
        }
        else if(ans.size() > 1){
            puts("Bad magician!");
        }
        else{
            printf("%d\n", ans[0]);
        }
    }
    return 0;
}
