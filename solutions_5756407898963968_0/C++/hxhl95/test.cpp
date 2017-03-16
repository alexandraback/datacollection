#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int ans, tmp;
        cin >> ans;
        vector<int> nums, possible;
        for (int i = 0; i < 16; i++) {
            cin >> tmp;
            if (i / 4 == ans-1)
                nums.push_back(tmp);
        }
        cin >> ans;
        for (int i = 0; i < 16; i++) {
            cin >> tmp;
            if (i / 4 != ans-1)
                continue;
            if (find(nums.begin(), nums.end(), tmp) != nums.end())
                possible.push_back(tmp);
        }
        cout << "Case #" << c << ": ";
        if (possible.empty())
            cout << "Volunteer cheated!" << endl;
        else if (possible.size() == 1)
            cout << possible[0] << endl;
        else
            cout << "Bad magician!" << endl;
    }

    return 0;
}
