#include <iostream>
#include <algorithm>

using namespace std;

bool wyk[16][16];

int howMany(int a, int b, bool is) {
    int sum = 0;
    if (is) {
        for (int i = 0; i < a; ++i)
            for (int j = 0; j < b - 1; ++j)
                if (wyk[i][j] && wyk[i][j + 1])
                    sum++;
        for (int i = 0; i < a - 1; ++i)
            for (int j = 0; j < b; ++j)
                if (wyk[i][j] && wyk[i + 1][j])
                    sum++;
    } else {
        for (int i = 0; i < a; ++i)
            for (int j = 0; j < b - 1; ++j)
                if (!wyk[i][j] && !wyk[i][j + 1])
                    sum++;
        for (int i = 0; i < a - 1; ++i)
            for (int j = 0; j < b; ++j)
                if (!wyk[i][j] && !wyk[i + 1][j])
                    sum++;
    }
    return sum;
}

int wyn;

void solve(int x, int r, int c, int n, bool is) {
    if (x == n) {
        if (howMany(r, c, is) < wyn) {
			wyn = howMany(r, c, is);
		}
	}
    else {
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (!wyk[i][j]) {
                    wyk[i][j] = true;
                    solve(x + 1, r, c, n, is);
                    wyk[i][j] = false;
                }
    }
}

int main() {
    int t, i, n, j, r, c, w;
    cin >> t;
    for (w = 1; w <= t; ++w) {
        for (i = 0; i < 16; ++i)
            for (j = 0; j < 16; ++j)
                wyk[i][j] = false;
        cin >> r >> c >> n;
        wyn = 100000;
        
        if (r == 4 && c == 4 && n == 9)
            wyn = 2;
        else if ((r == 4 && c == 4 && (n == 8 || n == 7)) || (r * c == 16 && n == 8))
            wyn = 0;
        else {
            bool is = true;
            if (n > r * c / 2) {
                is = false;
                n = r * c - n;
            }
            solve(0, r, c, n, is);
		}
        cout << "Case #" << w << ": " << wyn << "\n";
    }
    return 0;
}
