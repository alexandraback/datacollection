/******************************************************************************\
*                         Author:  Dumbear                                     *
*                         Email:   dumbear[#at]163.com                         *
*                         Website: http://dumbear.com                          *
\******************************************************************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

int t;

void get(set<int>& s) {
    int row;
    scanf("%d", &row);
    for (int i = 0; i < 4; ++i) {
        int card;
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &card);
            if (i == row - 1)
                s.insert(card);
        }
    }
}

void solve() {
    set<int> s1, s2;
    get(s1);
    get(s2);
    vector<int> v;
    for (set<int>::iterator i = s1.begin(); i != s1.end(); ++i) {
        if (s2.find(*i) != s2.end()) {
            v.push_back(*i);
        }
    }
    printf("Case #%d: ", ++t);
    if (v.size() == 0) {
        puts("Volunteer cheated!");
    } else if (v.size() > 1) {
        puts("Bad magician!");
    } else {
        printf("%d\n", v[0]);
    }
}

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
