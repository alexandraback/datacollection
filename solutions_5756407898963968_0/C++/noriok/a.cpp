#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

typedef vector<int> vi;

const int N = 4;

void calc(int fstRow, int fstCards[][N], int sndRow, int sndCards[][N]) {

    vi candidates;
    For(i, N) {
        For(j, N) {
            if (fstCards[fstRow][i] == sndCards[sndRow][j]) {
                int x = fstCards[fstRow][i];
                candidates.push_back(x);
            }
        }
    }

    if (candidates.empty()) {
        puts("Volunteer cheated!");
    }
    else if (candidates.size() == 1) {
        printf("%d\n", candidates[0]);
    }
    else {
        puts("Bad magician!");
    }
}

int main() {
    int ncases;
    scanf("%d", &ncases);

    For(cc, ncases) {
        int fstRow; scanf("%d", &fstRow);
        int fstCards[N][N];
        For(i, N) For(j, N) scanf("%d", &fstCards[i][j]);

        int sndRow; scanf("%d", &sndRow);
        int sndCards[N][N];
        For(i, N) For(j, N) scanf("%d", &sndCards[i][j]);

        printf("Case #%d: ", cc+1);
        calc(fstRow-1, fstCards, sndRow-1, sndCards);
    }
}
