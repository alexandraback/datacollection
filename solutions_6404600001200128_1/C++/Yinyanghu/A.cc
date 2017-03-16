#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> A;

int N;


int main() {
    int T;
    scanf("%d", &T);    
    for (int test = 1; test <= T; ++ test) {
        scanf("%d", &N);
        A.clear();
        for (int i = 0; i < N; ++ i) {
            int k;
            scanf("%d", &k);
            A.push_back(k);
        }
        int max = -1;
        int resA = 0;
        for (int i = 1; i < N; ++ i)
            if (A[i] < A[i - 1]) {
                resA += A[i - 1] - A[i];
                if (A[i - 1] - A[i] > max)
                    max = A[i - 1] - A[i];
            }
        int resB = 0;
        if (resA != 0) {
            for (int i = 0; i < N - 1; ++ i) {
                resB += (A[i] < max) ? A[i] : max;
            }
        }
        printf("Case #%d: %d %d\n", test, resA, resB);
    }
    return 0;
}
