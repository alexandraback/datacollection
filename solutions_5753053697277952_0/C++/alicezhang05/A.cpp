#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Party {
    char name;
    int count;

    bool operator <(Party& other) const {
        return count > other.count;
    }
};

struct F {
    bool operator()(Party& lhs, Party& rhs) const {
        return lhs.count > rhs.count;
    }
};
// aa bb -> ab ab
// aaa bb cc -> a
// a b cc
// aa bbb c

// a / n < 1/2
// a-1 / n-1 < 1/2
// a-1   1
// n-1   2

// 2(a-1) < n-1
// 2/3
// 1/2

string solve(vector<int>& input) {
    vector<Party> senators;
    int total = 0;
    for (size_t i = 0; i < input.size(); ++i) {
        Party p;
        p.name = 'A' + i;
        p.count = input[i];
        senators.push_back(p);
        total += input[i];
    }
    sort(senators.begin(), senators.end(), F());

    string result;

    while (total > 0) {
        string cur;

        // Add a single senator
        cur.push_back(senators.front().name);
        senators.front().count--;
        if (senators.front().count == 0) {
            senators.erase(senators.begin());
        }
        --total;

        sort(senators.begin(), senators.end(), F());

        if (senators.front().count > total / 2) {
           cur.push_back(senators.front().name);
           senators.front().count--;
           if (senators.front().count == 0) {
                senators.erase(senators.begin());
           }
           --total;
           sort(senators.begin(), senators.end(), F());
        }
        
        result += result.empty() ? cur : ' ' + cur;
    }

    return result;

}

int main() {
    int T;
    int n;
    int count;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> n;
        vector<int> senators;
        while (n--) {
            cin >> count;
            senators.push_back(count);
        }
        cout << "Case #" << i << ": " << solve(senators) << endl;
    }
    return 0;
}
