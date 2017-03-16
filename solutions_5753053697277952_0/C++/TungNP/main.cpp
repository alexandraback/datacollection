//
//  main.cpp
//  A
//
//  Created by ianto on 5/8/16.
//  Copyright © 2016 TungNguyen. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> veci;

bool notEmpty(veci v){
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) {
            return true;
        }
    }
    return false;
}

int maxIndex(veci v){
    int idx = 0;
    int m = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > m) {
            m = v[i];
            idx = i;
        }
    }
    return idx;
}

bool major(veci v){
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > sum / 2) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
//    freopen("test.txt", "r", stdin);
//    freopen("A-small-attempt0.in.txt", "r", stdin);
//    freopen("A-large.in.txt", "r", stdin);
    
    int T; cin >> T;
    
    for (int Case = 1; Case <= T; Case++) {
        int N; cin >> N;
        
        veci P(N);
        string PN = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        vector<string> result;
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        
        while (notEmpty(P)) {
            int idx = maxIndex(P);
            string evac = "";
            evac.push_back(PN[idx]);
            P[idx] = P[idx] - 1;
            
            veci Pc = P;
            if (notEmpty(Pc)) {
                int idx2 = maxIndex(Pc);
                Pc[idx2] = Pc[idx2] - 1;
                if (!major(Pc)) {
                    P = Pc;
                    evac.push_back(PN[idx2]);
                }
            }
            result.push_back(evac);
        }
        
        
        cout << "Case #" << Case << ":";
        for (int i = 0; i < result.size(); i++) {
            cout << " " << result[i];
        }
        cout << endl;
    }
    
    return 0;
}
