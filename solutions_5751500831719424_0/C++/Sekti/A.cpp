#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void normalise(string s, string &normalised, vector<int> &sizes) {
    char curr = s[0];
    int runLen = 0;
    normalised = "";
    s += "$";
    
    for(char c: s) {
        if (c != curr) {
            normalised += curr;
            curr = c;
            sizes.push_back(runLen);
            runLen = 1;
        } else {
            runLen++;
        }
    }
}

int costfor(vector<int> &lengths) {
    vector<int>::iterator posmed = lengths.begin() + lengths.size() / 2;
    nth_element(lengths.begin(), posmed, lengths.end());
    int med = *posmed;
    
    int c = 0;
    for(int l : lengths) {
        c += abs(l - med);
    }
    
    return c;
}

int main() {
    int T; cin >> T;
    for(int t = 1; t <= T; ++t) {
        int N; cin >> N;
        
        vector<string> normalised(N);
        vector<vector<int>> lengths(N);
        
        for(int n = 0; n < N; ++n) {
            string s; cin >> s;
            normalise(s, normalised[n], lengths[n]);
        }
        
        cout << "Case #" << t << ": ";
        if(normalised != vector<string>(N, normalised[0])) {
            cout << "Fegla Won";
        } else {
            int c = 0;
            for(int p = 0; p < normalised[0].size(); ++p) {
                vector<int> v;
                for(auto &len: lengths) {
                    v.push_back(len[p]);
                }
                c += costfor(v);
            }
            cout << c;
        } cout << endl;
    }
}