#include <cstdio>
#include <iostream>

using namespace std;

int t, mas1[4], mas2[4], a, num;

int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> a;
        //cout << a << endl;
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (j == a - 1) {
                    cin >> mas1[k];
                    //cout << mas1[k] << " ";
                } else {
                    cin >> num;
                }
            }
        }
        //cout << endl;
        cin >> a;
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (j == a - 1) {
                    cin >> mas2[k];
                } else {
                    cin >> num;
                }
            }
        }
        int flag = 0;
        int mem = -1;
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (mas1[j] == mas2[k]) {
                    ++flag;
                    mem = j;
                }
            }
        }
        if (flag == 0) {
            printf("Case #%d: Volunteer cheated!\n", i + 1);
        } else if (flag > 1) {
            printf("Case #%d: Bad magician!\n", i + 1);
        } else {
            printf("Case #%d: %d\n", i + 1, mas1[mem]);
        }
    }
    return 0;
}