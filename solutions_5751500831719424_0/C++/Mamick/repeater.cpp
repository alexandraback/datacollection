#include <string>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int counts[200];
int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; cases++) {
        int n;
        cin >> n;
vector<string> stringsss;
vector<int> positions;
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            stringsss.push_back(tmp);
            positions.push_back(0);
        }
        bool works = true;
        int num = 0;
        while (works) {
            bool done = false;
            if (positions[0] >= stringsss[0].length()) done = true;
            for (int i = 0; i < n; i++) {
                if (done == true && positions[i] < stringsss[i].length()) {
                    done = true;
                    works = false;
                }
                if (done == false && positions[i] >= stringsss[i].length()) {
                    done = true;
                    works = false;
                }
            }
            if (done) break;
            memset(counts, 0, sizeof(counts));
            char nextChar = stringsss[0][positions[0]];
            // cout << nextChar;
            for (int i = 0; i < n; i++) {
                // cout << positions[i] << " " << stringsss[i][positions[i]] <<  endl;
                int count = 0;
                while (positions[i] < stringsss[i].length() && stringsss[i][positions[i]] == nextChar) {
                    positions[i]++; count++;
                }
                 // cout << "asfsa" << count << endl;
                if (count == 0) {works = false; break;}
                counts[i] = count;
            }
            // cout << n <<  endl;
            if (!works) break;
            int minnum = 99999;
            for (int i = 1; i < 200; i++) {
                int curnum = 0;
                for (int j = 0; j < n; j++) {
                    curnum += (counts[j] > i ? (counts[j] - i) : (i - counts[j]));
                }
                if (curnum < minnum) minnum = curnum;
            }
            num += minnum;
            // cout << num << endl;
        }
        cout << "Case #" << cases << ": ";
        if (works) cout << num << endl;
        else cout << "Fegla Won" << endl;
    }
}