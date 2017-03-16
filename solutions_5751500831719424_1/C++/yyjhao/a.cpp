#include <string>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int getCost(const vector<string>& strs) {
    vector<vector<pair<char, int> > > letters;
    for (int i = 0; i < strs.size(); i++) {
        char lastChar = strs[i][0];
        int count = 1;
        vector<pair<char, int> > cur;
        for (int j = 1; j < strs[i].size(); j++) {
            if (lastChar != strs[i][j]) {
                cur.push_back(make_pair(lastChar, count));
                lastChar = strs[i][j];
                count = 1;
            } else {
                count++;
            }
        }
        cur.push_back(make_pair(lastChar, count));
        letters.push_back(cur);
    }
    int len = letters[0].size();
    for (int i = 0; i < strs.size(); i++) {
        if (len != letters[i].size()) return -1;
    }

    int cost = 0;
    for (int i = 0; i < len; i++) {
        char c = letters[0][i].first;
        vector<int> nums;
        nums.push_back(letters[0][i].second);
        for (int j = 1; j < letters.size(); j++) {
            if (c != letters[j][i].first) {
                return -1;
            }
            nums.push_back(letters[j][i].second);
        }
        sort(nums.begin(), nums.end());
        int med = nums[nums.size() / 2];
        for (int i = 0; i < nums.size(); i++) {
            cost += abs(nums[i] - med);
        }
    }
    return cost;
}

int main() {
    int t;
    cin>>t;
    for(int ca = 0; ca < t; ca++) {
        int n;
        cin>>n;
        vector<string> strs(n);
        for (int i = 0; i < n; i++) {
            cin>>strs[i];
        }
        cout<<"Case #"<<(ca+1)<<": ";
        int cost = getCost(strs);
        if (cost == -1) {
            cout<<"Fegla Won"<<endl;
        } else {
            cout<<cost<<endl;
        }
    }
    return 0;
}