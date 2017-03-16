//
//  main.cpp
//  code_jam_q1
//
//  Created by Nolan Miller on 4/12/14.
//  Copyright (c) 2014 Nolan Miller. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <sstream>
#include <climits>
#include <cmath>
#include <queue>

using namespace std;

void print(vector<int>& list){
    for (int i = 0; i<list.size(); i++) {
        cout<<list[i]<<",";
    }
    cout<<endl;
}
void print(vector<char>& list){
    for (int i = 0; i<list.size(); i++) {
        cout<<list[i]<<",";
    }
    cout<<endl;
}
int max_length(vector<string>& set){
    int mlength = 0;
    for (int i = 0; i<set.size(); i++) {
        if (set[i].size()>mlength) {
            mlength = (int)set[i].size();
        }
    }
    return mlength;
}
int max(vector<int>& set){
    int mlength = 0;
    for (int i = 0; i<set.size(); i++) {
        if (set[i]>mlength) {
            mlength = (int)set[i];
        }
    }
    return mlength;
}
int bestScore(vector<string>& set,int place){
    vector<int> runs;
    for (int ind = 0; ind<set.size(); ind++) {
        int x = 0;
        for (int p = 0; p<place; p++) {
            char c = set[ind][x];
            while (set[ind][x] == c) {
                x++;
            }
        }
        char c = set[ind][x];
        int cnt = 0;
        while (set[ind][x] == c) {
            x++;
            cnt++;
        }
        runs.push_back(cnt);
    }
    int ans;
    int min_score = 99999;
    int best_ans = 0;
    for (ans = 1; ans<=max(runs);ans++) {
        int score = 0;
        for (int i= 0; i<runs.size(); i++) {
            score+= abs(runs[i]-ans);
        }
        if (score<min_score) {
            min_score = score;
            best_ans = ans;
        }
    }
    return min_score;
}
int solve(vector<string> set){
    //make sure it is solvable
    vector<char> order;
    char added =0;
    for (int i = 0; i<set[0].size(); i++) {
        if (added != set[0][i]) {
            order.push_back(set[0][i]);
            added= set[0][i];
        }
    }
    for (int i = 0; i<set.size(); i++) {
        int p = 0;
        int flag = false;
        int ii = 0;
        for (p=0; p<order.size(); p++) {
            flag = false;
            while (ii<set[i].size()&&set[i][ii] == order[p]) {
                ii++;
                flag = true;
            }
            if (!flag) {
                return -1;
            }
        }
        if (ii!=set[i].size()) {
            return -1;
        }
    }
    int val = 0;
    for (int i = 0; i<order.size(); i++) {
        val+=bestScore(set, i);
    }
    return val;
}

int main(int argc, const char * argv[])
{
    
    int t;
    cin>>t;
    for (int i = 0; i<t; i++) {
        int n;
        cin>>n;
        vector<string> words;
        for (int x = 0; x<n; x++) {
            string word;
            cin>>word;
            words.push_back(word);
        }
        int ans = solve(words);
        if (ans == -1) {
            cout<<"Case #"<<i+1<<": "<<"Fegla Won";
        }
        else{
            cout<<"Case #"<<i+1<<": "<<ans;
        }
        if(i+1!=t)
            cout<<endl;
    }
    return 0;
}
