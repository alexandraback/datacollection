#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <cctype>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;

#define pb push_back
#define FOR(i, N) for (int i = 0; i < N; i++)
#define FOR_1(i, N) for (int i = 1; i <= N; i++)
#define vi vector<int>
#define vii vector< vector<int> >
#define pii pair<int, int>
#define sz size()

typedef long long ll;
typedef unsigned long long ull;

const int null = 0;
const int INF = numeric_limits<int>::max();
const ll INF_LONG = numeric_limits<ll>::max();

int calculateRep(string S, char c) {
    int idx = 0;

    while (idx < S.size() && S[idx] == c)
        idx++;

    return idx;
}

int balance(vector<int> &rep) {
    int N = rep.size();

    //bounds
    int lo = rep[0];
    int hi = rep[0];

    for (int i = 0; i < N; i++) {
        lo = min(lo, rep[i]);
        hi = max(hi, rep[i]);
    }

    int ans = INF;

    for (int target = lo; target <= hi; target++) {
        int moves = 0;

        for (int i = 0; i < N; i++) {
            moves += abs(rep[i] - target);
        }

        ans = min(ans, moves);
    }

    return ans;
}

int main() {
    ifstream in("A-large.in");
    ofstream out("A-large.out");

    //ifstream in("A-small-attempt1.in");
    //ofstream out("A-small-attempt11.out");

    //ifstream in("A-small-attempt0.in");
    //ofstream out("A-small-attempt0.out");

    //ifstream in("A-small-sample.in");
    //ofstream out("A-small-sample.out");

    int T;
    in >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        in >> N;

        vector<string> strings(N);
        for (int i = 0; i < N; i++) {
            in >> strings[i];
        }

        int moves = 0;
        bool possible = true;

        while (strings[0].size() > 0) {
            char c = strings[0][0];
            vector<int> rep(N);

            for (int i = 0; i < N; i++) {
                if (strings[i][0] != c) {
                    possible = false;
                    break;
                }

                rep[i] = calculateRep(strings[i], c);
                strings[i] = strings[i].substr(rep[i], strings[i].size() - rep[i]);
            }

            if (!possible) {
                break;
            }

            moves += balance(rep);
        }

        for (int i = 0; i < N; i++) {
            if (strings[i] != "")
                possible = false;
        }

        if (possible) {
            out << "Case #" << t << ": " << moves << endl;
        }
        else {
            out << "Case #" << t << ": Fegla Won" << endl;
        }

    }

    in.close();
    out.close();
}
