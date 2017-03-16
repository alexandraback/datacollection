#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

ifstream cin("A-large.in");
ofstream cout("A-large.out");

void solve(int N, string A[]) {
    vector<vector<int> > M(MAXN, vector<int>(MAXN));
    vector<int> K(MAXN);

    for (int i = 0;i < N;i++) {
        int s = A[i].size();

        string m;
        m.push_back(A[i][0]);
        int j, count, n;
        for (j = 1, count = 1, n = 0;j < s;j++, count++) {
            if (A[i][j] != A[i][j - 1]) {
                M[n][i] = count;
                count = 0;
                m.push_back(A[i][j]);
                n++;
            }
        }

        M[n][i] = count;

        A[i] = m;
    }

    for (int i = 1;i < N;i++)
        if (A[i] != A[i - 1]) {
            cout << "Fegla Won\n";
            return;
        }

    int s = A[0].size();

    /*cout << s << "\n";

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < s;j++)
            cout << A[i][j] << " " << M[j][i] << " ";
        cout << "\n";
    }*/


    for (int i = 0;i < s;i++) {
        sort(M[i].begin(), M[i].begin() + N);
    }

    /*for (int i = 0;i < s;i++) {
        for (int j = 0;j < N;j++) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }*/

    int p;

    if (N%2 == 0)
        p = N/2 - 1;
    else
        p = (N - 1)/2;

    int ans = 0;

    for (int i = 0;i < N;i++)
        for (int j = 0;j < s;j++)
            ans += abs(M[j][i] - M[j][p]);

    cout << ans << "\n";
    return;
}

int main() {

    int T, N;

    string A[MAXN];

    cin >> T;

    for (int t = 1;t <= T;t++) {
        cin >> N;

        for (int i = 0;i < N;i++)
            cin >> A[i];

        cout << "Case #" << t << ": ";
        solve(N, A);
    }

    return 0;
}
