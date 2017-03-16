#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

const string path = "/Users/mac/Documents/cpp/Code Jam/";

const string IMPOSSIBLE = "IMPOSSIBLE";

const int N = 1000;

int main() {
    ifstream cin(path + "in");
    ofstream cout(path + "out");
    
    int T;
    cin >> T;
    for (int CT = 1;  CT <= T; CT ++) {
        int n;
        cin >> n;
        
        vector<int> a(n, 0);
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        
        cout << "Case #" << CT << ":";
        
        while (true) {
            int mi = 0;
            for (int i = 1; i < n; i ++) {
                if (a[i] > a[mi])
                    mi = i;
            }
            
            if (a[mi] == 0)
                break;
            
            a[mi] --;
            
            int rem = 0;
            for (int i = 0; i < n; i ++)
                rem += a[i];
            
            if (rem == 2 || rem == 0) {
                cout << " " << char(mi + 'A');
                continue;
            }
            
            int mj = 0;
            for (int i = 1; i < n; i ++) {
                if (a[i] > a[mj])
                    mj = i;
            }
            
            a[mj] --;
            
            cout << " " << char(mi + 'A') << char(mj + 'A');
        }
        
        cout << endl;
    }
    
    
    return 0;
}
