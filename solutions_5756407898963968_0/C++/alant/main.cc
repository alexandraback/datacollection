#include<iostream>
#include<set>

using namespace std;

int ar[4][4];
int br[4][4];

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int a;
        cin >> a;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> ar[i][j];
            }
        }
        int b;
        cin >> b;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> br[i][j];
            }
        }
        set<int> as, bs;
        for (int i = 0; i < 4; ++i) {
            as.insert(ar[a - 1][i]);
            bs.insert(br[b - 1][i]);
        }
        set<int> r;
        for (set<int>::const_iterator it = as.begin(); it != as.end(); ++it) {
            if (bs.count(*it)) {
                r.insert(*it);
            }
        }
        cout << "Case #" << t << ": ";
        if (r.size() == 0) {
            cout << "Volunteer cheated!";
        } else if (r.size() == 1) {
            cout << *r.begin();
        } else {
            cout << "Bad magician!";
        }
        cout << "\n";
    }
}
