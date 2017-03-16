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
const int MAXN = 1010;
int N;
int arr[MAXN];

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d", &N);
        for(int i=0;i<N;++i)
            scanf("%d", &arr[i]);

        ll ans1 = 0;
        for(int i=1;i<N;++i)
            ans1 += (arr[i-1]-arr[i]) > 0 ? (arr[i-1]-arr[i]) : 0; 

        ll ans2 = 0;
        int maxDiff = 0;
        for(int i=1;i<N;++i)
            if(arr[i-1] > arr[i])
                maxDiff = max(maxDiff, arr[i-1]-arr[i]);
        for(int i=0;i<N-1;++i) {
            if(arr[i] >= maxDiff)
                ans2 += maxDiff;
            else
                ans2 += arr[i];
        }

        //printf("Case #%d: %d %d\n", ii, ans1, ans2);
        cout << "Case #" << ii << ": " << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
