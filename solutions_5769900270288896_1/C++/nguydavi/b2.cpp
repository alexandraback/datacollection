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

typedef pair<int, int> pii;
const int MAXN = 10010;
int R, C, N;
vector< vector<bool> > building;

bool isIn(int r, int c) {
    return r >= 0 && c >= 0 && r<R && c < C;
}

int unhappy() {
    int res = 0;
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j) {
            if(isIn(i+1, j) && building[i][j] && building[i+1][j])
                ++res;
            if(isIn(i, j+1) && building[i][j] && building[i][j+1])
                ++res;
        }

    /*
    for(int i=0;i<R;++i) {
        for(int j=0;j<C;++j)
            cout << building[i][j] << " ";
        cout << endl;
    }
    cout << "DEBUG " << res << endl;
    */
    return res;
}

int solve(bool mode) {
    int tenants = N;
    int r = 0, c = mode;

    while(r < R && tenants > 0) {
        if(isIn(r, c)) {
            building[r][c] = true;
            --tenants;
        }
        c+=2;
        if(c >= C) {
            ++r;
            c = (r+mode)%2;
        }
    }

    int index = 0;
    vector<pii> corners = {{0,0}, {0, C-1}, {R-1, 0}, {R-1, C-1}};
    while(tenants && index < corners.size()) {
        int rr = corners[index].first;
        int cc = corners[index].second;
        if(!building[rr][cc]) {
            building[rr][cc] = true;
            --tenants;
        }
        ++index;
    }

    c = 0;
    while(tenants && c < C) {
        if(!building[0][c]) {
            building[0][c] = true;
            --tenants;
        }
        ++c;
    }
    c = 0;
    while(tenants && c < C) {
        if(!building[R-1][c]) {
            building[R-1][c] = true;
            --tenants;
        }
        ++c;
    }

    r = 0;
    while(tenants && r < R) {
        if(!building[r][0]) {
            building[r][0] = true;
            --tenants;
        }
        ++r;
    }
    r = 0;
    while(tenants && r < R) {
        if(!building[r][C-1]) {
            building[r][C-1] = true;
            --tenants;
        }
        ++r;
    }

    r = 0, c = 0;
    while(tenants && r < R) {
        if(!building[r][c]) {
            building[r][c] = true;
            --tenants;
        }
        r += (c+1==C);
        c = (c+1)%C;
    }

    return unhappy();
}

int main() {
    int tc;
    cin >> tc;
    for(int ii=1;ii<=tc;++ii) {
        cin >> R >> C >> N;
        building.resize(R);
        for(int i=0;i<R;++i)
            building[i] = vector<bool>(C, false);
        int ans = solve(0);
        for(int i=0;i<R;++i)
            building[i] = vector<bool>(C, false);
        ans = min(ans, solve(1));
        cout << "Case #" << ii << ": " << ans << "\n";
    }
    return 0;
}
