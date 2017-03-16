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

#define SIZE 100

int N;
string input[SIZE];
int num[SIZE][SIZE];
int tmp[SIZE];

int solve() {
    int tot = 0;

    string::iterator it=input[0].begin();
    string test = "";
    while (it != input[0].end()) {
        char c = *it;
        test += c;
        while (it != input[0].end() && *it == c) ++it;
    }

    for (int i = 0; i < N; ++i) {
        int j = 0;
        it = input[i].begin();
        while (it != input[i].end()) {
            num[i][j] = 0;
            char c = *it;
            if (j >= (int)test.size() || c != test[j]) return -1;

            while (it != input[i].end() && *it == c) {++it; ++num[i][j];}
            //cout << num[i][j] << endl;
            //cout << num[0][0] << endl;
            //cout << i << " " << j << endl;
            ++j;
        }
        if (j != (int)test.size()) return -1;
    }

    for (int j = 0; j < (int)test.size(); ++j) {
        for (int i = 0; i < N; ++i) {
            //cout << num[i][j] << endl;
            tmp[i] = num[i][j];
            //cout << tmp[i] << " ";
        }
        //cout << endl;

        sort(tmp,tmp+N);
        //cout << tmp[0] << " /// " << tmp[1] << endl;;
        while(tmp[0] < tmp[N-1]) {
            int min = tmp[0]; int f = 0;
            while (tmp[f] == min) ++f;
            
            int max = tmp[N-1]; int l = 0;
            while (tmp[N-1-l] == max) ++l;

            if (min == max) continue;

            if (f < l) {
                tot += f;
                f = 0;
                while (tmp[f] == min) ++tmp[f++];
            } else {
                tot += l;
                l = 0;
                while (tmp[N-1-l] == max) --tmp[N-1-(l++)];
            }
            //cout << tot << "ttt" << endl;
        }
    }
    return tot;
}


int main() {
    int numcase;

    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-test.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

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
