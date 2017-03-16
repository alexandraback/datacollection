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

int r,c,n;

bool is_present(int x, int y, int mask) {

    int pos = x * c + y;

    return (mask&(1<<pos)) != 0;
}


void print_mask(int mask) {
    for(int i=0;i<r;++i) {
        for(int j=0;j<c;++j) {
            putchar(is_present(i,j,mask) ? '1' : '0');
        }

        puts("");
    }

}

int unhappiness(int mask) {

    int ans=0;
    for(int i=0;i<r;++i) {
        for(int j=0;j<c;++j) {

            if(!is_present(i,j,mask)) continue;

            int dx[]={1,-1,0,0};
            int dy[]={0,0,1,-1};

            for(int k=0;k<4;++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];


                if(ni>=0 && ni < r && nj>=0 && nj<c && is_present(ni,nj,mask)) ++ans;
            }

        }
    }

    return ans;
}

int main() {

    int tc;
    scanf("%d",&tc);

    for(int t=1;t<=tc;++t) {

        scanf("%d %d %d",&r,&c,&n);

        int cell_count = r * c;
        int ans=INF;
        for(int i=0;i<1<<cell_count;++i) {
            if(__builtin_popcount(i) != n) continue;
            ans = min(ans,unhappiness(i));
        }
        printf("Case #%d: %d\n", t, ans/2);
    }
    return 0;
}

