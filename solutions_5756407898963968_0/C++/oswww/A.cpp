

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;



int main() {
    #ifdef OSW
    freopen("C:\\Users\\Oswww\\Desktop\\in.txt", "r", stdin);
    #endif // OSW
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    int t=0;
    while (T-(t++)) {
        set<int> s[2][4];
        int x[2];
        for (int k=0; k!=2; ++k) {
            cin >> x[k];
            --x[k];
            for (int i=0; i!=4; ++i) {
                for (int j=0; j!=4; ++j) {
                    int y;
                    cin >> y;
                    s[k][i].insert(y);
                }
            }
        }
        set<int> & s1 = s[0][x[0]];
        set<int> & s2 = s[1][x[1]];
        set<int> ss;
        for (auto d:s1) if (s2.count(d)) ss.insert(d);


        cout << "Case #" << t << ": ";
        if (ss.size()==1) cout << *ss.begin() << endl;
        else if (ss.size()==0) cout << "Volunteer cheated!" << endl;
        else  cout << "Bad magician!" << endl;
    }
}
