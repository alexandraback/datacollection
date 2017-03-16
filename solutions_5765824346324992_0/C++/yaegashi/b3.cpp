#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        int B, N, M[1000], W[1000] = {};
        cin >> B >> N;
        for (int i = 0; i < B; i++)
            cin >> M[i];

        vector<int> X;

        while (1) {
            int min = INT_MAX;
            for (int i = 0; i < B; i++)
                min = W[i] < min ? W[i] : min;
            if (min > 0) {
                bool done = true;
                for (int i = 0; i < B; i++)
                    if (min != W[i])
                        done = false;
                if (done)
                    break;
            }
            for (int i = 0; i < B; i++) {
                W[i] -= min;
                if (!W[i]) {
                    W[i] = M[i];
                    X.push_back(i);
                }
            }
        }

        //cout << X.size() << endl;

        int A = X[(N-1) % X.size()] + 1;

        cout << "Case #" << testcase+1 << ": ";
        cout << A << endl;
    }
    return 0;
}

// vim: set sw=4:
