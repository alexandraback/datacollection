#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fi("date.in");
    ofstream fo("out.txt");

    int T;
    fi >> T;

    for (int k = 1; k <= T; k++) {
        int N;
        fi >> N;
        vector<int> placinte(N);

        for (int i = 0; i < N; i++) {
            fi >> placinte[i];
        }

        long long x = 0, y = 0, maxim = 0;

        for (int i = 0; i < N - 1; i++) {
            long long dif = placinte[i] - placinte[i + 1];
            if (dif > 0) {
                x += dif;
                if (dif > maxim) {
                    maxim = dif;
                }
            }
        }
        for (int i = 0; i < N - 1; i++) {
            y += min((long long)placinte[i], maxim);
        }

        fo << "Case #" << k << ": " << x << " " << y << endl;
    }

    return 0;
}
