/* 
 * File:   main.cpp
 * Author: juro
 *
 * Created on May 8, 2016, 11:09 AM
 */

#include <cstdlib>
#include <map>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<pair<int, int> > parties;
        int p[n];
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            parties.push_back(make_pair(tmp, j));
            p[j] = tmp;
        }
        sort(parties.rbegin(), parties.rend());
        int ind1 = parties[0].second;
        int ind2 = parties[1].second;
        printf("Case #%d:", i+1);
        while (p[ind1] > p[ind2]) {
            cout << " " << (char)('A'+ind1);
            p[ind1]--;
        }
        for (int j = 0; j < n; j++) {
            if ((j == ind1) || (j == ind2)) continue;
            while (p[j] > 0) {
                if (p[j] == 1) {
                    cout << " " << (char)('A'+j);
                    p[j]--;
                } else {
                    cout << " " << (char)('A'+j) << (char)('A'+j);
                    p[j] -= 2;
                }
            }
        }
        while(p[ind1] > 0) {
            cout << " " << (char)('A'+ind1) << (char)('A'+ind2);
            p[ind1]--;
            p[ind2]--;
        }
        cout << endl;
        
    }
    
    return 0;
}

