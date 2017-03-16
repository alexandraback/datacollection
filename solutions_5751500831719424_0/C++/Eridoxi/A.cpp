#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cmath>

// STL
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map> // contains multimap
#include <set> // contains multiset
#include <queue> // contains priority_queue
#include <deque>
#include <list>
#include <stack>

using namespace std;

typedef unsigned long long ul;
typedef long long ll;

#define SIZE 1000

int N;
string input[SIZE];

int solve() {
    int tot = 0;

    string::iterator it1=input[0].begin();
    string::iterator it2=input[1].begin();
    
    while (it1 != input[0].end()) {
        char c = *it1;
        //cout << c;
        int cnt = 0;
        while (it1 != input[0].end() && *it1 == c) {
            ++it1; ++cnt;
        }
        //cout << "/" << input[0] << "/";
        //cout << "/" << *it1 << "/";
        if (it2 == input[1].end() || *it2 != c) return -1;
        //cout << *it2;
        while (it2 != input[1].end() && *it2 == c) {
            ++it2; --cnt;
        }
        tot += cnt >= 0 ? cnt : -cnt;
    }
    //if (it2 != input[1].end()) {cout << *it2 << endl;return -1;}
    if (it2 != input[1].end()) return -1;

    return tot;
}


int main() {
    int numcase;

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> N;
        for  (int j = 0; j < N; ++j) {
            cin >> input[j];
        }
        int c = solve();
        if (c == -1)
            cout << "Case #" << i + 1 << ": " << "Fegla Won" << endl;
        else
            cout << "Case #" << i + 1 << ": " << c << endl;
    }

    return 0;
}
