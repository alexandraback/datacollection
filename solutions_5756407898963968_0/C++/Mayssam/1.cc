
#include <string.h>
#include <iostream>

using namespace std;

int main() {

    int t = 0;
    cin >> t;

    int arr[17];

    for (int i=0; i<t; i++) {
        memset(arr, 0, sizeof(arr));
        int ans = -1;
        int cnt = 0;
        cin >> ans;
        if (ans < 1) break;
        int r;
        for (int j=0; j<4; j++)
        for (int k=0; k<4; k++) {
            cin >> r;
            if (ans != j+1) continue;
            arr[r]++;
            cnt++;
        }

        ans = -1;
        cin >> ans;
        if (ans < 1) break;
        for (int j=0; j<4; j++)
        for (int k=0; k<4; k++) {
            cin >> r;
            if (ans == j+1) continue;
            cnt -= arr[r];
            arr[r] = 0;
        }
        cout << "Case #" << (i+1) << ": ";
        if (cnt == 0) cout << "Volunteer cheated!\n";
        else if (cnt != 1) cout << "Bad magician!\n";
        else {
            for (int i=1; i<17; i++)
                if (arr[i]) cout << i << endl;
        }
    }

    return 0;
}
