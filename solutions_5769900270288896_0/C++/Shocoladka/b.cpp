#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int> > bal;
set<pair<int, pair<int, int> > > st;
int r, c, n;

int ox[] = {0, 0, -1, 1};
int oy[] = {-1, 1, 0, 0};

void reduce(int x, int y) {
    if (x < 0 || x >= r || y < 0 || y >= c || bal[x][y] == 0)
        return;
    auto fn = st.find(make_pair(bal[x][y], make_pair(x, y)));
    pair<int, pair<int, int> > s = *fn;
    
    st.erase(fn);
    s.first = s.first - 1;
    bal[x][y] -= 1;
    st.insert(s);
}

int main() {
    ifstream cin("input");
    ofstream cout("output");

    int t;
    cin >> t;

    for (int l = 0; l < t; l++) {
        cin >> r >> c >> n;
        bal = vector<vector<int>>(r, vector<int>(c));
        st.clear();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (r == 1 || c == 1) {
                    if ((i == 0 || i == r - 1) && (j == 0 || j == c - 1)) {
                        st.insert(make_pair(1, make_pair(i, j)));
                        bal[i][j] = 1;
                    } else {
                        st.insert(make_pair(2, make_pair(i, j)));
                        bal[i][j] = 2;
                    }
                } else if ((i == 0 || i == r - 1) && (j == 0 || j == c - 1)) {
                    st.insert(make_pair(2, make_pair(i, j)));
                    bal[i][j] = 2;
                } else if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {
                    st.insert(make_pair(3, make_pair(i, j)));
                    bal[i][j] = 3;
                } else {
                    st.insert(make_pair(4, make_pair(i, j)));
                    bal[i][j] = 4;
                }
            }
        }

        for (int i = 0; i < r * c - n; i++) {
            pair<int, int> top = (*(--st.end())).second;
            st.erase(--st.end());
            bal[top.first][top.second] = 0;
            for (int k = 0; k < 4; k++) {
                reduce(top.first + ox[k], top.second + oy[k]);
            }
        }
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans += bal[i][j];
            }
        }

        cout << "Case #" << l + 1 << ": " << ans / 2 << endl;
    }
}
