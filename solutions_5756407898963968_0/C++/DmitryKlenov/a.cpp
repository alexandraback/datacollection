#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <set>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()

set<int> getCards() {
    set<int> s;
    int row;
    cin >> row;
    forn(i, 4)
        forn(j, 4) {
            int tmp;
            cin >> tmp;

            if (i + 1 == row) s.insert(tmp);
        }
    return s;
}

void solveCase() {
    set<int> a = getCards(), b = getCards();

    vector<int> v(4);
    vector<int>::iterator rs = set_intersection(all(a), all(b), v.begin());
    v.resize(rs - v.begin());

    switch (v.size()) {
        case 1: printf("%d\n", v[0]); break;
        case 0: printf("Volunteer cheated!\n"); break;
        default: printf("Bad magician!\n");
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int tk;
    scanf("%d", &tk);
    for(int tc = 1; tc <= tk; ++tc) {
        printf("Case #%d: ", tc);
        solveCase();
        cerr << "Case #" << tc << " is solved." << endl;
    }
    return 0;
}