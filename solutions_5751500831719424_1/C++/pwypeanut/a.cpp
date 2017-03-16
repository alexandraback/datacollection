#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool dead = false;
int T, N;
string S[105], decomp;
vector<int> V[105];

void die() {dead=true;}

void decompose(int n) {
    string T = S[n];
    int prevptr = 0;
    int ptr = 0;
    for ( int i = 0; i < decomp.length(); i++ ) {
        if ( ptr == T.length() ) {
            die();
            return;
        }
        if ( T[ptr] != decomp[i] ) {
            die();
            return;
        }
        while ( T[ptr] == decomp[i] ) {
            ptr++;
            if ( ptr == T.length() ) break;
        }
        V[n].push_back(ptr - prevptr);
        prevptr = ptr;
    }
    if ( ptr != T.length() ) die();
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    cin >> T;
    for ( int tc = 1; tc <= T; tc++ ) {
        for ( int i = 0; i < 105; i++ ) V[i].clear();
        dead = false;
        decomp = "";
        cin >> N;
        int ans;
        for ( int i = 0; i < N; i++ ) cin >> S[i];
        for ( int i = 0; i < S[0].length(); i++ ) {
            if ( i + 1 == S[0].length() ) decomp += S[0][i];
            else if ( S[0][i] != S[0][i + 1] ) decomp += S[0][i];
        }
        for ( int i = 0; i < N; i++ ) {
            decompose(i);
            if (dead) goto dead1;
        }
        ans = 0;
        for ( int i = 0; i < decomp.length(); i++ ) {
            int minsum = 2000000;
            for ( int j = 0; j <= 105; j++ ) {
                int sum = 0;
                for ( int k = 0; k < N; k++ ) sum += abs(j - V[k][i]);
                minsum = min(minsum, sum);
            }
            ans += minsum;
        }
        printf("Case #%d: %d\n", tc, ans);
        continue;       
        dead1:
            printf("Case #%d: Fegla Won\n", tc);
    }
}
