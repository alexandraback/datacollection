#include <iostream>
#include <vector>

using namespace std;
int main() {
    int ncase;
    cin>>ncase;
    for (int nc = 1; nc <= ncase; nc++) {
        int n;
        cin>>n;
        vector<int> num;
        vector<int> diff;
        int maxdiff = -99999999;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin>>tmp;
            num.push_back(tmp);
            if (i > 0) {
                diff.push_back(num[i - 1] - num[i]);
                maxdiff = max(diff[i - 1], maxdiff);
            }
        }
        int ans1 = 0;
        int ans2 = 0;
        int i = 0;
        for (auto di: diff) {
            if (di > 0) {
                ans1 += di;
            }
            if (di == maxdiff) {
                ans2 += maxdiff;
            }
            else {
                ans2 += min(maxdiff, num[i]);
            }
            i++;
        }
        cout << "Case #" << nc << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}
