#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAXB = 1010;
const int MAXS = 1e6+10;
int B, N;
int arr[MAXS];
set<int> numb[MAXS];
ll psum[MAXS];

ll gcd(ll a, ll b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a*b/gcd(a, b);
}

void seq() {
    for(int i=0;i<B;++i) {
        for(int j=0;j*arr[i] < MAXS;++j) {
            numb[j*arr[i]].insert(i+1);
        }
    }
    psum[0] = numb[0].size();
    for(int i=1;i<MAXS;++i)
        psum[i] = psum[i-1] + numb[i].size();
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        for(int i=0;i<MAXS;++i)
            numb[i].clear();

        scanf("%d %d", &B, &N);
        for(int i=0;i<B;++i)
            scanf("%d", &arr[i]);

        ll allLcm = 1;
        for(int i=0;i<B;++i)
            allLcm = lcm(allLcm, arr[i]);

        int cycle = 0;
        for(int i=0;i<B;++i)
            cycle += allLcm/arr[i];

        seq();
        int term = (N%cycle);
        if(term == 0)
            term = cycle;
        /*
        int index = upper_bound(psum, psum+cycle, term) - psum;
        if(index && term >= psum[index-1])
            term -= psum[index-1];

        int ans = -1;
        while(numb[index].size() == 0)
            --index;

        for(int x : numb[index]) {
            if(term == 0) {
                ans = x;
                break;
            }
            --term;
        }
        */
        int cnt = 1;
        int ans = -1;
        for(int i=0;cnt<=cycle;++i) {
            for(int b : numb[i]) {
                if(cnt == term) {
                    ans = b;
                    break;
                }
                ++cnt;
            }
            if(ans != -1)
                break;
        }
        printf("Case #%d: %d\n", ii, ans);
    }
    return 0;
}
