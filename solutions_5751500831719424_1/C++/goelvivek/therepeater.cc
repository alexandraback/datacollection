/* 
 * File:   therepeater.cc
 * Author: vivek
 *
 * Created on May 3, 2014, 10:19 PM
 */

#include <cstdlib>

#include <iostream>
#include <cstdio>


#include <vector>
#include <set>
#include <algorithm>
#include <map>

#include <cmath>



using namespace std;
#define Int long int
#define UInt unsigned Int 

/*
 * 
 */
#define MAX_N 101

int compare(const void * a, const void * b) {
    return ( *(Int*) a - *(Int*) b);
}

int main(int argc, char** argv) {
    UInt t;
    cin >> t;
    char strings[MAX_N][MAX_N];
    for (UInt i = 1; i <= t; i++) {
        Int count = 0;
        UInt n;
        cin >> n;
        for (UInt j = 0; j < n; j++) cin >> strings[j];
        char current = strings[0][0];
        Int index[MAX_N] = {0};
        bool answer = true;

        while (answer) {
            //cout << current << endl;
            Int currentN[MAX_N] = {0};

            for (UInt j = 0; j < n; j++) {
                char temp = strings[j][index[j]];

                while (temp == current) {
                    currentN[j]++;
                    index[j]++;
                    if (temp == NULL) {
                        break;
                    }
                    temp = strings[j][index[j]];
                }

                if (currentN[j] == 0) {
                    count = -1;
                    answer = false;
                    break;
                }
            }

            if (answer) {
                qsort(currentN, n, sizeof (Int), compare);
                Int ans = currentN[n / 2];
                for (UInt j = 0; j < n; j++) {
                    count += abs(ans - currentN[j]);
                }

                if (current == NULL) {
                    break;
                }
                current = strings[0][index[0]];
            }
        }
        if (count != -1) {
            cout << "Case #" << i << ": " << count << endl;
        } else {
            cout << "Case #" << i << ": Fegla Won" << endl;
        }


    }
    return 0;
}

