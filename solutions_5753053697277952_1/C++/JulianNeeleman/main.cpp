#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> p(N);
        int tot = 0;
        for(int i = 0; i < N; i++) {
            cin >> p[i];
            tot += p[i];
        }

        cout << "Case #" << t << ": ";

        while(tot > 0) {
            int max_v = 0, m = -1;
            for(int i = 0; i < N; i++) {
                if(p[i] > max_v) {
                    max_v = max(max_v, p[i]);
                    m = i;
                }
            }
            cout << (char)(m + 'A');
            p[m]--;
            tot--;
            if(tot % 2 == 0) cout << " ";
        }

        cout << endl;
    }
    return 0;
}
