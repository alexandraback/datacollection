#include <cmath>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>


using namespace std;

string red(string s) {
    stringstream ss;
    string l;
    ss << s[0];
    ss >> l ;
    
    string r = l ;
    for (int i = 1 ; i < s.size() ; i++) {
        if (s[i] != r[r.size()-1]) {
            r += s[i];
        }
    }
    return r;
}


int main() {
  
    int T;
    
    cin >> T;
    
    
    for (int _i = 0 ; _i < T; _i++){
        
        int n;
        int flag = 0;
        cin >> n;
        
        
        string t;
        cin >> t;
        
        string reduce = red(t);
        vector<vector<int> > value;
        value.resize(n);
        for (int i = 0 ; i < n ;i++) {
            value[i].resize(reduce.size());
        }
        
        int j=0;
        for (int i = 0 ; i < t.size() ; i++) {
            if (reduce[j] != t[i]) {
                j++;
            }
            value[0][j]++;
        }
        
        
        for (int i = 1 ; i < n ; i++) {
            
            cin >> t;
            
            if (reduce != red(t)) {
                flag = 1;
            }
            if (!flag) {
                int j=0;
                for (int k = 0 ; k < t.size() ; k++) {
                    if (reduce[j] != t[k]) {
                        j++;
                    }
                    value[i][j]++;
                }
            }
        }
        
        
        int r = 0;
        
        if (!flag) {
        
        for (int i = 0 ; i < value[0].size() ; i++) {
            int min = value[0][i];
            int max = value[0][i];
            
            for (int j = 1 ; j < n ; j++) {
                min = (min < value[j][i])? min : value[j][i];
                max = (max > value[j][i])? max : value[j][i];
            }
            
            int best = 10000;
            if (min == max) {
                best = 0;
            }
            
            for (int k = min ; k < max ; k++) {
                int current = 0;
                for (int j = 0 ; j < n ; j++) {
                    current += abs(value[j][i] - k);
                }
                best = (best < current)? best : current;
            }
            r += best;
        }
        }
        
        if (flag) {
            cout << "Case #" << _i+1 << ": " << "Fegla Won" << endl;
        }
        else {
            cout << "Case #" << _i+1 << ": " << r << endl;
        }
        
        
        
    }
    
    return 0;
}

