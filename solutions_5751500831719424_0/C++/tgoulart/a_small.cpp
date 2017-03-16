#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int T;

    cin >> T;
    for (int t=1; t <= T; ++t) {
        int n;
        string a, b;
        cin >> n;
        cin >> a;
        cin >> b;

        bool valid = true;
        int steps = 0;
        int i = 0;
        int j = 0;
        while (valid && i < a.length() && j < b.length()) {
            if (a[i] != b[j]) {
                if (i > 0 && a[i] == a[i-1]) {
                    ++i;
                    ++steps;
                } else if (j > 0 && b[j] == b[j-1]) {
                    ++j;
                    ++steps;
                } else {
                    valid = false;
                }
            } else {
                ++i;
                ++j;
            }
        }
        steps += (a.length() - i);
        if (valid) {
            for (int k=i; k < a.length(); ++k) {
                if (a[k] != a[k-1]) {
                    valid = false;
                }
            }
        }
        steps += (b.length() - j);
        if (valid) {
            for (int k=j; k < b.length(); ++k) {
                if (b[k] != b[k-1]) {
                    valid = false;
                }
            }
        }

        cout << "Case #" << t << ": ";
        if (valid) {
            cout << steps << endl;
        } else {
            cout << "Fegla Won" << endl;
        }
    }
	
	return 0;
}
