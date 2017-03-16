#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int
main(void)
{
    int T;
    int t, i, j, n;
    int row_a, row_b;
    int msk_a, msk_b;
    
    cin >> T;

    for(t=1;t<=T;t++) {
        cin >> row_a;
        msk_a = msk_b = 0;
        for(i=1;i<=4;i++) {
            for(j=1;j<=4;j++) {
                cin >> n;
                if (i == row_a) {
                    msk_a |= (1 << n);
                }
            }
        }
        cin >> row_b;
        for(i=1;i<=4;i++) {
            for(j=1;j<=4;j++) {
                cin >> n;
                if (i == row_b) {
                    msk_b |= (1 << n);
                }
            }
        }
        if ((msk_a & msk_b) == 0) {
            cout << "Case #" << t << ": Volunteer cheated!" << endl;
        } else {
            n = -1;
            for(i=1;i<=16;i++) {
                if ((msk_a & msk_b) == (1 << i)) {
                    n = i;
                    break;
                }
            }
            if (n == -1) {
                cout << "Case #" << t << ": Bad magician!" << endl;
            } else {
                cout << "Case #" << t << ": " << n  << endl;
            }
        }

    }
    
    return 0;
}
