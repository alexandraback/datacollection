#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#define y1 _dfdfdfd


const int maxn = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;

int c[4][4];
int d[4][4];
 
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";
        int a, b;
        cin >> a;
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cin >> c[i][j];
        cin >> b;
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cin >> d[i][j];
        
        a--;
        b--;
        int cmask1 = 0, cmask2 = 0;
        for (int j = 0; j < 4; j++) {
            cmask1 |= 1 << c[a][j];
            cmask2 |= 1 << d[b][j];
        }
        int mask = cmask1 & cmask2;
        
        vector<int> v;
        for (int i = 1; i <= 16; i++) if (mask & (1 << i)) v.push_back(i);
        
        if (v.size() == 0) {
            cout << "Volunteer cheated!" << endl;
        } else if (v.size() == 1) {
            cout << v[0] << endl;
        } else {
            cout << "Bad magician!" << endl;
        }

    }

	return 0;
}
