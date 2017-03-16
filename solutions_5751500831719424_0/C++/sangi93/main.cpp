//
//  main.cpp
//  Repeater
//
//  Created by Ignas Kancleris on 2014-05-03.
//  Copyright (c) 2014 Ignas Kancleris. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct str {
    vector<char> letters;
    vector<int> lengths;
};

string solve(){
    int n;
    cin >> n;
    vector<str> strings;
    strings.resize(n);
    for (int j = 0; j < n; j++) {
        string str;
        cin >> str;
        char last = '\0';
        for (int k = 0; k < str.size(); k++){
            if(str[k] != last){
                strings[j].letters.push_back(str[k]);
                strings[j].lengths.push_back(1);
                last = str[k];
            }else{
                strings[j].lengths[strings[j].lengths.size()-1] += 1;
            }
        }
    }
    int score = 0;
    for (int j = 0; j < strings[0].letters.size(); j++) {
        int mn = 10001;
        int mx = 0;
        for (int k = 0; k < n; k++) {
            if(strings[k].letters.size() != strings[0].letters.size()){
                return "Fegla Won";
            }
            if(strings[k].letters[j] != strings[0].letters[j]){
                return "Fegla Won";
            }
            mn = min(mn, strings[k].lengths[j]);
            mx = max(mx, strings[k].lengths[j]);
        }
        
        int minScore = 10000000;
        for (int k = mn; k <= mx; k++) {
            int curScore = 0;
            for (int l = 0; l < n; l++) {
                curScore += abs(strings[l].lengths[j]-k);
            }
            minScore = min(minScore,curScore);
        }
        score+= minScore;
    }
    
    stringstream ss;
    ss << score;
    return ss.str();
}

int main(int argc, const char * argv[])
{

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}

