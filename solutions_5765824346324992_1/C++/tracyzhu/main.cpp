#include <iostream>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <numeric>
#include <list>
#include <stack>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <functional>

#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef  long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VII;
typedef priority_queue<int> PQI;
const int Mod = 1e9 + 7;
inline LL FIX(LL a) {return (a % Mod + Mod) % Mod;}
#define MP(x,y) make_pair(x,y)
#define LEN(x) ((int)x.length())
#define SZ(x) ((int)x.size())
#define take(x,y) (((x)>>(y)) & 1ll)
#define mv(n) (1<<(n))
#define what_is(x) cerr << #x << " is " << x << endl;
#define eb emplace_back
#define pb push_back
#define UNQ(x) (sort(begin(x),end(x)),x.erase(unique(begin(x),end(x)),end(x)))


const int N = 1000 + 5;
LL n,B,b[N];

LL cal(int i) {
    LL l = 0,r = n;
    LL ret = n;
    LL retv = -1;
    while(l <= r) {
        LL mid = (l + r) / 2;
        LL t = (LL)mid * b[i];
        LL sum = mid;
        for(int j = 1;j <= B;j++) {
            if(j < i) {
                sum += t / b[j] + 1;
            }else if(j > i) {
                if(t % b[j] == 0) {
                    sum += t / b[j];
                }else sum += t / b[j] + 1;
            }
        }
        if(sum >= n - 1) {
            ret = mid;
            retv = sum;
            r = mid - 1;
        }else l = mid + 1;
    }
    return retv;
}
int main(){
    
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T,cas = 0;
    scanf("%d",&T);
    
    while(T--) {
        scanf("%lld %lld",&B,&n);
        for(int i = 1;i <= B;i++) {
            scanf("%lld",&b[i]);
        }
        int ret = 0;
        for(int i = 1;i <= B;i++) {
            LL tmp = cal(i);
            //printf("cal i: %d\n",tmp);
            if(tmp == n - 1) {
                ret = i;
                break;
            }
        }
        printf("Case #%d: %d\n",++cas,ret);
    }
    
    

    
    return 0;
}





