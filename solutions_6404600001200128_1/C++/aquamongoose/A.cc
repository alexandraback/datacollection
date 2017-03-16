#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
#define A first
#define B second
#define MP make_pair
#define PB push_back

const int MAXN = 1010;
int N;
int m[MAXN];

int get_eaten(int b) {
    int ret = 0;
    for (int i=0; i+1<N; i++) {
        ret += min(m[i], b);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int kase=1; kase<=T; kase++) {
        cout << "Case #" << kase << ": ";
        cin >> N;
        for (int i=0; i<N; i++) {
            cin >> m[i];
        }
        int a = 0;
        for (int i=1; i<N; i++) {
            if (m[i] < m[i-1]) {
                a += m[i-1]-m[i];
            }
        }
        int bb = 0;
        for (int i=1; i<N; i++) {
            bb = max(bb, m[i-1]-m[i]);
        }
        cout << a << ' ' << get_eaten(bb) << '\n';
    }
    return 0;
}
