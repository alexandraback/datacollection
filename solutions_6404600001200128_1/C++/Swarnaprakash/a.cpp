// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 105;
const int INF = 0x3f3f3f3f;
const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int main() {

    int tc;
    scanf("%d",&tc);

    for(int t=1;t<=tc;++t) {
        int n;
        scanf("%d",&n);

        int mushroom[n];
        for(int i=0;i<n;++i) scanf("%d", &mushroom[i]);

        int method_1_min = 0;

        for(int i=1;i<n;++i) {
            method_1_min += max(0, mushroom[i-1] - mushroom[i]);
        }

        int method_2_10_x_rate = 0;
        for(int i=1;i<n;++i) {
            method_2_10_x_rate = max(method_2_10_x_rate, mushroom[i-1] - mushroom[i]);
        }

        int method_2_min = 0;
        for(int i=1;i<n;++i) {
            method_2_min += min(mushroom[i-1], method_2_10_x_rate);
        }

        printf("Case #%d: %d %d\n",t,method_1_min, method_2_min);
    }
    return 0;
}

