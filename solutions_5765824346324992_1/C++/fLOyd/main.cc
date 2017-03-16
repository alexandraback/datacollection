#include <iostream>
#include <vector>

const int MAXB = 1005;

int caces, barbers, n;
int m[MAXB];
int ans;

long count(int b, long minutes) {
    long result = 0;
    for (int i = 0; i < barbers; ++i) {
        result += minutes / m[i] + 1;
        if (minutes % m[i] == 0 && i > b) {
            result--;
        }
    }
    return result;
}

int solve() {
    for (int b = 0; b < barbers; ++b) {
        int left = 0, right = n - 1, mid;
        long c;
        while (left <= right) {
            mid = (left + right) / 2;
            c = count(b, (long)mid * m[b]);
            if (c == n) {
                return b + 1;
            } else if (c < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    std::cin >> caces;
    for (int c = 0; c < caces; ++c) {
        std::cin >> barbers >> n;
        for (int i = 0; i < barbers; ++i) {
            std::cin >> m[i];
        }
        std::cout << "Case #" << c + 1 << ": " << solve() << std::endl;
    }
    return 0;
}
