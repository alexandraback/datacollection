#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int id = 1;
    while (t--)
    {
        int num[4];
        int r;
        cin >> r;
        for (int i=1; i<=4; i++) {
            for (int j=0; j<4; j++) {
                int v;
                cin >> v;
                if (i==r)num[j]=v;
            }
        }
        
        int ans = 0;
        cin >> r;
        for (int i=1; i<=4; i++) {
            for (int j=0; j<4; j++) {
                int v;
                cin >> v;
                if (i==r) {
                    for (int k=0; k<4; k++) {
                        if (num[k] == v) {
                            if (ans == 0)ans = v;
                            else if(ans > 0) ans = -1;
                        }
                    }
                }
            }
        }
        cout << "Case #" << id++ << ": ";
        if (ans == -1) cout << "Bad magician!";
        else if(ans == 0) cout << "Volunteer cheated!";
        else cout << ans;
        cout << endl;
    }
}
