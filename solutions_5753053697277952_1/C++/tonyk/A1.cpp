#include <iostream>

using namespace std;

int main(){
    int t;
    
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        
        int p[30];
        int sp = 0;
        int d = 0;
        for (int j = 0; j < n; j++) {
            cin >> p[j];
            if (p[j] != 0) d++;
            sp += p[j];
        }
        
        cout << "Case #" << i+1 << ":";
        if (d == 2) {
            int p1, p2;
            bool f = true;
            for (int j = 0; j < n; j++) {
                if (p[j] > 0) {
                    if (f) {
                        p1 = j;
                        f = false;
                    } else {
                        p2 = j;
                    }
                }
            }
            while (sp > 0) {
                cout << " " << (char)(p1 + 'A') << (char)(p2 + 'A');
                sp -= 2;
            }
        } else {
            while (sp > 0) {
                if (sp == 2) {
                    cout << " ";
                    for (int j = 0; j < n; j++) {
                        if (p[j] != 0) cout << (char)(j + 'A');
                    }
                    sp = 0;
                } else {
                    int mx = 0;
                    int idx;
                    for (int j = 0; j < n; j++) {
                        if (p[j] > mx) {
                            mx = p[j];
                            idx = j;
                        }
                    }
                    cout << " " << (char)(idx + 'A');
                    p[idx]--;
                    sp--;
                }
            }
        }
        
        cout << endl;
    }
    
    return 0;
}
