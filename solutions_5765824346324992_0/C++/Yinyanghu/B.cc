#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int M, N;

vector<int> A;

vector<int> B;

int main() {
    int T;
    scanf("%d", &T);    
    for (int test = 1; test <= T; ++ test) {
        scanf("%d %d", &N, &M);
        A.clear();
        for (int i = 0; i < N; ++ i) {
            int k;
            scanf("%d", &k);
            A.push_back(k);
        }
        int lcm = A[0];
        for (int i = 1; i < N; ++ i) {
            int k = gcd(lcm, A[i]);
            lcm = (A[i] / k) * lcm;
        }
        int single = 0;
        for (int i = 0; i < N; ++ i)
            single += lcm / A[i];
        M = M % single;
        B.clear();
        for (int i = 0; i < N; ++ i)
            B.push_back(0);
        int def = 0;
        for (int i = 1; i < N; ++ i)
            if (A[i] <= A[def]) def = i;
        int min = def;
        while (M --) {
            min = 0;
            for (int i = 1; i < N; ++ i)
                if (B[min] > B[i]) min = i;
            B[min] += A[min];
        }
        printf("Case #%d: %d\n", test, min + 1);
    }
    return 0;
}
