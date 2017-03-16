#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

typedef pair<char, int> chnum;
typedef vector<chnum> chword;

typedef vector<chword> chwords;

int solve(chwords chws) {
    int chsize = 0;
    for (int i=0; i<chws.size(); ++i) {
        if (chsize == 0) {
            chsize = chws[i].size();
        }
        if (chws[i].size() != chsize) {
            return -1;
        }
    }

    int total_min_tries = 0;
    for (int i=0; i<chsize; ++i) { // iterate through chars
        int min=999999999, max=0;
        char ch;
        ch=0x0;
        for (int j=0; j<chws.size(); ++j) {
            if (ch == 0x0) {
                ch = chws[j][i].first;
            }
            if (chws[j][i].first != ch) {
                return -1;
            }
            if (chws[j][i].second < min) {
                min = chws[j][i].second;
            }
            if (chws[j][i].second > max) {
                max = chws[j][i].second;
            }
        }
        set<int> repeats;
        for (int j=0; j<chws.size(); ++j) {
            repeats.insert(chws[j][i].second);
        }
        int min_tries = 999999999;
        for (set<int>::iterator iter=repeats.begin(); iter!=repeats.end(); ++iter) {
            int tries = 0;
            for (int j=0; j<chws.size(); ++j) {
                tries += abs(chws[j][i].second - *iter);
            }
            if (tries < min_tries ) {
                min_tries = tries;
            }
        }
        total_min_tries += min_tries;
    }
    return total_min_tries;
}

chword string2chwords(string s) {
    chword chw;
    char last = 0x0;
    int repeats = 0;
    for (int i=0; i<s.size(); ++i) {
        if (last != s[i]) {
            if (last != 0x0) {
                chw.push_back(chnum(last, repeats));
                repeats = 1;
                last = s[i];
            } else {
                last = s[i];
                ++repeats;
            }
        } else {
            ++repeats;
            last = s[i];
        }
    }
    chw.push_back(chnum(last, repeats));
    return chw;
}

int main(int argc, char** argv) {
    int T;
    int case_num = 0;
    for (cin >> T; T>0; --T) {
        int N;
        cin >> N;
        chwords chws;
        for (; N>0 ; --N) {
            string word;
            cin >> word;
            chword chw = string2chwords(word);
            chws.push_back(chw);
        }
        cout << "Case #" << ++case_num << ": ";
        int solution = solve(chws);
        if (solution == -1) {
            cout << "Fegla Won" << endl;
        } else {
            cout << solution << endl;
        }
    }
    return 0;
}
