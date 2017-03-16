#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int T; cin >> T;
    
    for(int t = 1; t <= T; ++t) {
        vector<int> hits(17, 0);
        
        for(int tries = 1; tries <= 2; ++tries) {
            int theRow; cin >> theRow;
            
            for(int row = 1; row <= 4; ++row) {
                for(int col = 1; col <= 4; ++col) {
                    int n; cin >> n;
                    
                    if (row == theRow) {
                        hits[n]++;
                    }
                }
            }
        }
        
        auto maxe = max_element(hits.begin(), hits.end());
        
        cout << "Case #" << t << ": ";
        if (*maxe < 2) {
            cout << "Volunteer cheated!";
        } else if (--*maxe, *max_element(hits.begin(), hits.end()) == 2) {
            cout << "Bad magician!";
        } else {
            cout << maxe - hits.begin();
        }   cout << endl;
    }
}