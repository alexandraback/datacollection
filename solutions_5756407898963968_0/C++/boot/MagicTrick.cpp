
#include <cstdio>
#include <iostream>

#define ANSWERS 2
#define SIZE 4

using namespace std;

int main (void) {
    int cases, count, num, x;
    int answers[ANSWERS + 1];
    int rows[ANSWERS + 1][SIZE + 1];
    
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    
    cin >> cases;
    
    for (int t = 1; t <= cases; t++) {
        for (int k = 1; k <= ANSWERS; k++) {
            cin >> answers[k];
            
            for (int j = 1; j <= SIZE; j++) {
                for (int i = 1; i <= SIZE; i++) {
                    cin >> x;
                    
                    if (j == answers[k]) {
                        rows[k][i] = x;
                    }
                }
            }
        }
        
        cout << "Case #" << t << ": ";
        count = 0;
        
        for (int i = 1; i <= SIZE; i++) {
            for (int j = 1; j <= SIZE; j++) {
                if (rows[1][i] == rows[2][j]) {
                    count++;
                    num = rows[1][i];
                }
            }
        }
        
        if (count == 0) {
            cout << "Volunteer cheated!" << endl;
        } else if (count == 1) {
            cout << num << endl;
        } else {
            cout << "Bad magician!" << endl;
        }
    }
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
