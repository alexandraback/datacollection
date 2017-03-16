#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    int tn;
    cin >> tn;
    for (int ti = 1; ti <= tn; ++ti) {
        cout << "Case #" << ti << ": ";
        int n;
        cin >> n;
        vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            sum += v[i];
        }
        while (sum > 0) {
            int a = distance(v.begin(), max_element(v.begin(), v.end()));
            cout << (char) ('A' + a);
            if (sum % 2 == 1) {
                cout << ' ';
            }
            --sum;
            --v[a];
        }
        cout << "\n";
    }
    cout << flush;

    return 0;
}
