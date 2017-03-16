#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int testcase(0); testcase != t; ++testcase) {
        cout << "Case #" << testcase + 1 << ": ";
        int n;
        cin >> n;
        vector<string> s;
        string unique;
        vector<vector<int> > tab;
        bool possible(true);
        for(int i(0); i != n; ++i) {
            string temp;
            cin >> temp;
            if( i == 0) {
                char c = temp[0];
                unique += c;
                for(int j(1); j < temp.size(); ++j) {
                    if(temp[j] != c) {
                        c = temp[j];
                        unique += c;
                    }   
                }
            }
            s.push_back(temp);
            vector<int> tv;
            char c = temp[0];
            int len = 1;
            int ui = 0;
            if(c != unique[0]) possible = false;
            for(int j(1); j < temp.size(); ++j) {               
                if(temp[j] == c) {
                    ++len;
                } else {
                    ++ui;
                    tv.push_back(len);
                    len = 1;
                    c = temp[j];
                    if(c != unique[ui]) possible = false;
                }
            }
            tv.push_back(len);
            if(ui != unique.size() - 1) possible = false;
            tab.push_back(tv);
        }
        if(!possible) {
            cout << "Fegla Won" << endl;
            continue;
        }
        int cost(0);
        for(int i(0); i != tab[0].size(); ++i) {
            int min_cost(9999999);
            for(int j(1); j <= 100; ++j) {
                int temp_cost(0);
                for(int k(0); k != tab.size(); ++k) {
                    temp_cost += abs(j - tab[k][i]);
                }
                if(temp_cost < min_cost) min_cost = temp_cost;                
            }
            cost += min_cost;
        }
        cout << cost << endl;
        
    }
}
