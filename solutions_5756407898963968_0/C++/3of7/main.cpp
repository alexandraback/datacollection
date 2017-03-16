#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    cin >> T;
    int c[4][4][2];
    int r[2];
    set<int> s[2];
    for(int t = 1; t <= T; t++) {
        s[0].clear();
        s[1].clear();
        for(int i = 0; i < 2; i++) {
            cin >> r[i]; r[i]--;
            for(int y = 0; y < 4; y++) {
                for(int x = 0 ; x < 4; x++) {
                    cin >> c[y][x][i];
                    if(y == r[i]) s[i].insert(c[y][x][i]);
                }
            }
        }
        int na = 0, a = -1;
        set<int>::iterator it = s[0].begin();
        while(it != s[0].end()) {
            if(s[1].find((*it)) != s[1].end()) {
                na++;
                a = (*it);
            }
            ++it;
        }
        cout << "Case #" << t << ": ";
        if(na == 1) {
            cout << a;
        } else if(na > 1) {
            cout << "Bad magician!";
        } else {
            cout << "Volunteer cheated!";
        }
        cout << endl;
    }
}