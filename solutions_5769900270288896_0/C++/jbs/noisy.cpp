#include <iostream>
using namespace std;

int sadness(int r, int c, int n) {
    int sad = 0;
    int odd = c%2;
    if (r == 1) {
        int half = c/2;
        if (n <= (half + odd)) return 0;
        if (n == half+1 + odd) return 1 + odd;
        return (n-half-1)*2 + 1+odd;
    }
    else if (r == 2) {
        if (n <= c) return 0;
        if (n <= (c+2)) return (n-c)*2;
        return 2*2 + (n-(c+2))*3;
    }
    else if (r == 3) {
        if (!odd) {
            if (n < 7) return 0;
            if (n == 7) return 2;
            if (n == 8) return 4;
            if (n < 12) return 4+(n-8)*3;
            return 17;
        }
        if (odd) {
            if (c == 3) {
                if (n < 6) return 0;
                return (n-5)*3;
            }
            // c == 5
            if (n < 9) return 0;
            if (n < 15) return (n-8)*3;
            return 6*3 + 4;
        }
    }
    else { // if (r == 4) {
        if (n < 9) return 0;
        if (n < 11) return (n-8)*2;
        if (n < 15) return 4 + (n-10)*3;
        //        if (n > 14)
        return 2*2 + 4*3 + (n-14)*4;
    }
    return sad;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int R, C, N;
        cin >> R >> C >> N;
        int minimum = (R < C) ? R : C;
        int maximum = (R > C) ? R : C;
        int sad = sadness(minimum, maximum, N);
        //        cerr << minimum << ' ' << maximum << ' ' << N << endl;
        cout << "Case #" << i << ": " << sad << endl;
    }
}
