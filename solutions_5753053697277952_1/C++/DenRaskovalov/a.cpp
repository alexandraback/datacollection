#include <cstdio>
#include <cstdlib>

#include <vector>

using namespace std;

typedef vector<int> IntVector;

inline bool hasMajority(const IntVector& v, int p1, int p2, int j, int sum) {
    int count = v[j];
    if (j == p1) {
        --count;
    }
    if (j == p2) {
        --count;
    }
    return 2*count > sum;
}

inline bool hasMajority(const IntVector& v, int p1, int j, int sum) {
    int count = v[j];
    if (j == p1) {
        --count;
    }
    return 2*count > sum;
}

int main() {
    int nT;
    scanf("%d", &nT);

    for (int t = 0; t < nT; ++t) {
        int n;
        scanf("%d", &n);
        IntVector v(n);
        int sum = 0;
        for (size_t i = 0; i < n; ++i) {
            scanf("%d", &(v[i]));
            sum += v[i];
        }
        printf("Case #%d:", t + 1);
        while (sum) {
            int maxp1;
            int maxp2;
            int max1 = 0;
            int max2 = 0;
            bool found = false;
            for (int p1 = 0; p1 < n; ++p1) {
                if (v[p1]) {
                    for (int p2 = p1 + 1; p2 < n; ++p2) {
                        if (v[p2]) {
                            int j = 0;
                            while ( (j < n) && !hasMajority(v, p1, p2, j, sum - 2) ) {
                                ++j;
                            }
                            if (j == n) {
                                found = true;
                                if (v[p1] > max1 || ((v[p1] == max1) && (v[p2] > max2))) {
                                    max1 = v[p1];
                                    max2 = v[p2];
                                    maxp1 = p1;
                                    maxp2 = p2;
                                }
                            }
                        }
                    }
                }
            }
            if (found) {
                printf(" %c%c", 'A' + maxp1, 'A' + maxp2);
                --v[maxp1];
                --v[maxp2];
                sum -= 2;
            } else {
                int max = 0;
                for (int p1 = 0; p1 < n; ++p1) {
                    if (v[p1]) {
                        int j = 0;
                        while ( (j < n) && !hasMajority(v, p1, j, sum - 1) ) {
                            ++j;
                        }
                        if (j == n) {
                            found = true;
                            int sm = v[p1];
                            if (sm > max) {
                                max = sm;
                                maxp1 = p1;
                            }
                        }
                    }
                }
                if (found) {
                    printf(" %c", 'A' + maxp1);
                    --v[maxp1];
                    --sum;
                } else {
                    fprintf(stderr, "!!!No move %d %d\n", n, sum);
                    exit(1);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
