#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, total = 0;
        pair<int, char> A[30];
        cin >> N;
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            total += num;
            A[i] = make_pair(-num, i + 'A');
        }
        cout << "Case #" << t + 1 << ": ";
        if (total % 2) {
            sort(&A[0], &A[N]);
            if (A[0].first == 0)
                break;
            cout << A[0].second;
            A[0].first++;
            cout << " ";

        }
        while (true) {
            sort(&A[0], &A[N]);
            if (A[0].first == 0)
                break;
            cout << A[0].second;
            A[0].first++;
            sort(&A[0], &A[N]);
            if (A[0].first == 0)
                break;
            cout << A[0].second;
            A[0].first++;
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}
