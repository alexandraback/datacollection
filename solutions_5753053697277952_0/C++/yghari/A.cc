#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

typedef unsigned long long u64;
typedef long long l64;

void preprocess() {
}

bool mygreat(pair<int, int> const & lhs, pair<int, int> const & rhs) {
    return (lhs > rhs);
}

void solve() {
    int N;
    cin >> N;
    vector<pair<int, int> > P(N);
    int nn;
    int curr;
    for (nn=0; nn<N; ++nn) {
        cin >> curr;
        P[nn] = make_pair(curr, nn);
    }

    bool done = false;
    do {
        sort(P.begin(), P.end(), mygreat);
        /*for (nn=0; nn<N; ++nn) {
            cerr << " " << nn << ": cnt = " << P[nn].first << ", party = " << P[nn].second << endl;
        }*/
        int lefttotal = 0;
        int bestparty = 0;
        // remove only top 2
        bestparty = max(P[0].first-2, P[1].first);
        lefttotal = P[0].first-2+P[1].first;
        for (nn=2; nn<N; ++nn) {
            bestparty = max(bestparty, P[nn].first);
            lefttotal += P[nn].first;
        }
        //cerr << "1. bestparty = " << bestparty << " left total = " << lefttotal << endl;
        if ((bestparty*2) <= lefttotal) {
            cout << char('A'+P[0].second) << char('A'+P[0].second) << " ";
            P[0].first -= 2;
            goto check;
        }

        bestparty = lefttotal = 0;
        // remove top 1 and second 1
        bestparty = max(P[0].first-1, P[1].first-1);
        lefttotal = P[0].first-1+P[1].first-1;
        for (nn=2; nn<N; ++nn) {
            bestparty = max(bestparty, P[nn].first);
            lefttotal += P[nn].first;
        }
        //cerr << "2. bestparty = " << bestparty << " left total = " << lefttotal << endl;
        if ((bestparty*2) <= lefttotal) {
            cout << char('A'+P[0].second) << char('A'+P[1].second) << " ";
            P[0].first -= 1;
            P[1].first -= 1;
            goto check;
        }

        bestparty = lefttotal = 0;
        // remove only top 1
        bestparty = P[0].first-1;
        lefttotal = P[0].first-1;
        for (nn=1; nn<N; ++nn) {
            bestparty = max(bestparty, P[nn].first);
            lefttotal += P[nn].first;
        }
        //cerr << "3. bestparty = " << bestparty << " left total = " << lefttotal << endl;
        if ((bestparty*2) <= lefttotal) {
            cout << char('A'+P[0].second) << " ";
            P[0].first -= 1;
            goto check;
        }

check:
        done = true;
        for (nn=0; nn<N; ++nn) {
            if (P[nn].first > 0) {
                done = false;
                break;
            }
        }
    } while (not done);
}

int main() {
    preprocess();
    int T;
    cin >> T;
    int tt;
    for (tt=1; tt<=T; ++tt) {
        cout << "Case #" << tt << ": ";
        solve();
        cout << endl;
    }
    return 0;
}

