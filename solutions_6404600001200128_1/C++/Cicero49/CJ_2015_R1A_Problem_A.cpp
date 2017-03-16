#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++) {
        int n;
        cin >> n;

        int* intervalls = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> intervalls[j];
        }

        int y = 0;
        int maxDiff = 0;
        int last = intervalls[0];
        
        for(int j = 1; j < n; j++) {
            if(last - intervalls[j] > 0) {
                y += last - intervalls[j];
                if(last - intervalls[j] > maxDiff) {
                    maxDiff = last - intervalls[j];
                }
            }
            last = intervalls[j];
        }

        int z = 0;
        last = intervalls[0];

        for(int j = 1; j < n; j++) {
            z += min(last, maxDiff);
            last = intervalls[j];
        }

        cout << "Case #" << i << ": ";
        cout << y << " " << z;
        cout << endl;
    }

    return 0;
}

