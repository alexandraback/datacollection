#include <cstdio>
#include <iostream>
using namespace std;

const int NMAX = 28;
int tests, N, A[NMAX];

void read() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
}

inline int getBest() {
    int bestV = -1, whichPos;
    for (int i = 1; i <= N; i++) {
        if (A[i] > bestV) {
            bestV = A[i];
            whichPos = i;
        }
    }

    return whichPos;
}

inline int getSndBest(int other) {
    int bestV = -1, whichPos;
    for (int i = 1; i <= N; i++) {
        if (A[i] > bestV && i != other) {
            bestV = A[i];
            whichPos = i;
        }
    }

    return whichPos;
}

inline string encode(int pos) {
    string result;
    result += (char)('A' + pos - 1);

    return result;
}

inline string encode(int pos1, int pos2) {
    return encode(pos1) + encode(pos2);
}

void solve() {
    bool first = true;

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += A[i];
    }
    if (sum & 1) {
        int pos = getBest();
        cout << encode(pos);
        first = false;
        A[pos]--;
    }

    int pos1, pos2;
    for (int i = 1; i <= sum / 2; i++, first = false) {
        pos1 = getBest(); pos2 = getSndBest(pos1);
        if (!first) {
            cout << " ";
        }
        cout << encode(pos1, pos2);

        A[pos1]--; A[pos2]--;
    }
    cout << "\n";
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        printf("Case #%d: ", test);

        read();
        solve();
    }
    return 0;
}