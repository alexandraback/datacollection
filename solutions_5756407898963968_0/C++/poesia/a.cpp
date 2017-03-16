#include <iostream>
#include <set>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int r;
        cin >> r;

        set<int> row, possibilities;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int x;
                cin >> x;

                if (i + 1 == r)
                    row.insert(x);
            }
        }

        cin >> r;

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                int x;
                cin >> x;

                if (i + 1 == r && row.count(x))
                    possibilities.insert(x);
            }

        cout << "Case #" << tc << ": ";

        if (possibilities.size() > 1)
            cout << "Bad magician!\n";
        else if (possibilities.size() == 0)
            cout << "Volunteer cheated!\n";
        else
            cout << *possibilities.begin() << '\n';
    }

    return 0;
}

