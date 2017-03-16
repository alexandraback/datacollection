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

const int M = 1000 + 5;
const int INF = 0x3f3f3f3f;
const bool debug=false;

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

LL barber[M];
int N;
int B;

LL get_count(int pos, LL tt) {
    return ((tt - 1)/barber[pos -1]) + 1;
}

LL get_pos(LL mid, int pos) {
    LL total_pos = 0;
    for(int i = 1;i<= pos;++i) {
        total_pos += get_count(i, mid);
    }

    for(int i = pos + 1; i<= B; ++i) {
        total_pos += get_count(i, mid - 1);
    }

    return total_pos;
}

bool search(int pos) {

    LL lo = 1;
    LL hi = (LL) 100009 * (LL) 1000000000 + (LL) 100;

    while( lo <= hi) {
        LL mid = lo + (hi-lo)/2;

        LL mid_pos = get_pos(mid, pos);

        DB(lo);DB(hi);
        DB(mid); DB(mid_pos);


        if ( mid_pos == N && ((mid  -1 )% barber[pos-1]) == 0) {
            DB(mid);
            return true;
        }

        if( mid_pos >= N)  {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return false;
}

int main() {

    int tc;
    scanf("%d",&tc);

    for(int t=1;t<=tc;++t) {
        scanf("%d %d",&B, &N);

        int x;
        for(int i=0;i<B;++i) {
            scanf("%d", &x);
            barber[i] = x;
        }

        for(int i=1;i<=B;++i) {
            if(search(i)) {
                printf("Case #%d: %d\n",t,i);
                break;
            }

        }
    }
    return 0;
}

