#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <set>

using namespace std;

int TC = 1, T, N;
int sen[26];

void cal(int party) {
    if (party == 0) {
        return;
    }
    int max1,max2,pos1,pos2;
    max1 = max(sen[0],sen[1]);
    max2 = min(sen[0],sen[1]);
    if (sen[0] < sen[1]) {
        pos1 = 1;
        pos2 = 0;
    } else {
        pos1 = 0;
        pos2 = 1;
    }
    for (int i = 2; i < N; i++) {
        if (sen[i] > max1) {
            max2 = max1;
            max1 = sen[i];
            pos2 = pos1;
            pos1 = i;
        } else if (sen[i] > max2) {
            max2 = sen[i];
            pos2 = i;
        }
    }
    if (max1 == 0) {
        return;
    }
    if (max1 == max2) {
        if (max1 == 1 && party == 3) {
            cout << char('A'+pos1) << " ";
            sen[pos1]--;
            return cal(party-1);
        } else {
            cout << char('A'+pos1) << char('A'+pos2) << " ";
            sen[pos1]--;
            sen[pos2]--;
            if (max1 == 1) {
                return cal(party-2);
            } else {
                return cal(party);
            }
        }
    } else if (max1-max2 == 1) {
        cout << char('A'+pos1) << " ";
        sen[pos1]--;
        if (max1 == 1) {
            return cal(party-1);
        } else {
            return cal(party);
        }
    } else {
        cout << char('A'+pos1) << char('A'+pos1) << " ";
        sen[pos1]--;
        sen[pos1]--;
        if (max1 == 1) {
            return cal(party-2);
        } else {
            return cal(party);
        }
    }
}

int main ()
{
    for (cin >> T; TC <= T; TC++) {
        memset(sen, 0, sizeof(sen));
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> sen[i];
        }
        cout << "Case #" << TC << ": ";
        cal(N);
        cout << endl;
    }
    return 0;
}