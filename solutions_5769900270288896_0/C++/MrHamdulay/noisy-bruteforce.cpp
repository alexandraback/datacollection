#include <iostream>
#include <bitset>

using namespace std;

bool occupied(unsigned int bitvector, int R, int C, int r, int c) {
    return (bitvector & (1<<(r*C + c))) != 0;
}

int unhappiness(int R, int C, unsigned int bitvector) {
    int unhappy = 0;
    for (int r=0; r<R; r++) {
        for(int c=0; c<C; c++) {
            if (!occupied(bitvector, R, C, r, c))
                continue;
            if (r>0 and occupied(bitvector, R, C, r-1, c))
                unhappy++;
            if (c>0 and occupied(bitvector, R, C, r, c-1))
                unhappy++;
        }
    }
    return unhappy;
}

int main() {
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        int R, C, N;
        cin >> R >> C >> N;

        int minHappiness = R*C*10;
        for (unsigned int i=0; i<(1<<(R*C)); i++) {
            if (__builtin_popcount(i) == N) {
                minHappiness = min(minHappiness, unhappiness(R, C, i));
            }
        }
        cout<<"Case #"<<(t+1)<<": "<<minHappiness<<"\n";
    }
}
