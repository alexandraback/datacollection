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
        int N, v[1000];
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> v[i];

        int sum1 = 0, sum2 = 0, max = 0;

        for (int i = 1; i < N; i++) {
            if (v[i-1] > v[i]) {
                int eaten = v[i-1] - v[i];
                sum1 += eaten;
                max = eaten > max ? eaten : max;
            }
        }

        for (int i = 0; i < N-1; i++)
            sum2 += v[i] < max ? v[i] : max;

        cout << "Case #" << testcase+1 << ": ";
        cout << sum1 << " " << sum2 << endl;
    }
    return 0;
}

// vim: set sw=4:
