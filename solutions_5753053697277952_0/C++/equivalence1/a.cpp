#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; i++)
#define what_is(x) cerr << #x << ": " << x << endl;

#define file "f"

using namespace std;

char letter[27];
int a[27];
int T, n;

void solve() {
    static int test_case = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;

                char cmp = letter[i];
                letter[i] = letter[j];
                letter[j] = cmp;
            }
        }
    }

    cout << "Case #" << ++test_case << ": ";

    int i = n;
    while (i != 0) {
        while (a[i] > a[i - 1]) {

            int j = i;
            if ((n - i + 1) % 2 == 1) {
                 cout << letter[j] << " ";
                 a[j]--;
                 j++;
            }

            while (j < n) {
                a[j]--, a[j + 1]--;
                cout << letter[j] << letter[j + 1] << " ";
                j += 2;
            }
        }

        i--;
    }

    cout << "\n";
}

int main(void) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);

    ios_base::sync_with_stdio(false);

    cin >> T;
    forn(t, T) {
        cin >> n;
        forn(i, n) {
            cin >> a[i + 1];
            letter[i + 1] = 'A' + i;
        }

        solve();
    }
}

