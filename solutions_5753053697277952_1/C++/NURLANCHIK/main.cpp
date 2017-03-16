#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#pragma comment(linker, "/STACK:64000000")

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define sqr(x) ((x) * (x))
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 26;

int n;
int a[N];

bool valid() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > sum - a[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (true) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                found = true;
                break;
            }
        }
        if (!found) {
            break;
        }
        int ii = -1, jj = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (i == j || a[j] == 0) {
                    continue;
                }
                a[i]--;
                a[j]--;
                if (valid()) {
                    ii = i;
                    jj = j;
                    break;
                }
                a[i]++;
                a[j]++;
            }
            if (ii != -1) {
                break;
            }
        }
        if (ii != -1) {
            cout << (char)(ii + 'A') << (char)(jj + 'A') << " ";
        } else {
            for (int i = 0; i < n; i++) {
                if (a[i] == 0) {
                    continue;
                }
                a[i]--;
                if (valid()) {
                    ii = i;
                    break;
                }
                a[i]++;
            }
            cout << (char)(ii + 'A') << " ";
        }
    }
}

int main() {
    freopen("/Users/nurlan/Dropbox/Programming/Google/googleSmall/googleSmall/input", "r", stdin);
    freopen("/Users/nurlan/Dropbox/Programming/Google/googleSmall/googleSmall/output", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}