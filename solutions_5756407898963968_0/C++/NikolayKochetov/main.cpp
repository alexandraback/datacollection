#include <set>
#include <iostream>

using namespace std;

int main() {
   freopen("A-small-attempt0.in", "rt", stdin);
   freopen("file.out", "wt", stdout);
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        size_t f, s;
        set < size_t > st;
        set < size_t > st2;
        cin >> f;
        for (size_t j = 0; j < 4; j++) {
            for (size_t k = 0; k < 4; k++) {
                size_t next;
                cin >> next;
                if (j + 1 == f)
                    st.insert(next);
            }
        }
        cin >> s;
        for (size_t j = 0; j < 4; j++) {
            for (size_t k = 0; k < 4; k++) {
                size_t next;
                cin >> next;
                if (j + 1 == s && st.find(next) != st.end())
                    st2.insert(next);
            }
        }
        cout << "Case #" << i + 1 << ": ";
        if (st2.size() == 0)
            cout << "Volunteer cheated!";
        else if(st2.size() > 1)
            cout << "Bad magician!";
        else
            cout << *st2.begin();
        cout << endl;
    }
    return 0;
}
