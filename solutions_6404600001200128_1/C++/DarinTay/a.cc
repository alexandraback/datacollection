#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        int N;
        cin>>N;
        vector<int> M;
        int maxDiff = 0;
        int v1 = 0;
        for (int i=0;i<N;++i) {
            int m;
            cin>>m;
            M.push_back(m);
            if (i > 0) {
                maxDiff = std::max(maxDiff, M[i-1] - M[i]);
                v1 += std::max(0, M[i-1] - M[i]);
            }
        }

        int v2 = 0;
        for (int i=0;i<M.size() - 1;++i) {
            v2 += std::min(maxDiff, M[i]);
        }

        printf("Case #%d: %d %d\n", t, v1, v2);
    }
}
