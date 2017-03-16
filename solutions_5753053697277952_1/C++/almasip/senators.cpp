#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    int test;
    cin >> test;
    for (int tc=1; tc<=test; ++tc) {
        int n, sum=0;
        int t[30];
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> t[i];
            sum+=t[i];
        }
        cout << "Case #" << tc << ":";

        if (sum%2 !=0) {
            int* a = max_element(t, t+n);
            int pos = a - t;
            t[pos]--; sum--;
            cout << " " << char('A'+pos);
        }
        while (sum>0) {
            int* a = max_element(t, t+n);
            int pos = a - t;
            t[pos]--; sum--;
            cout << " " << char('A'+pos);
            a = max_element(t, t+n);
            pos = a-t;
            t[pos]--; sum--;
            cout << char('A' + pos);
        }


        cout << endl;
    }
}
