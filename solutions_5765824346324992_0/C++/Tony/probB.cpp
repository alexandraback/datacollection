
#include <algorithm>
#include <cassert>
#include <iostream>
#define MAXB 1024

using namespace std;

int B, N;
int M[MAXB];

long long getNumCut(long long totalTime) {
    long long numCut = 0;
    for (int i = 0; i < B; i++)
        numCut += (totalTime + M[i] - 1) / M[i];
    return numCut;
}

int solve() {
    if (N <= B)
        return N;

    long long low = 0, high = (1LL << 60);
    while (low < high) {
        long long mid = (low + high + 1) / 2;
        if (getNumCut(mid) >= N)
            high = mid - 1;
        else
            low = mid;
    }
    long long totalTime = low;
    int needed = (int) (N - getNumCut(totalTime));
    assert(needed <= B);

    // cerr << "time: " << totalTime << " needed: " << needed << endl;
    for (int i = 0; i < B; i++) {
        if (totalTime % M[i] == 0) {
            needed--;
            if (needed == 0)
                return i + 1;
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> B >> N;
        for (int i = 0; i < B; i++)
            cin >> M[i];
        cout << "Case #" << t << ": " << solve() << endl;
    }
}

